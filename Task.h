//
// Created by Jan Ole Weighardt on 10.05.23.
//

#ifndef PICGROUG6DEVELOUPMENT_TASK_H
#define PICGROUG6DEVELOUPMENT_TASK_H
#include <string>
#include <vector>
#include <memory>

namespace ToDoListAdventure {

    class Tasks {
        // Define a vector named "task"
        std::vector<std::string> task;
    public:
        Tasks() = default;
        void newTask(std::string const &task);
        void showTask();
        void deleteTask(std::string taskToDelete);

        std::shared_ptr<std::string> findTask(std::string);
    };

} // ToDoListAdventure



#endif //PICGROUG6DEVELOUPMENT_TASK_H
