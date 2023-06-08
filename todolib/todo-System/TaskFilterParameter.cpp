//
// Created by helen on 07.06.2023.
//

#include "TaskFilterParameter.h"

void todolib::TaskFilterParameter::addPriorityFilter(todolib::Task::priority_t priority) {
    priorityFilter.push_back(priority);
}
void todolib::TaskFilterParameter::removePriorityFilter(Task::priority_t priority) {
    priorityFilter.remove(priority);
}

void todolib::TaskFilterParameter::setDueDateFilter(DueDateFilter &newDueDateFilter) {
    dueDateFilter = newDueDateFilter;
}

void todolib::TaskFilterParameter::setDurationFilter(double &newDurationFilter) {
    durationFilter = newDurationFilter;
}

bool todolib::TaskFilterParameter::filterTask(todolib::Task &task) {
    if (!priorityFilter.empty() && !filterPriority(task)) {
        return false;
    } else if (dueDateFilter && !filterDueDate(task)) {
        return false;
    } else if (durationFilter && !filterDuration(task)) {
        return false;
    }
    return true;
}

bool todolib::TaskFilterParameter::filterPriority(todolib::Task &task) {
    for (Task::priority_t& filter : priorityFilter) {
        if (task.getPriority() == filter) {
            return true;
        }
    }
    return false;
}

bool todolib::TaskFilterParameter::filterDueDate(todolib::Task &task) {
    return false;
}

bool todolib::TaskFilterParameter::filterDuration(todolib::Task &task) {
    if (durationFilter >= 0) {
        if (task.getDuration() < durationFilter) {
            return true;
        } else {
            return false;
        }
    } else if (task.getDuration() > (-1.0 * durationFilter.value())) {
        return true;
    } else {
        return false;
    }
}

void todolib::TaskFilterParameter::clear() {
    priorityFilter.clear();
    dueDateFilter.reset();
    durationFilter.reset();
}

void todolib::TaskFilterParameter::clearPriorityFilter() {
    priorityFilter.clear();
}

void todolib::TaskFilterParameter::clearDueDateFilter() {
    dueDateFilter.reset();
}

void todolib::TaskFilterParameter::clearDurationFilter() {
    durationFilter.reset();
}

