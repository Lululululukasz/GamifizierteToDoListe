//
// Created by trashpanda on 01.06.23.
//

#include "GUI/pages/AchievementsPage.h"

AchievementsPage::AchievementsPage(todolib::ToDoList &toDoList) : Page{toDoList}, achievementList{toDoList} {

    achievementListWidget = std::make_shared<AchievementListWidget>(achievementList);
    layout->addWidget(achievementListWidget.get(), 0, Qt::AlignTop);

}