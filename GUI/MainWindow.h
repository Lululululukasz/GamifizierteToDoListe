//
// Created by helen on 26.05.2023.
//

#ifndef PIC_AEM_PROJEKT_MAINWINDOW_H
#define PIC_AEM_PROJEKT_MAINWINDOW_H

#include <QStackedLayout>
#include <QWidget>
#include "todolib/todolib.h"
#include "CategoryViewPage.h"

class MainWindow : public QWidget {

Q_OBJECT

public:
    MainWindow(todolib::ToDoList &todolist);

public slots:

    void openCategoryViewPage();


private:
    todolib::ToDoList &toDoList;
    QStackedLayout stackedLayout{QStackedLayout(this)};
    std::list<std::shared_ptr<Page>> pages;

    void closePage(const std::shared_ptr<Page>& page);
};


#endif //PIC_AEM_PROJEKT_MAINWINDOW_H
