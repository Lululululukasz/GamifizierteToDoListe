
#include "Task.h"

using namespace ToDoListAdventure;

int main() {
    Tasks tasks = Tasks();
    tasks.newTask("test");
    tasks.newTask("Dishes");
    tasks.showTask();
    tasks.deleteTask();
    return 0;
}




