//
// Created by Jan Ole Weighardt on 23.05.23.
//

#ifndef AEMPROJEKT_CATEGORYWIDGET_H
#define AEMPROJEKT_CATEGORYWIDGET_H

#include <memory>
#include <QVBoxLayout>
#include <QLabel>
#include <QApplication>
#include <QPushButton>
#include <QInputDialog>
#include <QWidget>
#include <QPushButton>
#include "GUI/popups/AddTaskBox.h"
#include "GUI/pages/Page.h"

#include "todolib/todolib.h"
#include "GUI/widgets/category-task/TaskWidget.h"
#include "GUI/popups/ConfirmDeleteWindow.h"

class CategoryWidget : public QWidget {

Q_OBJECT
public:
    explicit CategoryWidget(todolib::Category &category, todolib::TaskFilterParameter &taskFilterParameter, Page &page);

    todolib::Category &category;
    todolib::TaskFilterParameter &taskFilterParameter;

    void changeName(const QString &newName);

public slots:
    void filterTasks();

signals:
    void categoryDeleteSignal();
    void xpWidgetSignalAdd();
    void xpWidgetSignalSub();

    void categoryConfigSignal();

    void refreshPageWidgetSignal();

private slots:

    void openAddTaskWindow(bool checked);

    void saveToJson();

    void openConfirmDeleteWindow(const std::shared_ptr<TaskWidget> taskWidget);
    void deleteTask( std::shared_ptr<TaskWidget> taskWidget);
private:
    QVBoxLayout vlayout{QVBoxLayout()};
    QHBoxLayout hlayout{QHBoxLayout()};
    QLabel name{QLabel()};
    QPushButton deleteButton{QPushButton()};
    QPushButton confButton{QPushButton()};
    std::list<std::shared_ptr<TaskWidget>> taskWidgets;
    Page &page;

    void addTaskWidget(todolib::Task &task);

    void configCategory();

    void deleteCategory();

    std::shared_ptr<ConfirmDeleteWindow> confirmDeleteWindow;

public:
    // Adding Tasks
    std::shared_ptr<QPushButton> addTaskButton;
    std::shared_ptr<AddTaskBox> addTaskBox;

    void addTask(todolib::Task &task);
};

#endif //AEMPROJEKT_CATEGORYWIDGET_H
