#include "Tasks.h"

namespace ToDoListAdventure {
    void Tasks::newTask(std::string task) {
        // Add new tasks to the vector
        this->task.emplace_back(task);
    };
} // ToDoListAdventure