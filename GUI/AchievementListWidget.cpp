//
// Created by trashpanda on 26.05.23.
//

#include "AchievementListWidget.h"
#include "AchievementWidget.h"

AchievementListWidget::AchievementListWidget(todolib::AchievementList &achievementList, QWidget *parent)
: achievements{achievementList} {

    setLayout(&vlayout);

    // List of Achievements
    for (todolib::Achievement a : achievements.getAchievements()) {
        AchievementWidget widget {a};
        vlayout.addWidget(&widget, 0, Qt::AlignTop);
    }
}
