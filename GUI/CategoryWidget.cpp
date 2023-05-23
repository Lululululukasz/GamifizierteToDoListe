//
// Created by Jan Ole Weighardt on 23.05.23.
//

#include "GUI/CategoryWidget.h"
#include "todolib/todolib.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QInputDialog>
#include <QWidget>

CategoryWidget::CategoryWidget(todolib::Category &category, QWidget *parent) : category{category},
                                                                               QWidget(parent) {

    name.setText(QString::fromStdString(category.name));
    hlayout.addWidget(&name, 0, Qt::AlignLeft | Qt::AlignCenter);

    deleteButton.setText("Delete");
    hlayout.addWidget(&deleteButton, 1, Qt::AlignLeft | Qt::AlignCenter);
    // connect(&deleteButton, &QPushButton::clicked, this, [&]() { deleteCategory(); });

    setLayout(&hlayout);
    setLayout(&vlayout);

}

