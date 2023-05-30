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

class MainPage : public Page {

Q_OBJECT

public:
    explicit MainPage(todolib::ToDoList &toDoList);

    signals:
    void openCategoryViewPageSignal();

private:
    QPushButton categoryViewPageButton{QPushButton("Open the Category View")};

    void categoryViewPageButtonPressed();

};


#endif //PIC_AEM_PROJEKT_MAINPAGE_H
