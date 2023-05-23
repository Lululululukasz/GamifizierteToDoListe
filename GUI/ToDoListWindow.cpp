//
// Created by helen on 23.05.2023.
//

#include "ToDoListWindow.h"
#include "todolib/todolib.h"
#include "TaskWidget.h"
#include "CategoryWidget.h"
#include <memory>

using namespace todolib;

ToDoListWindow::ToDoListWindow(todolib::ToDoList& toDoList, QWidget *parent) : toDoList{toDoList}, QWidget{parent} {
    toDoList = ToDoList();
   // layout.addWidget(&addCategoryButton);

    //connect(&addCategoryButton, &QPushButton::clicked, this, &ToDoListWindow::addCategory);

    for (auto &category: toDoList.categories) {
        auto* categoryWidget {new CategoryWidget{category}};
        layout.addWidget(categoryWidget, 0, Qt::AlignTop);
        categoryWidgets.push_back(categoryWidget);

       /* CategoryWidget widget {CategoryWidget(category)};
        categoryWidgets.emplace_back(widget);
        layout.addWidget(categoryWidget);*/
    }

    resize(250, 150);
    setWindowTitle("to do list");
    show();
}

/*void ToDoListWindow::addCategory() {
    QString categoryName = QInputDialog::getText(this, "New Category", "enter the category name");

    if (!categoryName.isEmpty()) {
        toDoList.addCategory(Category(categoryName.toStdString()));


        adjustSize();
    }
}


void ToDoListWindow::deleteCategory(CategoryWidget &categoryWidget) {
    toDoList.deleteCategory(categoryWidget.category.getID());

}
 */

