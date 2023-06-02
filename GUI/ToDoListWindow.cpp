//
// Created by helen on 23.05.2023.
//

#include "ToDoListWindow.h"
#include "todolib/todolib.h"
#include "TaskWidget.h"
#include "CategoryWidget.h"
#include "XpWidget.h"
#include <memory>

using namespace todolib;

ToDoListWindow::ToDoListWindow(todolib::ToDoList &toDoList, QWidget *parent) : toDoList{toDoList}, QWidget{parent} {
    layout.addWidget(&addCategoryButton);
    addCategoryButton.setGeometry(10, 100, 80, 30);
    connect(&addCategoryButton, &QPushButton::clicked, this, [&]() { addCategory(); });

    for (Category &category: toDoList.categories) {
        addCategoryWidget(category);
        addXpWidget();
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
    connect(widget.get(), &CategoryWidget::xpWidgetSignal1, this, &ToDoListWindow::xpWidgetSignal1);
    connect(widget.get(), &CategoryWidget::xpWidgetSignal2, this, &ToDoListWindow::xpWidgetSignal2);
}


void ToDoListWindow::deleteCategory(const shared_ptr<CategoryWidget>& categoryWidget) {
    toDoList.deleteCategory(categoryWidget->category.getID());
    categoryWidget->hide();
    layout.removeWidget(categoryWidget.get());
    categoryWidgets.remove(categoryWidget);
}

void ToDoListWindow::addXpWidget(){
    std::shared_ptr<XpWidget> xpWidget {std::make_shared<XpWidget>(/*toDoList,*/this)};
    xpWidgets.push_back(xpWidget);
    layout.addWidget(xpWidget.get(),0,Qt::AlignBottom);
    connect(this, &ToDoListWindow::xpWidgetSignal1, xpWidget.get(), &XpWidget::xpWidgetFunc1);
    connect(this, &ToDoListWindow::xpWidgetSignal2, xpWidget.get(), &XpWidget::xpWidgetFunc2);
}


