//
// Created by helen on 30.05.2023.
//

#ifndef PIC_AEM_PROJEKT_MAINPAGE_H
#define PIC_AEM_PROJEKT_MAINPAGE_H

#include "Page.h"
#include "todolib/todolib.h"
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>

/**
 * MainPage
 * Default Base Page including buttons to open all other pages.
 * To add a new type of page it needs its own button and signal that are connected in the constructor.
 */
class MainPage : public Page {

Q_OBJECT

public:
    /**
     * MainPage Constructor
     * Adds and connects the button for each type of page.
     * @param toDoList
     */
    explicit MainPage(todolib::ToDoList &toDoList);

    signals:
    void openCategoryViewPageSignal();

private:
    QPushButton categoryViewPageButton{QPushButton("Open the Category View")};

};


#endif //PIC_AEM_PROJEKT_MAINPAGE_H
