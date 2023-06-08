//
// Created by helen on 12.05.2023.
//

#include "Category.h"
#include <memory>
#include <iostream>

using namespace std;
using namespace todolib;

// Constructor
Category::Category(const string &n) {
    this->id = n + to_string((int) time(nullptr));
    this->name = n;
    saveToJson();
}

/**
 * Constructor for the Savefiles
 * @param jsonObject
 */
Category::Category(const QJsonObject &jsonObject) {
    id = jsonObject.value(QString("id")).toString().toStdString();
    name = jsonObject.value(QString("name")).toString().toStdString();
    QJsonArray tasks = jsonObject.value("tasks").toArray();

    foreach(QJsonValue task, tasks){
            if (task.isObject()){
                QJsonObject taskObject = task.toObject();
                QStringList keys = taskObject.keys();

                // Check if the QJsonObject is convertable to a task
                int checksum = 0;
                        foreach(QString key, keys) {
                        if (key == "id") {
                            checksum += 1;
                        } else if (key == "name") {
                            checksum += 2;
                        } else if (key == "description") {
                            checksum += 4;
                        } else if (key == "done") {
                            checksum += 8;
                        } else if (key == "priorityFilter"){
                            checksum += 16;
                        } else if (key == "durationFilter"){
                           checksum += 32 ;
                        } else if (key == "dueYear"){
                            checksum += 64;
                        } else if (key == "dueMonth"){
                            checksum += 128;
                        } else if (key == "dueDay"){
                            checksum += 256;
                        } else if (key == "picture"){
                            checksum += 512;
                        }
                    }
                if (checksum == 1023) {
                    auto taskObj {Task(task.toObject())};
                    taskObj.setCategory(this);
                    this->tasks.push_back(std::move(taskObj));
                }
            }
    }
}

bool Category::isSame(const Category &other) const {
    if (this->getID() == other.id) {
        return true;
    } else {
        return false;
    }
}

void Category::addTask(Task &task) {
    tasks.push_back(task);
    task.setCategory(this);
    saveToJson();
}
void Category::addTask(Task &&task) {
    tasks.push_back(task);
    saveToJson();
}

/*
list<Task> Category::showTasks() {
    cout << name << ": ";
    for (const Task &task: tasks) {
        cout << task.name; // TODO debug
    }
    cout << endl;
}
 */

bool Category::deleteTask(const string &deleteID) {
    if (0 != this->tasks.remove_if([&] (Task t) {return (t.getID() == deleteID);})) {
        saveToJson();
        return true;
    } else {
        saveToJson();
        return false;
    }
}

/**
 * Function to convert the category-attributes to a QJsonObject and writes it to a .jsonfile
 */
void Category::saveToJson() {
    QJsonObject jsonObject;
    jsonObject.insert("id", id.c_str());
    jsonObject.insert("name", name.c_str());
    jsonObject.insert("tasks", tasks.toJson());
    Json::writeJsonObjectToFile(jsonObject, "categories/");
}

/**
 * getter and setter
 */

string Category::getID() const {
    return this->id;
}

void Category::setName(std::string &&newName) {
    name = newName;
    saveToJson();
}

std::string Category::getName() {
    return name;
}
