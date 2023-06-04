//
// Created by Jan Ole Weighardt on 23.05.23.
//

#include "GUI/CategoryWidget.h"
#include "todolib/todolib.h"
#include "GUI/TaskWidget.h"
#include "GUI/ConfirmDeleteWindow.h"

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QWidget>
#include <QStyle>

using namespace todolib;

CategoryWidget::CategoryWidget(todolib::Category &category, QWidget *parent) : category{category}, QWidget(parent) {
    setLayout(&vlayout);
    vlayout.addLayout(&hlayout);

    // Title
    name.setText(QString::fromStdString(category.name));
    hlayout.addWidget(&name, 1, Qt::AlignLeft | Qt::AlignVCenter);

    // Category Delete Button
    deleteButton.setText("  Delete");
    deleteButton.setIcon(deleteButton.style()->standardIcon(QStyle::SP_TrashIcon));
    hlayout.addWidget(&deleteButton, 0, Qt::AlignRight | Qt::AlignVCenter);
    connect(&deleteButton, &QPushButton::clicked, this, [=, this]() { deleteCategory(); });

    //Add Task Button
    addTaskButton = std::make_shared<QPushButton>("Add Task", this);
    addTaskButton->setGeometry(10, 100, 80, 30);
    addTaskButton->setCheckable(true);
    connect(addTaskButton.get(), SIGNAL(clicked(bool)), this, SLOT (openAddTaskWindow(bool)));
    vlayout.addWidget(addTaskButton.get());

    // List of Tasks
    for (Task &task: category.tasks) {
        addTaskWidget(task);
    }


}

void CategoryWidget::deleteCategory() {
    emit categoryDeleteSignal();
}

void CategoryWidget::addTask(Task &task) {
    category.addTask(task);
    addTaskWidget(task);
}

void CategoryWidget::addTaskWidget(Task &task) {
    shared_ptr<TaskWidget> widget {make_shared<TaskWidget>(task)};
    TaskWidgets.push_back(widget);
    vlayout.addWidget(widget.get(), 0, Qt::AlignTop);
    connect(widget.get(), &TaskWidget::deleteTaskSignal, confirmDeleteWindow, &ConfirmDeleteWindow::catchDeleteTask);
    //connect(widgetA, &WidgetAType::widgetASignal, widgetB, &WidgetBType::widgetBSlot);
}

void CategoryWidget::openAddTaskWindow(bool checked){
    if(checked) {
        this->addTaskButton->setChecked(false);
        addTaskBox = std::make_shared<AddTaskBox>();
        addTaskBox->setCategory(category);
        addTaskBox->show();
        connect(addTaskBox.get(), &AddTaskBox::isOver, this, [=, this]() {if(addTaskBox->hasTask()) { addTask(addTaskBox->task);};});
    }
}
ConfirmDeleteWindow::ConfirmDeleteWindow() {
    connect(this, &ConfirmDeleteWindow::confirmInput, categoryWidget, &CategoryWidget::catchConfirmDelete);
}

void CategoryWidget::catchConfirmDelete() {
    deleteTask(const std::shared_ptr<TaskWidget> &taskWidget);
}

void CategoryWidget::deleteTask(const std::shared_ptr<TaskWidget> &taskWidget) {
    category.deleteTask(taskWidget->task.getID());
    taskWidget->hide();
    vlayout.removeWidget(taskWidget.get());
    TaskWidgets.remove(taskWidget);
}