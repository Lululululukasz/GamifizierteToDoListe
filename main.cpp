#include <iostream>
#include "todolib\todolib.h"
#include "Window.h"

#include <QApplication>
#include <QWidget>


int main(int argc, char **argv) {

    using namespace std;
    using namespace todolib;

    // Backend Tests start
    /*

    ToDoList mainList = ToDoList();

    cout << "getCategoryByName: " << mainList.getCategoryByName("General").name << endl;
    mainList.getCategoryByName("General").addTask(Task("Test", ""));
    mainList.getCategoryByName("General").addTask(Task("Dishes", ""));

    mainList.showAllTasks();

    cout << "Suggested Task: " << mainList.suggestTask().name << endl;

    cout << "searched Task \"Test\": " << mainList.getTaskByName("Test").name << endl;
    mainList.getCategoryByName("General").deleteTask(mainList.getTaskByName("Test").getID());

    mainList.showAllTasks();*/

    // Backend tests end

    // Initialisiere eine QApplication-Instanz
    QApplication app(argc, argv);
    Window window; // lege ein Fenster an
    window.show();  // ... und zeige es.
    // Starten der QApplication
    return app.exec();

}