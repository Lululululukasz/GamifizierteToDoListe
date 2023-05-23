//
// Created by Jan Ole Weighardt on 23.05.23.
//

#ifndef AEMPROJEKT_CATEGORYWIDGET_H
#define AEMPROJEKT_CATEGORYWIDGET_H

#include "todolib/todolib.h"
#include "ToDoListWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QApplication>
#include <QPushButton>
#include <QInputDialog>
#include <QWidget>
#include <QPushButton>


class CategoryWidget : public QWidget {

Q_OBJECT


public:
    explicit CategoryWidget(todolib::Category &category, QWidget *parent = nullptr);

    todolib::Category& category;

private:
    //ToDoListWindow *parent;
    QVBoxLayout vlayout{QVBoxLayout(this)};
    QHBoxLayout hlayout{QHBoxLayout(this)};
    QLabel name {QLabel()};
    QPushButton deleteButton {QPushButton()};

    void deleteCategory();
};

#endif //AEMPROJEKT_CATEGORYWIDGET_H
