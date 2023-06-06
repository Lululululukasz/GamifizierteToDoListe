//
// Created by helen on 30.05.2023.
//

#ifndef PIC_AEM_PROJEKT_PAGE_H
#define PIC_AEM_PROJEKT_PAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include "todolib/todolib.h"
#include <QPushButton>
#include <memory>
#include "XpWidget.h"
//#include "CategoryViewPage.h"
#include <QMetaMethod>


/**
 * Page
 * parent class for pages including a closeSignal, a layout and a back button
 */
class Page : public QWidget {

Q_OBJECT

public:
    explicit Page(todolib::ToDoList(& toDoList));
    todolib::ToDoList& toDoList;
    void addXpWidget();
signals:
    void closePageSignal();
    void refreshPageSignal();
    void xpWidgetSignal1();
    void xpWidgetSignal2();
private:
   std::list<std::shared_ptr<XpWidget>> xpWidgets;
   todolib::Xp xp;
protected:

    QVBoxLayout layout {QVBoxLayout(this)};
    std::shared_ptr<QPushButton> closeButton;
};


#endif //PIC_AEM_PROJEKT_PAGE_H
