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

void todolib::TaskFilterParameter::setDueDateFilter(int newDueDateFilter) {
    dueDateFilter = newDueDateFilter;
}

void todolib::TaskFilterParameter::setDurationFilter(double newDurationFilter) {
    durationFilter = newDurationFilter;
}

bool todolib::TaskFilterParameter::filterTask(todolib::Task &task) {
    if (!priorityFilter.empty() && !filterPriority(task)) {
        std::cout << task.name << " filtered for priority" << std::endl;
        return false;
    } else if (dueDateFilter && !filterDueDate(task)) {
        std::cout << task.name << " filtered for due date" << std::endl;
        return false;
    } else if (durationFilter && !filterDuration(task)) {
        std::cout << task.name << " filtered for duration" << std::endl;
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
    auto nowFloor = std::chrono::floor<std::chrono::days>(now);
    std::chrono::year_month_day today{nowFloor};
    //auto tp = std::chrono::system_clock::now() + dueDateFilter.value();
    //auto timePoint = std::chrono::floor<std::chrono::days>(tp);
    //std::chrono::year_month_day filter{timePoint};

    std::cout << "DueDateFilter: " << dueDateFilter.value();
    auto filtertp = std::chrono::sys_days{today} + std::chrono::days{dueDateFilter.value()};
    /*
    for (int i = 0; i < dueDateFilter.value(); ++i) {
        nowFloor++;
    }
     */
    std::chrono::year_month_day filter{filtertp};

    std::cout << "today " << static_cast<unsigned>(today.day()) << "." << static_cast<unsigned>(today.month()) << "." << static_cast<int>(today.year()) << std::endl ;
    std::cout << "filter day " << static_cast<unsigned>(filter.day()) << "." << static_cast<unsigned>(filter.month()) << "." << static_cast<int>(filter.year()) << std::endl ;
    std::cout << "task day " << static_cast<unsigned>(task.getDueDate().day()) << "." << static_cast<unsigned>(task.getDueDate().month()) << "." << static_cast<int>(task.getDueDate().year()) << std::endl ;

    if (task.getDueDate() <= filter) {
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

