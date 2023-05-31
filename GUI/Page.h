//
// Created by helen on 30.05.2023.
//

#ifndef PIC_AEM_PROJEKT_PAGE_H
#define PIC_AEM_PROJEKT_PAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include "todolib/todolib.h"
#include <QPushButton>

class Page : public QWidget {

Q_OBJECT

public:
    explicit Page(todolib::ToDoList(& toDoList));

signals:
    void closePageSignal();

protected:
    todolib::ToDoList& toDoList;
    QVBoxLayout layout {QVBoxLayout(this)};
    QPushButton closeButton {QPushButton("<- Back")};

};


#endif //PIC_AEM_PROJEKT_PAGE_H
