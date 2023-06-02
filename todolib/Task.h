//
// Created by helen on 12.05.2023.
//

#ifndef PIC_AEM_PROJEKT_TASK_H
#define PIC_AEM_PROJEKT_TASK_H

namespace todolib {
    class Task;
}

#include <string>
#include <vector>
#include <memory>
#include "Category.h"
#include "Xp.h"


namespace todolib {
    using namespace std;

    class Task {
    private:
        string id;
        bool done;
        // TODO datetime

    public:
        string name;
        string description;

        /**
         * Constructor Task
         * @param n name
         * @param d description
         */
        explicit Task(const string &n, const string &d);

        string getID();

        /**
         * isSame
         * @param other
         * @return true if the tasks have the same id, false if not
         */
        bool isSame(const Task &other);

        bool getDoneStatus() const;

        void setAsDone();
        void setAsUndone();

    };

}

#endif //PIC_AEM_PROJEKT_TASK_H
