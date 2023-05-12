//
// Created by helen on 12.05.2023.
//

#include "Task.h"
#include <time.h>


using namespace std;


Task::Task(string n, string d) {
    this->id = n + to_string((int)time(NULL));
    this->name = n;
    this->description = d;
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