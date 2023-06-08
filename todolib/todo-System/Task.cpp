//
// Created by helen on 12.05.2023.
//

#include "Task.h"
#include <time.h>
#include <iostream>
#include <utility>

using namespace std;
using namespace todolib;

Task::Task(const string &n, const string &d) {
    this->id = n + to_string((int) time(nullptr));
    this->name = n;
    this->description = d;
    this->done = false;
    this->priority = medium;
    this->duration = 1;
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
    priority = static_cast<priority_t>(taskObject.value(QString("priorityFilter")).toInt());
    duration = taskObject.value(QString("durationFilter")).toDouble();
    dueDate = std::chrono::year_month_day(
            std::chrono::year(taskObject.value(QString("dueYear")).toInt()),
            std::chrono::month(taskObject.value(QString("dueMonth")).toInt()),
            std::chrono::day(taskObject.value(QString("dueDay")).toInt())
            );
    picture = taskObject.value(QString("picture")).toString().toStdString();
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

std::string Task::getPriorityString(Task::priority_t prio) {
    switch(prio) {
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
    return "";
}

void Task::setDuration(double dur) {
    this->duration = dur;
}
double Task::getDuration() const{
    return this->duration;
}

void Task::setdueDate(std::chrono::year_month_day due) {
    this->dueDate = due;
}

std::chrono::year_month_day Task::getdueDate() {
    return this->dueDate;
}

void Task::setPicture(std::string pic) {
    this->picture = pic;
}

std::string Task::getPicture() {
    return this->picture;
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
    jsonObject.insert("priorityFilter", static_cast<int>(priority));
    jsonObject.insert("durationFilter", duration);
    jsonObject.insert("dueYear", static_cast<int>(dueDate.year()));
    jsonObject.insert("dueMonth", static_cast<int>(static_cast<unsigned>(dueDate.month())));
    jsonObject.insert("dueDay", static_cast<int>(static_cast<unsigned>(dueDate.day())));
    jsonObject.insert("picture", picture.c_str());
    return jsonObject;
}









