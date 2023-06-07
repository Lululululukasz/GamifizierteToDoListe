//
// Created by Jan Ole Weighardt on 23.05.23.
//

#ifndef AEMPROJEKT_CATEGORYWIDGET_H
#define AEMPROJEKT_CATEGORYWIDGET_H

#include "todolib/todolib.h"
#include "TaskWidget.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QApplication>
#include <QPushButton>
#include <QInputDialog>
#include <QWidget>
#include <QPushButton>
#include "GUI/popups/AddTaskBox.h"
#include "GUI/pages/Page.h"


class CategoryWidget : public QWidget {

Q_OBJECT


public:
    explicit CategoryWidget(todolib::Category &category, Page &page, QWidget *parent = nullptr);

    todolib::Category &category;

    void changeName(const QString &newName);

signals:

    void categoryDeleteSignal();
    void xpWidgetSignalAdd();
    void xpWidgetSignalSub();

    void categoryConfigSignal();

    void refreshPageWidgetSignal();

private slots:

    void openAddTaskWindow(bool checked);

    void saveToJson();

private:
    QVBoxLayout vlayout{QVBoxLayout()};
    QHBoxLayout hlayout{QHBoxLayout()};
    QLabel name{QLabel()};
    QPushButton deleteButton{QPushButton()};
    QPushButton confButton{QPushButton()};
    std::list<std::shared_ptr<TaskWidget>> TaskWidgets;
    Page &page;

    void addTaskWidget(todolib::Task &task);

    void configCategory();

    void deleteCategory();

    void deleteTask(const std::shared_ptr<TaskWidget> &taskWidget);

    // Adding Tasks
    std::shared_ptr<QPushButton> addTaskButton;
    std::shared_ptr<AddTaskBox> addTaskBox;

    void addTask(todolib::Task &task);

};

#endif //AEMPROJEKT_CATEGORYWIDGET_H
