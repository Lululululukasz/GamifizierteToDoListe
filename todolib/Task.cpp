//
// Created by helen on 12.05.2023.
//

#include "Task.h"
#include <time.h>


using namespace std;
using namespace todolib;

Task::Task(const string &n, const string &d) {
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

bool Task::getDoneStatus() const {
    return this->done;
}

void Task::setAsDone() {
    this->done = true;

}

void Task::setAsUndone() {
    this->done = false;
}
