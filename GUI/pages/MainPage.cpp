//
// Created by helen on 30.05.2023.
//

#include "GUI/pages/MainPage.h"

MainPage::MainPage(todolib::Profile &profile) : Page{profile} {
    // nav bar
    closeButton->hide();
    layoutWidget.hNavBar->addWidget(&header);

    // Adding and connecting the Achievements page
    layoutWidget.hNavBar->addWidget(&achievementsPageButton);
    achievementsPageButton.setGeometry(10, 100, 80, 30);
    connect(&achievementsPageButton, SIGNAL(clicked()), this, SIGNAL(openAchievementsPageSignal()));

    // Sidebar
    layoutWidget.vSideBar->addWidget(&placeholderSearchbar);
    layoutWidget.vSideBar->addWidget(&placeholderFilter);
}
