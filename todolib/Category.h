//
// Created by helen on 12.05.2023.
//

#ifndef PIC_AEM_PROJEKT_CATEGORY_H
#define PIC_AEM_PROJEKT_CATEGORY_H

#include <string>
#include <list>
#include "Task.h"
#include <memory>

using namespace std;

class Category {
private:
    string id;
    list<Task> tasks;

public:
    string name;

    // Constructor
    explicit Category(const string &n);

    // Copy Constructor
    Category(Category &other);

    // Copy Assignment Constructor
    Category &operator=(Category &other);

    // Move Constructor
    Category (Category &&other) noexcept ;

    // Move Assignment Constructor
    Category& operator=(Category&& other);

    // Destructor
    ~Category() = default;

    const string getID();

    bool isSame(const Category &other);

    unique_ptr<list<Task>> getTasks(); // ! returns a pointer that needs to be dereferentiated with "*"!

    void addTask(const Task &task);

    bool deleteTask(const string &deleteID); // returns true if successfully deleted

};


#endif //PIC_AEM_PROJEKT_CATEGORY_H
