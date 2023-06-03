//
// Created by trashpanda on 26.05.23.
//

#include "AchievementListWidget.h"
#include "AchievementWidget.h"
#include "GUI/widgets/category-task/CategoryWidget.h"

AchievementListWidget::AchievementListWidget(todolib::AchievementList &achievementList, QWidget *parent) {

    setLayout(&vlayout);

    // List of Achievements that are done
     for (todolib::Achievement &a : achievementList.getAchievements()) {
         if (a.getDoneStatus()) addAchievementWidget(a);
     }

    // background color for whole List
    palet.setColor(QPalette::Window, "#04395b");
    setAutoFillBackground(true);
    setPalette(palet);
}

void AchievementListWidget::addAchievementWidget(todolib::Achievement &achievement) {
    std::shared_ptr<AchievementWidget> widget {std::make_shared<AchievementWidget>(achievement)};
    achievementWidgets.emplace_back(widget);
    widget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    widget->setMinimumSize(450,100);

    vlayout.addWidget(widget.get(), 1, Qt::AlignLeft | Qt::AlignVCenter);
}
