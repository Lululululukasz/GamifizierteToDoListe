//
// Created by helen on 23.05.2023.
//

#include "ToDoListWindow.h"
#include "todolib/todolib.h"
#include "TaskWidget.h"
#include "CategoryWidget.h"
#include <memory>

using namespace todolib;

ToDoListWindow::ToDoListWindow(todolib::ToDoList &toDoList, QWidget *parent) : toDoList{toDoList}, QWidget{parent} {
    layout.addWidget(&addCategoryButton);
    addCategoryButton.setGeometry(10, 100, 80, 30);
    connect(&addCategoryButton, &QPushButton::clicked, this, [&]() { addCategory(); });

    for (Category &category: toDoList.categories) {
        addCategoryWidget(category);
    }

    resize(400, 400);
    setWindowTitle("to do list");
    show();
}

void ToDoListWindow::addCategory() {
    QString categoryName = QInputDialog::getText(this, "New Category", "enter the category name");
    if (!categoryName.isEmpty()) {
        Category category = Category(categoryName.toStdString());
        toDoList.addCategory(category);
        addCategoryWidget(toDoList.categories.back());
    }
}

void ToDoListWindow::addCategoryWidget(Category& category) {
    shared_ptr<CategoryWidget> widget {make_shared<CategoryWidget>(category)};
    categoryWidgets.push_back(widget);
    layout.addWidget(widget.get(), 0, Qt::AlignTop);
    connect(widget.get(), &CategoryWidget::categoryDeleteSignal, this, [=, this]() { deleteCategory(widget); });
}


void ToDoListWindow::deleteCategory(const shared_ptr<CategoryWidget>& categoryWidget) {
    toDoList.deleteCategory(categoryWidget->category.getID());
    categoryWidget->hide();
    layout.removeWidget(categoryWidget.get());
    categoryWidgets.remove(categoryWidget);
}


