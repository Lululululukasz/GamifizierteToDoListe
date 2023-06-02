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
    saveToFile();
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
                        }
                    }
                if (checksum == 15) {
                    this->tasks.push_front(Task(task.toObject()));
                }
            }
    }
}

// Copy Constructor
Category::Category(Category &other) {
    this->id = other.getID();
    this->tasks = *make_unique<JsonList<Task>>(other.tasks);
    this->name = other.name;
}

// Copy Assignment Constructor
Category &Category::operator=(Category const &other) {
    this->id = other.getID();
    this->tasks = *make_unique<JsonList<Task>>(other.tasks);
    this->name = other.name;

    return *this;
}

// Move Constructor
Category::Category(Category &&other) noexcept {
    this->id = other.getID();
    this->tasks = *make_unique<JsonList<Task>>(other.tasks);
    this->name = other.name;
}

// Move Assignment Constructor
Category &Category::operator=(Category &&other) noexcept {
    this->id = other.getID();
    this->tasks = *make_unique<JsonList<Task>>(other.tasks);
    this->name = other.name;

    return *this;
}

string Category::getID() const {
    return this->id;
}

bool Category::isSame(const Category &other) const {
    if (this->getID() == other.id) {
        return true;
    } else {
        return false;
    }
}

void Category::addTask(Task &task) {
    tasks.push_front(task);
    saveToFile();
}
void Category::addTask(Task &&task) {
    tasks.push_front(task);
    saveToFile();
}

list<Task> Category::showTasks() {
    cout << name << ": ";
    for (const Task &task: tasks) {
        cout << task.name; // TODO debug
    }
    cout << endl;
}

bool Category::deleteTask(const string &deleteID) {
    if (0 != this->tasks.remove_if([&] (Task t) {return (t.getID() == deleteID);})) {
        saveToFile();
        return true;
    } else {
        saveToFile();
        return false;
    }
}

void Category::saveToFile() {
    //json.writeToFile();
    QJsonObject test2;
    test2.insert("id", id.c_str());
    test2.insert("name", name.c_str());
    test2.insert("tasks", tasks.toJson());
    Json::writeJsonObjectToFile(test2);
}




