//
// Created by helen on 23.05.2023.
//

#ifndef PIC_AEM_PROJEKT_TODOLISTWIDGET_H
#define PIC_AEM_PROJEKT_TODOLISTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QInputDialog>
#include <QLabel>
#include "TaskWidget.h"
#include "todolib/ToDoList.h"
#include "CategoryWidget.h"


class ToDoListWindow : public QWidget {

Q_OBJECT

public:
    explicit ToDoListWindow();

private:
    todolib::ToDoList toDoList;
    QPushButton* addCategoryButton;
    QVBoxLayout layout {QVBoxLayout(this)};
    QList<QStringList> categoryWidgets;
    void addCategory();
};


#endif //PIC_AEM_PROJEKT_TODOLISTWIDGET_H