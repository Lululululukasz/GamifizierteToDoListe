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

    class ToDoList {
    private:
        list<Task> suggestions;

    public:
        list<Category> categories;

        explicit ToDoList();

        Category &getCategoryByName(const string &name); // ! Will just get you the first one with that name
        Category &getCategoryByID(const string &id);

        void addCategory(Category &&category);

        bool deleteCategory(const string &c);

        list<Task> showAllTasks();

        Task &getTaskByName(const string &search); // formerly search

        // TODO search funktion mit Levenshtein Algorithmus

        Task suggestTask();

    };

}


#endif //PIC_AEM_PROJEKT_TODOLIST_H
