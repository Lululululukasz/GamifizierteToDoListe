//
// Created by helen on 12.05.2023.
//

#include "Category.h"
#include <memory>

using namespace std;

// Constructor
Category::Category(const string &n) {
    this->id = n + to_string((int) time(nullptr));
    this->name = n;
}

// Copy Constructor
Category::Category(Category &other) {
    this->id = other.getID();
    this->tasks = *other.getTasks();
    this->name = other.name;
}

// Copy Assignment Constructor
Category &Category::operator=(Category &other) {
    this->id = other.getID();
    this->tasks = *other.getTasks();
    this->name = other.name;
}

const string Category::getID() {
    return this->id;
}

bool Category::isSame(const Category &other) {
    if (this->getID() == other.id) {
        return true;
    } else {
        return false;
    }
}

unique_ptr<list<Task>> Category::getTasks() {
    return make_unique<list<Task>>(this->tasks);
}

void Category::addTask(Task task) {
    this->tasks.emplace_front(task);
}

bool Category::deleteTask(const string &id) {
    if (0 != this->tasks.remove_if([&] (Task t) {return (t.getID() == id);})) {
        return true;
    } else {
        return false;
    }
}






