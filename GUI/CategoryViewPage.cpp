//
// Created by helen on 23.05.2023.
//

#include "CategoryViewPage.h"
#include "todolib/todolib.h"
#include "TaskWidget.h"
#include "CategoryWidget.h"
#include <memory>

using namespace todolib;

CategoryViewPage::CategoryViewPage(todolib::ToDoList &toDoList) : Page{toDoList} {
    layout.addWidget(&addCategoryButton);
    addCategoryButton.setGeometry(10, 100, 80, 30);
    connect(&addCategoryButton, &QPushButton::clicked, this, [&]() { addCategory(); });

    for (Category &category: toDoList.categories) {
        addCategoryWidget(category);
    }
}

void CategoryViewPage::addCategory() {
    QString categoryName = QInputDialog::getText(this, "New Category", "enter the category name");
    if (!categoryName.isEmpty()) {
        Category category = Category(categoryName.toStdString());
        toDoList.addCategory(category);
        addCategoryWidget(toDoList.categories.back());
    }
}

void CategoryViewPage::addCategoryWidget(Category& category) {
    shared_ptr<CategoryWidget> widget {make_shared<CategoryWidget>(category)};
    categoryWidgets.push_back(widget);
    layout.addWidget(widget.get(), 0, Qt::AlignTop);
    connect(widget.get(), &CategoryWidget::categoryDeleteSignal, this, [=, this]() { deleteCategory(widget); });
}


void CategoryViewPage::deleteCategory(const shared_ptr<CategoryWidget>& categoryWidget) {
    toDoList.deleteCategory(categoryWidget->category.getID());
    categoryWidget->hide();
    layout.removeWidget(categoryWidget.get());
    categoryWidgets.remove(categoryWidget);
}


