//
// Created by trashpanda on 10.05.23.
//

#include <iostream>
#include <algorithm>
#include "Categories.h"

namespace ToDoListAdventure {
    void Categories::newCategory(const std::string &category) {
        // Add new categories to the vector
        this->category.emplace_back(category, NULL);
    }

    void Categories::showAllCategories() {
        std::cout << "Here is a List of all Categories, and their tasks:" << std::endl;
        for (const auto &element: this->category) {
            std::cout << element.first << std::endl; // print name of category
            for (const auto task : element.second) { // print each task in that category
                std::cout << "   - " << *task << std::endl;
            }
        }
    }

    void Categories::deleteCategory(std::string categoryToDelete) {
        erase_if(this->category,[categoryToDelete](auto &a){return categoryToDelete == a.first;});
    }

    void Categories::assignTaskToCategory( std::shared_ptr<std::string> ptrToTask, std::string categoryName) {
        for (auto &c: this->category)
            if (categoryName == c.first) {
                c.second.emplace_back(move(ptrToTask));
                break;
            }
    }


    void Categories::showTasksInCategory(std::string categoryName) {
        for (auto &c: this->category)
            if (categoryName == c.first) {
                std::cout << std::endl << "Here are all the Tasks in the Category \" " << c.first << "\"" << std::endl;
                for (const auto task : c.second) { // print each task in that category
                    std::cout << "   - " << *task << std::endl;
                }
                break;
            }
    }

    // ToDoListAdventure
} // ToDoListAdventure