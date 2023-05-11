
#include "Task.h"

using namespace ToDoListAdventure;

int main() {
    Tasks tasks = Tasks();
    tasks.newTask("test");
    tasks.newTask("Dishes");
    tasks.showTask();
    std::cout << tasks.suggestTask() << std::endl;
    tasks.searchTask();
    tasks.deleteTask();

    return 0;
}




