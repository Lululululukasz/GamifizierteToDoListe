#include "todolib/todolib.h"
#include "GUI/ToDoListWindow.h"
#include "todolib/AchievementList.h"

#include <QApplication>


int main(int argc, char** argv) {

    // Initialisiere eine QApplication-Instanz
    QApplication app(argc, argv);

    todolib::ToDoList todoList;
    todolib::AchievementList achievementList;

    ToDoListWindow window {todoList};

    // Starten der QApplication
    return app.exec();

}
