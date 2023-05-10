//
// Created by Jan Ole Weighardt on 10.05.23.
//

#ifndef PICGROUG6DEVELOUPMENT_TASK_H
#define PICGROUG6DEVELOUPMENT_TASK_H
#include <string>
#include <vector>

namespace ToDoListAdventure {

    class Tasks {
        // Define a vector named "task"
        std::vector<std::string> task;
    public:
        Tasks(){}
        void newTask(std::string);
        void showTask();
    };

} // ToDoListAdventure



#endif //PICGROUG6DEVELOUPMENT_TASK_H
