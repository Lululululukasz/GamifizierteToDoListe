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


namespace todolib {
    using namespace std;

    class Task {
    private:

        bool done{false};
        // TODO datetime

    public:
        string id;
        string name;
        string description;

        // Constructor
        explicit Task(const string &n, const string &d);

        string getID();

        bool isSame(const Task &other);

        bool getDoneStatus() const;

        void setAsDone();

        void setAsUndone();

    };

}

#endif //PIC_AEM_PROJEKT_TASK_H
