#include "ConfirmDeleteWindow.h"
#include <QInputDialog>


ConfirmDeleteWindow::ConfirmDeleteWindow() {
    instructions.setText(QString::fromStdString("Are you sure you want to delete this Task?"));
    layout.addWidget(&instructions);

    layout.addWidget(&deleteButton);
    connect(&deleteButton, &QPushButton::clicked, this, &ConfirmDeleteWindow::confirmInput);

    layout.addWidget(&cancelButton);
    connect(&cancelButton, &QPushButton::clicked, this, [&]() {this-> hide();});
    show();

}
void ConfirmDeleteWindow::catchDeleteTask() {
    ConfirmDeleteWindow();
}

void ConfirmDeleteWindow::confirmInput() {
        emit confirmDelete();
}