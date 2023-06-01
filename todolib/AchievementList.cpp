//
// Created by trashpanda on 26.05.23.
//

#include "AchievementList.h"

namespace todolib {

    AchievementList::AchievementList(ToDoList &todolist) {

        // taskNames (third parameter) should be changed, if they change in ToDoList.cpp
       // Achievement dishes10 {"Washing", "You washed the dishes  10 times", "Dishes"}; // TODO uncomment, when multiple achievements usable
       // addAchievement(dishes10);
        Achievement learn1 {"Learning", "You learned 1 time", "Study"};
        addAchievement(learn1);
        Achievement lecture1 {"First Time", "Go to your very first Lecture", "Lecture"};
        addAchievement(lecture1);
        Achievement semester1 {"Party Hard", "Complete your first Semester", "Semester"};
        addAchievement(semester1);
        Achievement quit {"Fuck That", "Quit your studies", "Quit"};
        addAchievement(quit);
        Achievement exams {"Blackout", "Survive the exams", "Exams"};
        addAchievement(exams);

        for (Achievement achievement : achievements) {
            // TODO this is only for one time task achievements, implement also for more than one time a. (example: 10x washing dishes)
            std::shared_ptr<Task> task {todolist.getTaskByName(achievement.taskForAchievement)};
            if (nullptr != task && task->getDoneStatus()) {
                achievement.setAsDone();
            }
        }
        achievements.begin()->setAsDone(); // TODO remove, temporary for display testing
        (achievements.begin()+1)->setAsDone(); // TODO remove

    }

    void AchievementList::addAchievement(Achievement &achievement){
        achievements.emplace_back(achievement);
    }

    std::vector<Achievement>  AchievementList::getAchievements() {
        return this->achievements;
    }

    // returns true if task with that Name can be found and achievement for it can be set
    bool setThisAchievementAsDone(std::string &taskName) {

    }

} // todolib

