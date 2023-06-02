//
// Created by trashpanda on 26.05.23.
//

#include "Achievement.h"
#include <ctime>

namespace todolib {
    Achievement::Achievement(const std::string &name, const std::string &description, const std::string task)
    : name {name}, description {description}, taskForAchievement {task} {

        this->id = name + std::to_string((int) time(nullptr));

    }

    std::string Achievement::getID() {
        return this->id;
    }

    bool Achievement::getDoneStatus() const {
        return this->done;
    }

    void Achievement::setAsDone() {
        this->done = true;
    }
} // todolib