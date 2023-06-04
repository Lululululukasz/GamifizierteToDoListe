//
// Created by helen on 12.05.2023.
//

#include "Task.h"
#include <time.h>
#include <iostream>

using namespace std;
using namespace todolib;

Task::Task(const string &n, const string &d) {
    this->id = n + to_string((int) time(nullptr));
    this->name = n;
    this->description = d;
    this->done = false;
    this->priority = medium;
}

/**
 * Constructor to create a task with a QjsonObject
 * @param QJsonObject taskObject
 */
Task::Task(const QJsonObject &taskObject) {
    id = taskObject.value(QString("id")).toString().toStdString();
    name = taskObject.value(QString("name")).toString().toStdString();
    description = taskObject.value(QString("description")).toString().toStdString();
    done = taskObject.value(QString("done")).toString().toStdString() == "true";
    priority = static_cast<priority_t>(taskObject.value(QString("priority")).toInt());
}

string Task::getID() {
    return this->id;
}

bool Task::isSame(const Task &other) {
    if (this->getID() == other.id) {
        return true;
    } else {
        return false;
    }
}

bool Task::getDoneStatus() const {
    return this->done;
}

void Task::setAsDone() {
    this->done = true;

}

void Task::setAsUndone() {
    this->done = false;
}

void Task::setPriority(Task::priority_t prio) {
    this->priority = prio;
}

Task::priority_t Task::getPriority() {
    return this->priority;
}

std::string Task::getPriorityString() {
    switch(priority) {
        case trivial:
            return "trivial";
        case low:
            return "low";
        case medium:
            return "medium";
        case high:
            return "high";
        case urgent:
            return "urgent";

    }
}

/**
 * Function to convert the task with it's attributes to a QJsonObject
 * @return QJsonObject
 */
QJsonObject Task::toJson() {
    QJsonObject jsonObject;
    jsonObject.insert("id", id.c_str());
    jsonObject.insert("name", name.c_str());
    jsonObject.insert("description", description.c_str());
    jsonObject.insert("done", done?"true":"false");
    jsonObject.insert("priority", static_cast<int>(priority));
    return jsonObject;
}



