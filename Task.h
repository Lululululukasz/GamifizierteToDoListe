
//
// Created by Jan Ole Weighardt on 10.05.23.
//

#ifndef PICGROUG6DEVELOUPMENT_TASK_H
#define PICGROUG6DEVELOUPMENT_TASK_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

namespace ToDoListAdventure {

    class Tasks {
        // Define a vector named "task"
        std::vector<std::string> task;
        std::vector<std::string> defaultTask {"Abwaschen", "Wäsche waschen", "Müll rausbringen", "Bad putzen", "Blumen gießen", "Fenster putzen", "Bett machen", "staubsaugen"};
    public:
        Tasks() = default;
        void newTask(std::string const &task);
        std::shared_ptr<std::string> searchTask(std::string const &searchIn);
        std::shared_ptr<std::string> searchTask();
        void showTask();
        void deleteTask();
        std::string suggestTask();
    };

} // ToDoListAdventure



#endif //PICGROUG6DEVELOUPMENT_TASK_H
