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

    void Categories::assignTaskToCategory( std::shared_ptr<std::string> myTask, std::string category) {
        for (auto &c: this->category)
            if (category == c.first) {
                c.second.emplace_back(move(myTask));
                break;
            }
    }

    // ToDoListAdventure
} // ToDoListAdventure