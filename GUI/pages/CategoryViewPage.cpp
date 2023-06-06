//
// Created by helen on 23.05.2023.
//

#include "CategoryViewPage.h"
#include "todolib/todolib.h"


#include "GUI/widgets/XpWidget.h"
#include "GUI/widgets/category-task/TaskWidget.h"
#include "GUI/widgets/category-task/CategoryWidget.h"
#include <memory>

using namespace todolib;

CategoryViewPage::CategoryViewPage(todolib::Profile &profile) : Page{profile} {
    layoutWidget.vOuterLayout->addWidget(&addCategoryButton);
    addCategoryButton.setGeometry(10, 100, 80, 30);
    connect(&addCategoryButton, &QPushButton::clicked, this, [&]() { addCategory(); });

    for (Category &category: profile.todoList.categories) {
        addCategoryWidget(category);
    }

}

void CategoryViewPage::addCategory() {
    QString categoryName = QInputDialog::getText(this, "New Category", "enter the category name");
    if (!categoryName.isEmpty()) {
        Category category = Category(categoryName.toStdString());
        profile.todoList.addCategory(category);
        addCategoryWidget(profile.todoList.categories.back());
    }
}

void CategoryViewPage::addCategoryWidget(Category& category) {
    shared_ptr<CategoryWidget> widget {make_shared<CategoryWidget>(category, *this)};
    categoryWidgets.push_back(widget);
    layoutWidget.vOuterLayout->addWidget(widget.get(), 0, Qt::AlignTop);
    connect(widget.get(), &CategoryWidget::categoryDeleteSignal, this, [=, this]() { deleteCategory(widget); });
    connect(widget.get(), &CategoryWidget::xpWidgetSignal1, this, &Page::xpWidgetSignal1);
    connect(widget.get(), &CategoryWidget::xpWidgetSignal2, this, &Page::xpWidgetSignal2);
    connect(widget.get(), &CategoryWidget::categoryConfigSignal, this, [=, this]() { configCategory(widget); });
    connect(widget.get(), &CategoryWidget::refreshPageWidgetSignal, this, &CategoryViewPage::refreshPageSignal);
}

void CategoryViewPage::deleteCategory(const shared_ptr<CategoryWidget>& categoryWidget) {
    profile.todoList.deleteCategory(categoryWidget->category.getID());
    categoryWidget->hide();
    layoutWidget.vOuterLayout->removeWidget(categoryWidget.get());
    categoryWidgets.remove(categoryWidget);
}

void CategoryViewPage::configCategory(const shared_ptr<CategoryWidget>& categoryWidget){
    QString categoryName = QInputDialog::getText(this, "Category Config", "enter the category name");
    if (!categoryName.isEmpty()) {
        categoryWidget->changeName(categoryName);
        categoryWidget->category.name = categoryName.toStdString();
    }
}


