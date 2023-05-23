#include <iostream>
#include "GUI/TaskWidget.h"
#include "todolib/todolib.h"
#include "GUI/ToDoListWindow.h"

#include <QApplication>
#include <QWidget>


int main(int argc, char** argv) {

    // Initialisiere eine QApplication-Instanz
    QApplication app(argc, argv);

    ToDoListWindow window {};

    // Starten der QApplication
    return app.exec();
}




