//
// Created by helen on 23.05.2023.
//

#include "ToDoListWindow.h"
#include "todolib/todolib.h"
#include "TaskWidget.h"
#include <memory>

using namespace todolib;
ToDoListWindow::ToDoListWindow() {
    toDoList = ToDoList();

    addCategoryButton = new QPushButton("add a new Category"); // TODO memory leak
    layout.addWidget(addCategoryButton);

    QObject::connect(addCategoryButton, &QPushButton::clicked, [&]() {addCategory();});


    resize(250, 150);
    setWindowTitle("to do list");
    show();
}

void ToDoListWindow::addCategory() {
    QString categoryName = QInputDialog::getText(this, "new Category", "enter the category name");
    if (!categoryName.isEmpty()) {
        QStringList newCategory;
        categoryWidgets.append(newCategory);

        CategoryWidget* categoryWidget = new CategoryWidget(categoryName, categoryWidgets, layout, (categoryWidgets.size() - 1)); // TODO memory leak
        layout.addWidget(categoryWidget);

        adjustSize();
    }
}
