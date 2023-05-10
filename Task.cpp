//
// Created by Jan Ole Weighardt on 10.05.23.
//

#include "Task.h"
#include "iostream"
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
    // taskToDelete braucht einen cin zum überprüfen
    void Tasks::deleteTask(std::string taskToDelete){
        erase_if(this->task,[taskToDelete](auto a){return taskToDelete == a;});
    }

    shared_ptr<string> Tasks::findTask(std::string taskName) {
        for (auto t : this->task) {
            if (taskName == t) {
                return std::make_shared<string>(t);
            }
        }
        return nullptr;
    }


    // ToDoListAdventure
}

