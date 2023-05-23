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

    setLayout(&vlayout);
    vlayout.addLayout(&hlayout);

    name.setText(QString::fromStdString(category.name));
    hlayout.addWidget(&name, 1, Qt::AlignLeft | Qt::AlignVCenter);

    deleteButton.setText("Delete");
    hlayout.addWidget(&deleteButton, 0, Qt::AlignRight | Qt::AlignVCenter);
    connect(&deleteButton, &QPushButton::clicked, this, [&]() { deleteCategory(); });

}

void CategoryWidget::deleteCategory() {
    emit categoryDeleteSignal();
}

