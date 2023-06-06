//
// Created by helen on 30.05.2023.
//

#include "GUI/pages/MainPage.h"

MainPage::MainPage(todolib::ToDoList &toDoList) : Page{toDoList} {
    // nav bar
    closeButton->hide();
    layoutWidget.hNavBar->addWidget(&header);

    // Adding and connecting of the categoryViewPage use as template for other Pages
    layoutWidget.hNavBar->addWidget(&categoryViewPageButton);
    categoryViewPageButton.setGeometry(10, 100, 80, 30);
    connect(&categoryViewPageButton, SIGNAL(clicked()), this, SIGNAL(openCategoryViewPageSignal()));

    // Adding and connecting the Achievements page
    layoutWidget.hNavBar->addWidget(&achievementsPageButton);
    achievementsPageButton.setGeometry(10, 100, 80, 30);
    connect(&achievementsPageButton, SIGNAL(clicked()), this, SIGNAL(openAchievementsPageSignal()));

    // Sidebar
    layoutWidget.vSideBar->addWidget(&placeholderSearchbar);
    layoutWidget.vSideBar->addWidget(&placeholderFilter);

    // Body
    layoutWidget.vBodyLayout->addWidget(&placeholderBody);

    // Footer
    layoutWidget.vOuterLayout->addWidget(&placeholderAddButton);
}
