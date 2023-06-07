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

#include "todolib/todolib.h"
#include "TaskWidget.h"
#include "AddTaskBox.h"
#include "ConfirmDeleteWindow.h"


class CategoryWidget : public QWidget {

Q_OBJECT


public:
    explicit CategoryWidget(todolib::Category &category, QWidget *parent = nullptr);
    todolib::Category &category;

signals:

    void categoryDeleteSignal();

public slots:
    //void catchConfirmDelete();

private slots:
    void openAddTaskWindow(bool checked);
    bool openConfirmDeleteWindow(const std::shared_ptr<TaskWidget> taskWidget);
private:
    QVBoxLayout vlayout {QVBoxLayout()};
    QHBoxLayout hlayout {QHBoxLayout()};
    QLabel name {QLabel()};
    QPushButton deleteButton {QPushButton()};
    std::list<std::shared_ptr<TaskWidget>> TaskWidgets;
    void addTaskWidget(todolib::Task& task);
    void deleteCategory();
    std::shared_ptr<ConfirmDeleteWindow> confirmDeleteWindow;

public:
    void deleteTask(const std::shared_ptr<TaskWidget> taskWidget);
    // Adding Tasks
    std::shared_ptr<QPushButton> addTaskButton;
    std::shared_ptr<AddTaskBox> addTaskBox;
    void addTask(todolib::Task &task);


};

#endif //AEMPROJEKT_CATEGORYWIDGET_H
