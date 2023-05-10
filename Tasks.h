#ifndef PIC_AEM_GRUPPE_6_TASKS_H
#define PIC_AEM_GRUPPE_6_TASKS_H
#include <string>
#include <vector>

namespace ToDoListAdventure {

    class Tasks {
        // Define a vector named "task"
        std::vector<std::string> task;
    public:
        Tasks(){}
        void newTask(std::string);
    };

} // ToDoListAdventure

#endif //PIC_AEM_GRUPPE_6_TASKS_H
