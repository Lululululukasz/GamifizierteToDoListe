//
// Created by trashpanda on 26.05.23.
//

#ifndef PIC_AEM_PROJEKT_ACHIEVEMENTLIST_H
#define PIC_AEM_PROJEKT_ACHIEVEMENTLIST_H

#include <vector>
#include "Achievement.h"

namespace todolib {

    class AchievementList {
    private:
        std::vector<Achievement> achievements;

    public:

        // Constructor
        explicit AchievementList();

        // Destructor
        ~AchievementList() = default;

        void addAchievement(Achievement &achievement);

        std::vector<Achievement> getAchievements();

    };

} // todolib

#endif //PIC_AEM_PROJEKT_ACHIEVEMENTLIST_H
