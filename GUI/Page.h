//
// Created by helen on 30.05.2023.
//

#ifndef PIC_AEM_PROJEKT_PAGE_H
#define PIC_AEM_PROJEKT_PAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include "todolib/todolib.h"
#include <QPushButton>

/**
 * Page
 * parent class for pages including a closeSignal, a layout and a back button
 */
class Page : public QWidget {

Q_OBJECT

public:
    explicit Page(todolib::ToDoList(& toDoList));

signals:
    void closePageSignal();
    void refreshPageSignal();

protected:
    todolib::ToDoList& toDoList;
    QVBoxLayout layout {QVBoxLayout(this)};
    QPushButton closeButton {QPushButton("<- Back")};

};


#endif //PIC_AEM_PROJEKT_PAGE_H
