//
// Created by helen on 30.05.2023.
//

#ifndef PIC_AEM_PROJEKT_PAGE_H
#define PIC_AEM_PROJEKT_PAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include "todolib/todolib.h"
#include "PageLayoutWidget.h"
#include <QPushButton>
#include <memory>
#include <QStackedLayout>

/**
 * Page
 * parent class for pages including a closeSignal, a layout and a back button
 */
class Page : public QWidget {

Q_OBJECT

public:
    explicit Page(todolib::ToDoList(& toDoList));
    void setOverlay(std::shared_ptr<QWidget> _overlay);

signals:
    void closePageSignal();
    void refreshPageSignal();

protected:
    todolib::ToDoList& toDoList;
    std::shared_ptr<QVBoxLayout> layout {std::make_shared<QVBoxLayout>()};
    std::shared_ptr<QPushButton> closeButton;

private:
    PageLayoutWidget layoutWidget {PageLayoutWidget(layout)};
    QStackedLayout stackedLayout {QStackedLayout(this)};
    std::shared_ptr<QWidget> overlay;
};


#endif //PIC_AEM_PROJEKT_PAGE_H
