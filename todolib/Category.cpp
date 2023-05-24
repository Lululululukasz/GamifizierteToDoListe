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
}

// Copy Constructor
Category::Category(Category &other) {
    this->id = other.getID();
    this->tasks = *make_unique<list<Task>>(other.tasks);
    this->name = other.name;
}

// Copy Assignment Constructor
Category &Category::operator=(Category const &other) {
    this->id = other.getID();
    this->tasks = *make_unique<list<Task>>(other.tasks);
    this->name = other.name;

    return *this;
}

// Move Constructor
Category::Category(Category &&other) noexcept {
    this->id = other.getID();
    this->tasks = *make_unique<list<Task>>(other.tasks);
    this->name = other.name;
}

// Move Assignment Constructor
Category &Category::operator=(Category &&other) noexcept {
    this->id = other.getID();
    this->tasks = *make_unique<list<Task>>(other.tasks);
    this->name = other.name;

    return *this;
}

string Category::getID() const {
    return this->id;
}

bool Category::isSame(const Category &other) {
    if (this->getID() == other.id) {
        return true;
    } else {
        return false;
    }
}

void Category::addTask(Task &task) {
    tasks.push_front(task);
}
void Category::addTask(Task &&task) {
    tasks.push_front(task);
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
        return true;
    } else {
        return false;
    }
}






