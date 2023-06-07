//
// Created by trashpanda on 02.06.23.
//

#ifndef PIC_AEM_PROJEKT_PROFILE_H
#define PIC_AEM_PROJEKT_PROFILE_H

#include "todo-System/ToDoList.h"
#include "achievement-System/AchievementList.h"
#include "Xp.h"

namespace todolib {

    class Profile {
    public:
        ToDoList todoList {};
        AchievementList achievementList {todoList};
        // TODO add XP/Level - classes could be stored in todolib/leveling-System
        Xp xp {};
    };

} // todolib

#endif //PIC_AEM_PROJEKT_PROFILE_H
