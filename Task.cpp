//
// Created by Jan Ole Weighardt on 10.05.23.
//

#include "Task.h"
#include "iostream"
using namespace std;

namespace ToDoListAdventure {
    void Tasks::newTask(std::string task) {
        // Add new tasks to the vector
        this->task.emplace_back(task);
    };

    void Tasks::showTask() {
        for (const auto &element: task) {
            cout << element << endl << endl;
        }
    } // ToDoListAdventure
}

