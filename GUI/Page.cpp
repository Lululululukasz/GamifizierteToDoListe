//
// Created by helen on 30.05.2023.
//

#include "Page.h"

Page::Page(todolib::ToDoList &toDoList) : toDoList{toDoList} {
    layout.addWidget(&closeButton, 0, Qt::AlignLeft);
    connect(&closeButton, SIGNAL(clicked()), this, SIGNAL(closePageSignal()));

}
