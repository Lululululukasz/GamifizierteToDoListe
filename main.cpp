#include "todolib/todolib.h"
#include "GUI/ToDoListWindow.h"

#include <QApplication>

#include <QFile>
#include <QDir>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

int main(int argc, char** argv) {

    // Initialisiere eine QApplication-Instanz
    QApplication app(argc, argv);

    todolib::ToDoList todoList;

    ToDoListWindow window {todoList};

    // Starten der QApplication
    return app.exec();

}
