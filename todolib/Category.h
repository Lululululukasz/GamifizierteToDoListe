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


namespace todolib {
    using namespace std;

    class Category {
    private:
        string id;

    public:
        string name;
        list<Task> tasks;

        // Constructor
        explicit Category(const string &n);

        // Copy Constructor
        Category(Category &other);

        // Copy Assignment Constructor
        Category &operator=(Category const &other);

        // Move Constructor
        Category(Category &&other) noexcept;

        // Move Assignment Constructor
        Category &operator=(Category &&other) noexcept;

        // Destructor
        ~Category() = default;

        string getID() const;

        bool isSame(const Category &other);

        void addTask(Task &task);
        void addTask(Task &&task);

        list<Task> showTasks();

        bool deleteTask(const string &deleteID); // returns true if successfully deleted

    };

}

#endif //PIC_AEM_PROJEKT_CATEGORY_H
