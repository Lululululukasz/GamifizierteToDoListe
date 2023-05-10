#include <iostream>
#include "Task.h"

using namespace ToDoListAdventure;

int main() {
    Tasks tasks = Tasks();
    tasks.newTask("test");
    tasks.showTask();
    return 0;
}




