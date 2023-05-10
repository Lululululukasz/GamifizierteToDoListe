//
// Created by Jan Ole Weighardt on 10.05.23.
//

#ifndef PICGROUG6DEVELOUPMENT_TASK_H
#define PICGROUG6DEVELOUPMENT_TASK_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace ToDoListAdventure {

    class Tasks {
        // Define a vector named "task"
        std::vector<std::string> task;
    public:
        Tasks() = default;
        void newTask(std::string const &task);
        void showTask();
        void deleteTask();
    };

} // ToDoListAdventure



#endif //PICGROUG6DEVELOUPMENT_TASK_H
