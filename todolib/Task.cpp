//
// Created by helen on 12.05.2023.
//

#include "Task.h"
#include <time.h>


using namespace std;
using namespace todolib;

Task::Task(const string &n, const string &d) : category{nullptr} {
    this->id = n + to_string((int) time(nullptr));
    this->name = n;
    this->description = d;
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

bool Task::getDoneStatus() {
    return this->done;
}

void Task::setAsDone() {
    this->done = true;
}

void Task::setAsUndone() {
    this->done = false;
}

shared_ptr<Category> Task::getCategory() {
    return category;
}

void Task::setCategory(shared_ptr<Category> category) {
    this->category = category;
}
