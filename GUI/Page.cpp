//
// Created by helen on 30.05.2023.
//

#include "Page.h"
#include <QStyle>

Page::Page(todolib::ToDoList &toDoList)
        : toDoList{toDoList}  {
    closeButton = std::make_shared<QPushButton>();
    closeButton->setIcon(closeButton->style()->standardIcon(QStyle::SP_ArrowBack));
    layout.addWidget(closeButton.get(), 0, Qt::AlignLeft);
    connect(closeButton.get(), SIGNAL(clicked()), this, SIGNAL(closePageSignal()));
    addXpWidget();
}



void Page::addXpWidget(){
    std::shared_ptr<XpWidget> xpWidget = std::make_shared<XpWidget>(xp);
    xpWidgets.push_back(xpWidget);
    layout.addWidget(xpWidget.get(),0,Qt::AlignTop);
   connect(this, &Page::xpWidgetSignal1, xpWidget.get(), &XpWidget::xpWidgetFunc1);
   connect(this, &Page::xpWidgetSignal2, xpWidget.get(), &XpWidget::xpWidgetFunc2);
}
