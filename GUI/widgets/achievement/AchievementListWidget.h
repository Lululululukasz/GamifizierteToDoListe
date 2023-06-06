//
// Created by trashpanda on 26.05.23.
//

#ifndef PIC_AEM_PROJEKT_ACHIEVEMENTLISTWIDGET_H
#define PIC_AEM_PROJEKT_ACHIEVEMENTLISTWIDGET_H


#include <QWidget>
#include <QVBoxLayout>
#include "todolib/todolib.h"
#include "AchievementWidget.h"

class AchievementListWidget : public QWidget {

Q_OBJECT

public:
    explicit AchievementListWidget(todolib::AchievementList &achievementList, QWidget *parent = nullptr);

private:
    QVBoxLayout vlayout{QVBoxLayout()};
    QPalette palet {QPalette()};

    std::vector<std::shared_ptr<AchievementWidget>> achievementWidgets;
    void addAchievementWidget(todolib::Achievement &task);
};

#endif //PIC_AEM_PROJEKT_ACHIEVEMENTLISTWIDGET_H
