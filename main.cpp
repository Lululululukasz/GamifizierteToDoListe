#include <iostream>
#include "todolib\todolib.h"
#include "GUI/AddTaskBox.h"
#include "GUI/TaskWidget.h"
#include "todolib/todolib.h"
#include "GUI/ToDoListWindow.h"

#include <QApplication>
#include <QWidget>


int main(int argc, char** argv) {


    // Initialisiere eine QApplication-Instanz
    QApplication app(argc, argv);

    todolib::ToDoList todoList;

    ToDoListWindow window {todoList};

    /*
    QApplication app(argc, argv);

    Window window;
    window.show();
    */

    // Starten der QApplication
    return app.exec();

}
