//
// Created by Jan Ole Weighardt on 10.05.23.
//

#include "Task.h"
#include "iostream"
#include <random>
using namespace std;

namespace ToDoListAdventure {
    void Tasks::newTask(std::string const &task) {
        // Add new tasks to the vector
        this->task.emplace_back(task);
    }

    void Tasks::showTask() {
        for (const auto &element: task) {
            cout << element << endl << endl;
        }
    }

    shared_ptr<string> Tasks::searchTask() {
        std::string input;
        std::cout << "Enter task name: ";
        std::cin >> input;
        return searchTask(input);
    }

    shared_ptr<string> Tasks::searchTask(std::string const &searchIn) { // TODO: Optimierung Levenshtein Algorithmus
        auto it = std::find(task.begin(), task.end(), searchIn);
        if (it != task.end()) {
            std::cout << "Task: " << *it << std::endl;
            return std::make_shared<string>( *it);
        } else {
            std::cout << "A task with this name doesn't exist" << std::endl;
            return nullptr;
        }
    }

    void Tasks::deleteTask() {
            string taskToDelete;
            std::cout << "Enter the task you wish to remove: ";
            std::cin >> taskToDelete;

            auto it = std::find(task.begin(), task.end(), taskToDelete);
            if (it != task.end()) {
                task.erase(it);
                std::cout << "Task removed!" << std::endl;
            } else {
                std::cout << "A task with this name doesn't exist" << std::endl;
            }
    }

    void Tasks::addSuggested(std::string const &task) {
        char yn;
        std::cout << "Do you want to add this task? y for yes, n for no: ";
        std::cin >> yn;
        if(yn == 'y'){
            this->task.emplace_back(task);
            std::cout << "Added Task: " << task << std::endl;
        }else if(yn == 'n'){
            std::cout << "Did not add Task: " << task << std::endl;
        }else{
            std::cout << "invalid input" << std::endl;
        }
    }

   string Tasks::suggestTask(){
        int min {0}, max {static_cast<int>(defaultTask.size()) -1}, cache;
       std::random_device rd;
       std::default_random_engine eng(rd());
       uniform_int_distribution<int> distr(min, max);
       cache = distr(eng);

       std::cout << "How about: " << defaultTask[cache] << "?" << std::endl;

       return defaultTask[cache];
    }
    // ToDoListAdventure
}

