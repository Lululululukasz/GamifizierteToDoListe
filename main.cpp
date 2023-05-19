#include <iostream>
#include "Task.h"
#include "Categories.h"
#include "GUI/TaskWidget.h"

#include <QApplication>
#include <QWidget>

using namespace ToDoListAdventure;

int main(int argc, char** argv) {
    /*
    Tasks tasks = Tasks();
    tasks.newTask("test");
    tasks.newTask("Dishes");
    tasks.showTask();
    tasks.addSuggested(tasks.suggestTask());
    tasks.searchTask();
    tasks.deleteTask();


    tasks.newTask("buy apples");
    tasks.newTask("buy oranges");
    tasks.newTask("watch c++ video");

    Categories categories = Categories();
    categories.newCategory("shopping");
    categories.newCategory("studying");
    categories.assignTaskToCategory(tasks.searchTask("buy apples"), "shopping");
    categories.assignTaskToCategory(tasks.searchTask("buy oranges"), "shopping");
    categories.assignTaskToCategory(tasks.searchTask("watch c++ video"), "studying");
    categories.showAllCategories();

    categories.showTasksInCategory("shopping");
    */

    // Initialisiere eine QApplication-Instanz
    QApplication app(argc, argv);

    TaskWidget window;

    window.resize(250, 150);
    window.setWindowTitle("to do list");
    window.show();

    // Starten der QApplication
    return app.exec();
}




