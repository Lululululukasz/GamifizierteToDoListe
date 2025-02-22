//
// Created by helen on 12.05.2023.
//

#ifndef PIC_AEM_PROJEKT_CATEGORY_H
#define PIC_AEM_PROJEKT_CATEGORY_H

namespace todolib {
    class Category;
}

#include <string>
#include <list>
#include "Task.h"
#include <memory>
#include "../../utility/JsonList.tpp"
#include "../../utility/Json.h"


namespace todolib {
    using namespace std;

    /**
     * Category
     * saves a List of Tasks
     */
    class Category {
    private:
        string id;

    public:
        string name;
        JsonList<Task> tasks;

        /**
         * Category Constructor
         * @param n name
         */
        explicit Category(const string &n);

        /**
         * Category Constructor for Jsonobjects
         * @param jsonObject
         */
        explicit Category(const QJsonObject &jsonObject);

        /**
         * isSame
         * @param other
         * @return true if the tasks have the same id, false if not
         */
        bool isSame(const Category &other) const;

        /**
         * addTask
         * @param task (can be both l- and rvalue)
         */
        void addTask(Task &task);

        void addTask(Task &&task);

        /**
         * deleteTask
         * @param deleteID id of the task to be deleted
         * @return true if successful, false if unsuccessful
         */
        bool deleteTask(const string &deleteID);

        /**
         * Function to convert the category-attributes to a QJsonObject and writes it to a .jsonfile
         */
        void saveToJson();

        /**
         * getter and setter
         */
        string getID() const;

        void setName(std::string &&newName);
        std::string getName();
    };

}

#endif //PIC_AEM_PROJEKT_CATEGORY_H
