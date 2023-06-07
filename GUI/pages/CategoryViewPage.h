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
#include <optional>
#include "Page.h"
#include "MainPage.h"

class CategoryViewPage : public MainPage {

Q_OBJECT

signals:
    void xpWidgetSignalAdd();
    void xpWidgetSignalSub();

public:
    explicit CategoryViewPage(todolib::Profile & profile);

private:
    QPushButton addCategoryButton {QPushButton("add a new category")};
    std::list<std::shared_ptr<CategoryWidget>> categoryWidgets;
    std::shared_ptr<QInputDialog> categoryNameInputDialog;
    std::shared_ptr<QInputDialog> categoryConfig;
    std::optional<QString> invalidCategoryName();
    std::optional<QString> getCategoryName();
    void addCategory();
    void addCategoryWidget(todolib::Category& category);
    void deleteCategory(const std::shared_ptr<CategoryWidget>& categoryWidget);
    void configCategory(const std::shared_ptr<CategoryWidget>& categoryWidget);
};


#endif //PIC_AEM_PROJEKT_TODOLISTWIDGET_H