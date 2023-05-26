//
// Created by trashpanda on 26.05.23.
//

#include "AchievementWidget.h"

AchievementWidget::AchievementWidget(todolib::Achievement & achievement, QWidget *parent) : QWidget(parent) {

    setLayout(&vlayout);
    vlayout.addLayout(&hlayout);

    achievementName.setText(QString::fromStdString(achievement.name));
    achievementDescription.setText(QString::fromStdString(achievement.description));

    QPixmap pix("../resources/konfetti.png");
    achievementIcon.setPixmap(pix);

    vlayout.addWidget(&achievementIcon, 1, Qt::AlignLeft | Qt::AlignVCenter);
    hlayout.addWidget(&achievementName, 1, Qt::AlignLeft | Qt::AlignVCenter);
    vlayout.addWidget(&achievementDescription, 1, Qt::AlignLeft | Qt::AlignVCenter);

}


