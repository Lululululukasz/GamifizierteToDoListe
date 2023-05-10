#include <iostream>
#include "Tasks.h"

using namespace ToDoListAdventure;

int main() {
    Tasks tasks = Tasks();
    tasks.newTask("test");

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
