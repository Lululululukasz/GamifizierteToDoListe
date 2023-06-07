//
// Created by trashpanda on 01.06.23.
//

#include "GUI/pages/AchievementsPage.h"

AchievementsPage::AchievementsPage(todolib::Profile &profile) : Page{profile}, achievementList{profile.todoList} {

    achievementListWidget = std::make_shared<AchievementListWidget>(achievementList);
    layoutWidget.vOuterLayout->addWidget(achievementListWidget.get(), 0, Qt::AlignTop);

}