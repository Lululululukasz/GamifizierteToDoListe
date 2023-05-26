//
// Created by trashpanda on 26.05.23.
//

#include "AchievementWidget.h"

AchievementWidget::AchievementWidget(todolib::Achievement & achievement, QWidget *parent) : QWidget(parent) {

    achievementName.setText(QString::fromStdString(achievement.name));
    QFont nameFont("Arial", 15, QFont::Bold);
    achievementName.setFont(nameFont);

    achievementDescription.setText(QString::fromStdString(achievement.description));

    QPixmap pix("../resources/konfetti.png");
    pix = pix.scaled(80, 80, Qt::KeepAspectRatio);
    achievementIcon.setPixmap(pix);


    setLayout(&hlayout);
    hlayout.addWidget(&achievementIcon, 1, Qt::AlignLeft | Qt::AlignVCenter);
    hlayout.insertSpacing(1, 30);

    hlayout.addLayout(&vlayout);
    vlayout.addWidget(&achievementName, 1, Qt::AlignLeft | Qt::AlignVCenter);
    vlayout.addWidget(&achievementDescription, 1, Qt::AlignLeft | Qt::AlignVCenter);

}


