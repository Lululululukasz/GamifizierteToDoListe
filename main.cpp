#include <iostream>
#include "Task.h"
#include "Categories.h"

using namespace ToDoListAdventure;

int main() {
    Tasks tasks = Tasks();
    tasks.newTask("buy apples");
    tasks.newTask("buy oranges");
    tasks.newTask("watch c++ video");
    tasks.showTask();

    Categories categories = Categories();
    categories.newCategory("shopping");
    categories.newCategory("studying");
    categories.assignTaskToCategory(tasks.findTask("buy apples"), "shopping");
    categories.assignTaskToCategory(tasks.findTask("buy oranges"), "shopping");
    categories.assignTaskToCategory(tasks.findTask("watch c++ video"), "studying");
    categories.showAllCategories();

    return 0;
}




