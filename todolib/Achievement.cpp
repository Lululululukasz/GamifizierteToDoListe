//
// Created by trashpanda on 26.05.23.
//

#include "Achievement.h"

namespace todolib {
    Achievement::Achievement(const std::string &name, const std::string &description)
    : name {name}, description {description} {

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