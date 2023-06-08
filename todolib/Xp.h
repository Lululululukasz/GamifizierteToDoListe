//
// Created by Jan Ole Weighardt on 26.05.23.
//

#ifndef AEMPROJEKT_XP_H
#define AEMPROJEKT_XP_H

#include "iostream"

namespace todolib {
    class Xp {
    public:
        Xp();
       unsigned int levelNumber{1};
       int xptrueNumber {0};
       void setlevelNumber(unsigned int level);
       void setxptrueNumber(int xp);
       void saveToJson();
    };
}

#endif //AEMPROJEKT_XP_H
