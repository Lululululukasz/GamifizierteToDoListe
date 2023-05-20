#include <iostream>
#include "GUI/TaskWidget.h"
#include "todolib/todolib.h"

#include <QApplication>
#include <QWidget>


int main(int argc, char** argv) {

    // Initialisiere eine QApplication-Instanz
    QApplication app(argc, argv);

    TaskWidget window;

    window.resize(250, 150);
    window.setWindowTitle("to do list");
    window.show();

    // Starten der QApplication
    return app.exec();
}




