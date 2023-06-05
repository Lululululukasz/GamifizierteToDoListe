//
// Created by helen on 30.05.2023.
//

#ifndef PIC_AEM_PROJEKT_PAGE_H
#define PIC_AEM_PROJEKT_PAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "todolib/todolib.h"
#include "GUI/PageLayoutWidget.h"
#include <QPushButton>
#include <memory>
#include <QStackedLayout>

/**
 * Page
 * parent class for pages including a closeSignal, a vOuterLayout and a back button
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
    PageLayoutWidget layoutWidget {PageLayoutWidget()};
    std::shared_ptr<QPushButton> closeButton {std::make_shared<QPushButton>()};

private:
    QStackedLayout stackedLayout {QStackedLayout(this)};
    std::shared_ptr<QWidget> overlay;
};


#endif //PIC_AEM_PROJEKT_PAGE_H
