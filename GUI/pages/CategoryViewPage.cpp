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

CategoryViewPage::CategoryViewPage(todolib::Profile &profile) : MainPage{profile} {
    layoutWidget.vBodyLayout->addWidget(&addCategoryButton, 0,Qt::AlignTop);
CategoryViewPage::CategoryViewPage(todolib::Profile &profile) : Page{profile} {
    layoutWidget.vOuterLayout->addWidget(&addCategoryButton);
    connect(&addCategoryButton, &QPushButton::clicked, this, &CategoryViewPage::addCategory);
    addCategoryButton.setGeometry(10, 100, 80, 30);
    for (Category &category: profile.todoList.categories) {
        addCategoryWidget(category);
    }

}

optional<QString> CategoryViewPage::getCategoryName() {
    categoryNameInputDialog = std::make_shared<QInputDialog>();
    bool ok;
    QString categoryNameInput = categoryNameInputDialog->getText(this, "New Category", "enter the category name", QLineEdit::Normal, QString(), &ok);
    if(!ok) {
        return {};
    }
    return categoryNameInput.isEmpty() ? invalidCategoryName() : categoryNameInput;
}

void CategoryViewPage::addCategory() {
    auto categoryNameValue {getCategoryName()};
    if (!categoryNameValue.has_value()) {
        return;
    }
    auto categoryName {categoryNameValue.value()};
    Category category = Category(categoryName.toStdString());
    profile.todoList.addCategory(category);
    addCategoryWidget(profile.todoList.categories.back());
}



void CategoryViewPage::addCategoryWidget(Category& category) {
    shared_ptr<CategoryWidget> widget {make_shared<CategoryWidget>(category, *this)};
    categoryWidgets.push_back(widget);
    layoutWidget.vBodyLayout->addWidget(widget.get(), 0, Qt::AlignTop);
    connect(widget.get(), &CategoryWidget::categoryDeleteSignal, this, [=, this]() { deleteCategory(widget); });
    layoutWidget.vOuterLayout->addWidget(widget.get(), 0, Qt::AlignTop);
    connect(widget.get(), &CategoryWidget::categoryDeleteSignal, this, [=, this]() { openConfirmDeleteWindow(widget); });
    //connect(widget.get(), &CategoryWidget::categoryDeleteSignal, this, [=, this]() { deleteCategory(widget); });
    connect(widget.get(), &CategoryWidget::xpWidgetSignalAdd, this, &Page::xpWidgetSignalAdd);
    connect(widget.get(), &CategoryWidget::xpWidgetSignalSub, this, &Page::xpWidgetSignalSub);
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
    categoryConfig = std::make_shared<QInputDialog>();
    categoryConfig->setLabelText("Enter a new category name");
    categoryConfig->setWindowTitle("Edit category");
    categoryConfig->setTextValue(QString::fromStdString(categoryWidget->category.getName()));
    categoryConfig->exec();
    QString categoryNameEdited =categoryConfig->textValue();
    if (!categoryNameEdited.isEmpty()) {
        categoryWidget->changeName(categoryNameEdited);
        categoryWidget->category.name = categoryNameEdited.toStdString();
    }
}

optional<QString> CategoryViewPage::invalidCategoryName() {
    QString categoryNameInput;
    categoryNameInputDialog->setWindowTitle("New category");
    categoryNameInputDialog->setLabelText("Please enter a category name!");
    categoryNameInputDialog->setStyleSheet("QLabel{color: red;}");
    auto result {categoryNameInputDialog->exec()};
    categoryNameInput = categoryNameInputDialog->textValue();
    if(categoryNameInput.length() == 0 && result == QDialog::Accepted) {
        return invalidCategoryName();
    } else if(categoryNameInput.length() == 0) {
        return {};
    } else {
        return categoryNameInput;
    }
}
void CategoryViewPage::openConfirmDeleteWindow(std::shared_ptr<CategoryWidget> categoryWidget) {
    confirmDeleteWindow = std::make_shared<ConfirmDeleteWindow>();
    connect(confirmDeleteWindow.get(), &ConfirmDeleteWindow::confirmDelete, this, [=, this]() { deleteCategory(categoryWidget);});
}