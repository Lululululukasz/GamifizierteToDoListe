//
// Created by trashpanda on 26.05.23.
//

#include "AchievementListWidget.h"
#include "AchievementWidget.h"
#include "CategoryWidget.h"

AchievementListWidget::AchievementListWidget(todolib::AchievementList &achievementList, QWidget *parent) {

    setLayout(&vlayout);

    // List of Achievements that are done
     for (todolib::Achievement &a : achievementList.getAchievements()) {
         if (a.getDoneStatus()) addAchievementWidget(a);
     }
}

void AchievementListWidget::addAchievementWidget(todolib::Achievement &achievement) {
    std::shared_ptr<AchievementWidget> widget {std::make_shared<AchievementWidget>(achievement)};
    achievementWidgets.emplace_back(widget);
    vlayout.addWidget(widget.get(), 1, Qt::AlignLeft | Qt::AlignVCenter);
}
