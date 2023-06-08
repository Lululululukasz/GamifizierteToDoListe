//
// Created by helen on 07.06.2023.
//

#include "TaskFilterParameter.h"
#include <iostream>

void todolib::TaskFilterParameter::addPriorityFilter(todolib::Task::priority_t priority) {
    priorityFilter.push_back(priority);
}
void todolib::TaskFilterParameter::removePriorityFilter(Task::priority_t priority) {
    priorityFilter.remove(priority);
}

void todolib::TaskFilterParameter::setDueDateFilter(std::chrono::days &newDueDateFilter) {
    dueDateFilter = newDueDateFilter;
}

void todolib::TaskFilterParameter::setDurationFilter(double &newDurationFilter) {
    durationFilter = newDurationFilter;
}

bool todolib::TaskFilterParameter::filterTask(todolib::Task &task) {
    if (!priorityFilter.empty() && !filterPriority(task)) {
        std::cout << task.name << " filtered for priority";
        return false;
    } else if (dueDateFilter && !filterDueDate(task)) {
        std::cout << task.name << " filtered for due date";
        return false;
    } else if (durationFilter && !filterDuration(task)) {
        std::cout << task.name << " filtered for duration";
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
    auto now = std::chrono::system_clock::now();
    auto today = std::chrono::floor<std::chrono::days>(now);
    std::chrono::year_month_day filter{today + dueDateFilter.value()};
    std::cout << "filter day " << static_cast<unsigned>(filter.day()) << "." << static_cast<unsigned>(filter.month()) << "." << static_cast<int>(filter.year()) << std::endl ;
    std::cout << "task due day " << static_cast<unsigned>(task.getdueDate().day()) << "." << static_cast<unsigned>(task.getdueDate().month()) << "." << static_cast<int>(task.getdueDate().year()) << std::endl ;
    if (task.getdueDate() < filter) {
        return true;
    }
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

