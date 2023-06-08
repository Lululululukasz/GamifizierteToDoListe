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
#include <chrono>
#include <QtCore/QJsonObject>
#include "Category.h"


namespace todolib {
    using namespace std;

    class Task {

    public:
        /**
         * an enum that holds the different possible priorities.
         */
        using priority_t = enum {
            trivial,
            low,
            medium,
            high,
            urgent
        };

    private:
        string id;
        bool done;
        priority_t priority;
        double duration;
        std::chrono::year_month_day dueDate;
        std::string picture;
        todolib::Category* category {nullptr};

    public:
        string name;
        string description;


        /**
         * Constructor Task
         * @param n name
         * @param d description
         */
        explicit Task(const string &n, const string &d);

        /**
         * Constructor to create a task with a QjsonObject
         * @param QJsonObject taskObject
         */
        explicit Task(const QJsonObject &taskObject);

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

        void setPriority(Task::priority_t prio);
        priority_t getPriority();

        /** converts the priority to a string
         *
         * @return standard string
         */
        std::string getPriorityString();

        void setDuration(double dur);
        [[nodiscard]] double getDuration() const;

        void setDueDate(std::chrono::year_month_day due);
        std::chrono::year_month_day getDueDate();

        void setPicture(std::string pic);
        std::string getPicture();

        /**
         * Function to convert the task with it's attributes to a QJsonObject
         * @return QJsonObject
         */
        QJsonObject toJson();

        void saveToJson();
        void setCategory(todolib::Category *newCategory);
    };

}

#endif //PIC_AEM_PROJEKT_TASK_H
