//
// Created by trashpanda on 10.05.23.
//

#ifndef PIC_AEM_PROJEKT_CATEGORIES_H
#define PIC_AEM_PROJEKT_CATEGORIES_H

#include <string>
#include <vector>
#include <memory>

namespace ToDoListAdventure {

    class Categories {
        // Define a vector named "category", containing all categories for tasks
        // each pair has a string for the name of the category, and a vector of
        // pointers to the tasks that belong in the category
        std::vector< std::pair<
                std::string,
                std::vector< std::shared_ptr<std::string> >
        > > category;
    public:
        Categories() = default;
        void newCategory(std::string const &category);
        void showAllCategories();
        void deleteCategory(std::string categoryToDelete);

        void assignTaskToCategory( std::shared_ptr<std::string>, std::string );
    };

} // ToDoListAdventure

#endif //PIC_AEM_PROJEKT_CATEGORIES_H
