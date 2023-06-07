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
        Task(const QJsonObject &taskObject);

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

        void setdueDate(std::chrono::year_month_day due);
        std::chrono::year_month_day getdueDate();

        /**
         * Function to convert the task with it's attributes to a QJsonObject
         * @return QJsonObject
         */
        QJsonObject toJson();
    };

}

#endif //PIC_AEM_PROJEKT_TASK_H
