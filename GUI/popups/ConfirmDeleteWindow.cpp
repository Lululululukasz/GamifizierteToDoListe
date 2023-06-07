#include "GUI/popups/ConfirmDeleteWindow.h"
#include <QInputDialog>

ConfirmDeleteWindow::ConfirmDeleteWindow() {
    instructions.setText(QString::fromStdString("Are you sure you want to delete this ?"));
    layout.addWidget(&instructions);

    layout.addWidget(&deleteButton);
    deleteButton.setText("Delete");
    connect(&deleteButton, &QPushButton::clicked, this, &ConfirmDeleteWindow::deleteButtonClicked);

    cancelButton.setText("Cancel");
    layout.addWidget(&cancelButton);
    connect(&cancelButton, &QPushButton::clicked, this, [&, this]() {this-> hide();});
    show();
}

void ConfirmDeleteWindow::deleteButtonClicked(){
    emit confirmDelete();
    this->close();
}