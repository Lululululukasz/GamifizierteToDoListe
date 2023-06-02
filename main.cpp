#include "todolib/todolib.h"
#include "GUI/MainWindow.h"

#include <QApplication>

int main(int argc, char **argv) {

    // Initialisiere eine QApplication-Instanz
    QApplication app(argc, argv);

    todolib::ToDoList todoList = todolib::ToDoList();


    MainWindow window{todoList};

    /*
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app (argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
*/


    // Starten der QApplication
    return app.exec();

}
