//
// Created by helen on 07.06.2023.
//

#ifndef PIC_AEM_PROJEKT_TASKFILTERPARAMETER_H
#define PIC_AEM_PROJEKT_TASKFILTERPARAMETER_H

#include <optional>
#include "Task.h"

namespace todolib {
    using namespace std;
class TaskFilterParameter {

public:

    using DueDateFilter = enum {
        today,
        tomorrow,
        thisWeek,
        thisMonth
    };

    void setPriorityFilter(Task::priority_t &newPriority);
    void setDueDateFilter(DueDateFilter &newDueDateFilter);
    void setDurationFilter(double &newDurationFilter);
    bool filterTask(Task& task);
    void clearPriorityFilter();
    void clearDueDateFilter();
    void clearDurationFilter();
    void clear();

private:
    optional<Task::priority_t> priorityFilter;
    optional<DueDateFilter> dueDateFilter;
    optional<double> durationFilter;

    bool filterPriority(Task& task);
    bool filterDueDate(Task& task);
    bool filterDuration(Task& task);

};

}


#endif //PIC_AEM_PROJEKT_TASKFILTERPARAMETER_H
