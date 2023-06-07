//
// Created by helen on 12.05.2023.
//

#include "ToDoList.h"
#include <random>
#include <iostream>

using namespace todolib;

ToDoList::ToDoList() {
    QJsonArray categories = Json::getAllSaves();
    // if there is no json savefile create a new category
    if (categories.isEmpty()) {
        this->addCategory(Category("General"));
    } else {
        foreach(QJsonValue category, categories){
                if (category.isObject()) {
                    QJsonObject categoryObject = category.toObject();

                    // Check if the QJsonObject is convertable to a category
                    QStringList keys = categoryObject.keys();
                    int checksum = 0;
                            foreach(QString key, keys) {
                            if (key == "id") {
                                checksum += 1;
                            } else if (key == "name") {
                                checksum += 2;
                            } else if (key == "tasks") {
                                checksum += 4;
                            }
                        }
                    if (checksum == 7) {
                        this->addCategory(Category(categoryObject));
                    }
                }
        }
    }
    this->generalTasks = { // if these get changed, the achievements also have to be altered! (AchievementList.cpp)
            // Household chores
            Task("Laundry", "Do the laundry"),
            Task("Dishes", "Do the dishes"),
            Task("Garbage", "Take out the garbage"),
            Task("Bathroom", "Clean the bathroom"),
            Task("Flowers", "Water the flowers"),
            Task("Windows", "Clean the windows"),

            // University
            Task("Lecture", "Go to a lecture"),
            Task("Study", "study for your courses"),
            Task("Semester", "finish your first semester at university"),
            Task("Quit", "quit university"),
            Task("Exams", "go to all of your exams"),
    };

}

shared_ptr<Category> ToDoList::getCategoryByName(const string &name) {
    for (Category &category: categories) {
        if (category.name == name) {
            return make_shared<Category>(category);
        }
    }
    return static_cast<shared_ptr<Category>>(nullptr);
}

Category &ToDoList::getCategoryByID(const string &id) {
    for (Category &category: categories) {
        if (category.getID() == id) {
            return category;
        }
    }
}

void ToDoList::addCategory(Category &&category) {
    this->categories.emplace_back(category);
}

void ToDoList::addCategory(Category &category) {
    this->categories.emplace_back(category);
}

bool ToDoList::deleteCategory(const string &id) {
    if (0 != this->categories.remove_if([&](const Category &c) { if (c.getID() == id) {
        Json::deleteJson((c.getID()+".json").c_str());
        return true;
    }return false;
    })) {
        return true;
    } else {
        return false;
    }
}

list<Task> ToDoList::showAllTasks() {
    list<Task> allTasks;
    for (const Category &category: this->categories) {
        cout << category.name << ": "; // TODO debug
        for (const Task &task: category.tasks) {
            allTasks.push_back(task);
            cout << task.name; // TODO debug
        }
    }
    cout << endl;
    return allTasks;
}

std::shared_ptr<Task> ToDoList::getTaskByName(const string &search) {
    for (Category &category: this->categories) {
        for (Task &task: category.tasks) {
            if (task.name == search) {
                return std::make_shared<Task>(task);
            }
        }
    }
    return nullptr;
}

Task ToDoList::suggestTask() {
    int min{0}, max{static_cast<int>(this->generalTasks.size()) - 1}, cache;
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(min, max);
    cache = distr(eng);

    list<Task>::iterator re{this->generalTasks.begin()};

    for (int i{0}; i < cache; ++i, ++re) {
    }

    return *re;
}
