//
// Created by helen on 23.05.2023.
//

#ifndef PIC_AEM_PROJEKT_TODOLISTWIDGET_H
#define PIC_AEM_PROJEKT_TODOLISTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QInputDialog>
#include <QLabel>
#include "TaskWidget.h"
#include "todolib/todolib.h"
#include "CategoryWidget.h"
#include <memory>


class ToDoListWindow : public QWidget {

Q_OBJECT

public:
    explicit ToDoListWindow(todolib::ToDoList& toDoList, QWidget *parent = nullptr);

private:
    todolib::ToDoList& toDoList;
    QPushButton addCategoryButton {QPushButton("add a new category")};
    QVBoxLayout layout {QVBoxLayout(this)};
    std::list<std::shared_ptr<CategoryWidget>> categoryWidgets;
    void addCategory();
    void addCategoryWidget(todolib::Category& category);
    void deleteCategory(const std::shared_ptr<CategoryWidget>& categoryWidget);
    void configCategory(const std::shared_ptr<CategoryWidget>& categoryWidget);
};


#endif //PIC_AEM_PROJEKT_TODOLISTWIDGET_H