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
#include "GUI/widgets/category-task/TaskWidget.h"
#include "todolib/todolib.h"
#include "GUI/widgets/category-task/CategoryWidget.h"
#include "GUI/widgets/achievement/AchievementListWidget.h"
#include <memory>
#include "Page.h"


class CategoryViewPage : public Page {

Q_OBJECT

signals:
    void xpWidgetSignal1();
    void xpWidgetSignal2();

public:
    explicit CategoryViewPage(todolib::Profile & profile);

private:
    QPushButton addCategoryButton {QPushButton("add a new category")};
    std::list<std::shared_ptr<CategoryWidget>> categoryWidgets;
    std::shared_ptr<QInputDialog> categoryName;
    std::shared_ptr<QInputDialog> categoryConfig;
    QString invalidCategoryName();
    void addCategory();
    void addCategoryWidget(todolib::Category& category);
    void deleteCategory(const std::shared_ptr<CategoryWidget>& categoryWidget);
    void configCategory(const std::shared_ptr<CategoryWidget>& categoryWidget);
};


#endif //PIC_AEM_PROJEKT_TODOLISTWIDGET_H