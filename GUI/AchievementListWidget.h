//
// Created by trashpanda on 26.05.23.
//

#ifndef PIC_AEM_PROJEKT_ACHIEVEMENTLISTWIDGET_H
#define PIC_AEM_PROJEKT_ACHIEVEMENTLISTWIDGET_H


#include <QWidget>
#include <QVBoxLayout>
#include "todolib/AchievementList.h"

class AchievementListWidget : public QWidget {

Q_OBJECT

public:
    explicit AchievementListWidget(todolib::AchievementList &achievementList, QWidget *parent = nullptr);

private:
    QVBoxLayout vlayout{QVBoxLayout()};
    todolib::AchievementList &achievements;

};

#endif //PIC_AEM_PROJEKT_ACHIEVEMENTLISTWIDGET_H
