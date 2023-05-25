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
#include "AddTaskBox.h"


class CategoryWidget : public QWidget {

Q_OBJECT


public:
    explicit CategoryWidget(todolib::Category &category, QWidget *parent = nullptr);

    todolib::Category &category;

signals:

    void categoryDeleteSignal();

private slots:
    void openAddTaskWindow(bool checked);

private:
    QVBoxLayout vlayout {QVBoxLayout()};
    QHBoxLayout hlayout {QHBoxLayout()};
    QLabel name {QLabel()};
    QPushButton deleteButton {QPushButton()};
    std::list<std::shared_ptr<TaskWidget>> TaskWidgets;
    void addTaskWidget(todolib::Task& task);
    void deleteCategory();
    void deleteTask(const std::shared_ptr<TaskWidget>& taskWidget);

    // Adding Tasks
    std::shared_ptr<QPushButton> addTaskButton;
    std::shared_ptr<AddTaskBox> addTaskBox;
    void addTask(todolib::Task &task);

};

#endif //AEMPROJEKT_CATEGORYWIDGET_H
