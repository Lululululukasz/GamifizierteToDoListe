//
// Created by helen on 12.05.2023.
//

#ifndef PIC_AEM_PROJEKT_TODOLIST_H
#define PIC_AEM_PROJEKT_TODOLIST_H

#include "Category.h"
#include "Task.h"
#include <list>
#include <memory>



namespace todolib {
    using namespace std;

    /**
     * ToDoList
     *
     * The purpose of the ToDoList is to be a top level place whithin which all backend information is saved.
     */

    class ToDoList {
    private:
        list<Task> suggestions;

    public:
        /**
         * categories
         *  All Tasks are saved within the Categories in this List.
         */
        list<Category> categories;

        /**
         * ToDoList()
         * The Constructor automatically creates the "Default" Category and the suggestion list of Tasks.
         */
        explicit ToDoList();


        /**
         * getCategoryByName
         * @param name
         * @return a reference to the first Category that fits the name String
         */
        Category &getCategoryByName(const string &name);
        /**
         * get getCategoryByID
         * @param id
         * @return a reference to the category with that id
         */
        Category &getCategoryByID(const string &id);

        /**
         * addCategory
         * @param category (can be both l- and rvalue)
         */
        void addCategory(Category &&category);
        void addCategory(Category &category);

        /**
         * deleteCategory
         * @param id of the category to be deleted
         * @return true if successful, false if unsuccessful
         */
        bool deleteCategory(const string &id);

        /**
         * showAllTasks
         * @return a list of the tasks of all the categories combined
         */
        list<Task> showAllTasks();

        /**
         * getTaskByName
         * @param search
         * @return a task whith the exact same name as the search
         */
        std::shared_ptr<Task>  getTaskByName(const string &search); // formerly search
        // TODO search funktion mit Levenshtein Algorithmus

        /**
         * suggestTask
         * @return random Task from the suggestions List
         */
        Task suggestTask();

    };

}

#endif //PIC_AEM_PROJEKT_TODOLIST_H
