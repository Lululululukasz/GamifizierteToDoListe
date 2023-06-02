//
// Created by trashpanda on 26.05.23.
//

#include "AchievementWidget.h"

AchievementWidget::AchievementWidget(todolib::Achievement &achievement, QWidget *parent) : QWidget(parent) {

    // Achievement Name, styled
    achievementName.setText(QString::fromStdString(achievement.name));
    QFont nameFont("Arial", 15, QFont::Bold);
    achievementName.setFont(nameFont);

    // Achievement Description
    achievementDescription.setText(QString::fromStdString(achievement.description));

    // Achievement Icon (currently same example icon for every achievement)
    // TODO individualize icons for different achievements
    QPixmap pix {"../resources/konfetti.png"};
    pix = pix.scaled(80, 80, Qt::KeepAspectRatio);
    achievementIcon.setPixmap(pix);

    // Layout of Widget Components
    setLayout(&hlayout); // hlayout places the two components (icon & vlayout(name,description)) next to each other
    hlayout.addWidget(&achievementIcon, 1, Qt::AlignLeft | Qt::AlignVCenter);
    hlayout.insertSpacing(1, 15);
    hlayout.addLayout(&vlayout, 10); // vlayout places the name and description below each other
    vlayout.addWidget(&achievementName, 1, Qt::AlignLeft | Qt::AlignVCenter);
    vlayout.addWidget(&achievementDescription, 1, Qt::AlignLeft | Qt::AlignVCenter);

    // background color and font color for Achievement Widget
    palet.setColor(QPalette::Window, "#080c11");
    palet.setColor(QPalette::WindowText, Qt::white);
    setAutoFillBackground(true);
    setPalette(palet);
}


