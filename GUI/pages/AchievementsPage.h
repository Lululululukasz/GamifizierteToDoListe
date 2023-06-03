//
// Created by trashpanda on 01.06.23.
//

#ifndef PIC_AEM_PROJEKT_ACHIEVEMENTSPAGE_H
#define PIC_AEM_PROJEKT_ACHIEVEMENTSPAGE_H


#include "Page.h"
#include "GUI/widgets/achievement/AchievementListWidget.h"

class AchievementsPage : public Page {

Q_OBJECT

public:
    explicit AchievementsPage(todolib::ToDoList& toDoList);

private:
    std::shared_ptr<AchievementListWidget> achievementListWidget;
    todolib::AchievementList achievementList;

};

#endif //PIC_AEM_PROJEKT_ACHIEVEMENTSPAGE_H
