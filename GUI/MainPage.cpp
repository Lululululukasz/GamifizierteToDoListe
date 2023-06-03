//
// Created by helen on 30.05.2023.
//

#include "MainPage.h"

MainPage::MainPage(todolib::ToDoList &toDoList) : Page{toDoList} {
    closeButton->hide();

    // Adding and connecting of the categoryViewPage use as template for other Pages
    layout->addWidget(&categoryViewPageButton);
    categoryViewPageButton.setGeometry(10, 100, 80, 30);
    connect(&categoryViewPageButton, SIGNAL(clicked()), this, SIGNAL(openCategoryViewPageSignal()));

    // Adding and connecting the Achievements page
    layout->addWidget(&achievementsPageButton);
    achievementsPageButton.setGeometry(10, 100, 80, 30);
    connect(&achievementsPageButton, SIGNAL(clicked()), this, SIGNAL(openAchievementsPageSignal()));

}

