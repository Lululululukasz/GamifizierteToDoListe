//
// Created by helen on 12.05.2023.
//

#include "ToDoList.h"
#include <memory>
#include <random>

ToDoList::ToDoList() {
    this->addCategory(Category("General"));
    this->suggestions = {
            Task("Laundry", "Do the laundry"),
            Task("Dishes", "Do the dishes"),
            Task("Garbage", "Take out the garbage"),
            Task("Bathroom", "Clean the bathroom"),
            Task("Flowers", "Water the flowers"),
            Task("Windows", "Clean the windows"),
    };
}

unique_ptr<list<Category>> ToDoList::getCategories() {
    return make_unique<list<Category>>(this->categories);
}

unique_ptr<Category> ToDoList::getCategoryByName(const string &name) {
    for (Category category : categories) {
        if (category.name == name){
            return make_unique<Category>(category);
        }
    }
    return nullptr;
}

unique_ptr<Category> ToDoList::getCategoryByID(const string &id) {
    for (Category category : categories) {
        if (category.getID() == id){
            return make_unique<Category>(category);
        }
    }
    return nullptr;
}

void ToDoList::addCategory(const Category &category) {
    this->categories.emplace_back(category);
}

bool ToDoList::deleteCategory(const string &id) {
    if (0 != this->categories.remove_if([&] (Category c) {return (c.getID() == id);})) {
        return true;
    } else {
        return false;
    }
}

list<Task> ToDoList::showAllTasks() {
    list<Task> allTasks;
    for (Category category : this->categories) {
        allTasks.emplace_back(*(category.getTasks()));
    }
    return allTasks;
}

unique_ptr<Task> ToDoList::getTaskByName(const string &search) {
    for (Task task : *(this->getCategories())) {
        if (task.name == search){
            return make_unique<Task>(task);
        }
    }
    return nullptr;
}

Task ToDoList::suggestTask() {
    int min {0}, max {static_cast<int>(this->suggestions.size()) -1}, cache;
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(min, max);
    cache = distr(eng);

    list<Task>::iterator re {this->suggestions.begin()};

    for (int i {0}; i < cache; ++i, ++re){
    }

    return *re;
}
