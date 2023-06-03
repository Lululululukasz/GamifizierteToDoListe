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
#include "AchievementListWidget.h"
#include "XpWidget.h"
#include <memory>
#include "Page.h"


class CategoryViewPage : public Page {

Q_OBJECT

signals:
    void xpWidgetSignal1();
    void xpWidgetSignal2();

public:
    explicit CategoryViewPage(todolib::ToDoList& toDoList);

private:
    QPushButton addCategoryButton {QPushButton("add a new category")};
    std::list<std::shared_ptr<CategoryWidget>> categoryWidgets;
    std::list<std::shared_ptr<XpWidget>> xpWidgets;
    void addCategory();
    void addCategoryWidget(todolib::Category& category);
    void deleteCategory(const std::shared_ptr<CategoryWidget>& categoryWidget);
    void addXpWidget(todolib::Xp& xp);
    void configCategory(const std::shared_ptr<CategoryWidget>& categoryWidget);
    todolib::Xp xp;
};


#endif //PIC_AEM_PROJEKT_TODOLISTWIDGET_H