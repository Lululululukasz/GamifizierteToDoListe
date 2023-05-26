//
// Created by trashpanda on 26.05.23.
//

#include "AchievementList.h"

namespace todolib {

    AchievementList::AchievementList(){

        //TODO remove temp achievements!
        Achievement a {"Washing", "You washed 10 times the dishes"};
        Achievement b {"Learning", "You learned 1 time"};
        Achievement c {"First Time", "Go to your very first Lecture"};
        a.setAsDone();
        b.setAsDone();
        addAchievement(a);
        addAchievement(b);
        addAchievement(c);

    }

    void AchievementList::addAchievement(Achievement &achievement){
        achievements.emplace_back(achievement);
    }

    std::vector<Achievement>  AchievementList::getAchievements() {
        return this->achievements; //TODO make read only?
    }

} // todolib

