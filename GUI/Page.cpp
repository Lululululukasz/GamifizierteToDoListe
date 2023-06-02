//
// Created by helen on 30.05.2023.
//

#include "Page.h"
#include <QStyle>

Page::Page(todolib::ToDoList &toDoList) : toDoList{toDoList} {
    closeButton = std::make_shared<QPushButton>();
    closeButton->setIcon(closeButton->style()->standardIcon(QStyle::SP_ArrowBack));
    layout.addWidget(closeButton.get(), 0, Qt::AlignLeft);
    connect(closeButton.get(), SIGNAL(clicked()), this, SIGNAL(closePageSignal()));

}
