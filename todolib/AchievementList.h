//
// Created by trashpanda on 26.05.23.
//

#ifndef PIC_AEM_PROJEKT_ACHIEVEMENTLIST_H
#define PIC_AEM_PROJEKT_ACHIEVEMENTLIST_H

#include <vector>
#include "Achievement.h"
#include "ToDoList.h"

namespace todolib {

    class AchievementList {
    private:
        std::vector<Achievement> achievements;

    public:

        // Constructor
        explicit AchievementList(ToDoList &todolist);

        // Destructor
        ~AchievementList() = default;

        void addAchievement(Achievement &achievement);
        std::vector<Achievement> getAchievements();
        bool setThisAchievementAsDone(std::string &taskName);

    };

} // todolib

#endif //PIC_AEM_PROJEKT_ACHIEVEMENTLIST_H
