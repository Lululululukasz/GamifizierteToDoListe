//
// Created by Jan Ole Weighardt on 23.05.23.
//

#include "CategoryWidget.h"
#include "todolib/todolib.h"
#include "TaskWidget.h"
#include "utility/Globals.h"

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QWidget>
#include <QStyle>

using namespace todolib;

CategoryWidget::CategoryWidget(todolib::Category &category, Page &page, QWidget *parent) : category{category},
                                                                                           page{page},
                                                                                           QWidget(parent) {
    setLayout(&vlayout);
    vlayout.addLayout(&hlayout);

    // Title
    name.setText(QString::fromStdString(category.name));
    hlayout.addWidget(&name, 1, Qt::AlignLeft | Qt::AlignVCenter);

    // Category Delete Button
    deleteButton.setText("  Delete");
    deleteButton.setIcon(deleteButton.style()->standardIcon(QStyle::SP_TrashIcon));
    hlayout.addWidget(&deleteButton, 0, Qt::AlignRight | Qt::AlignVCenter);
    connect(&deleteButton, &QPushButton::clicked, this, [&, this]() { deleteCategory(); });

    // Category Config Button
    confButton.setIcon(QIcon(Globals::homepath+"/resources/edit_icon.png"));
    hlayout.addWidget(&confButton, 0 , Qt::AlignRight | Qt::AlignVCenter);
    connect(&confButton, &QPushButton::clicked, this, [&, this]() {configCategory();});

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

void CategoryWidget::changeName(const QString &newName){
    name.setText(newName);
    category.setName(newName.toStdString());
}

void CategoryWidget::configCategory(){
    emit categoryConfigSignal();
}
void CategoryWidget::deleteCategory() {
    emit categoryDeleteSignal();
}

void CategoryWidget::addTask(Task &task) {
    category.addTask(task);
    emit refreshPageWidgetSignal();
    // addTaskWidget(task);
    // category.showTasks();
}

void CategoryWidget::addTaskWidget(Task &task) {
    shared_ptr<TaskWidget> widget {make_shared<TaskWidget>(task, page)};
    TaskWidgets.push_back(widget);
    vlayout.addWidget(widget.get(), 0, Qt::AlignTop);
    connect(widget.get(), &TaskWidget::deleteTaskSignal, this, [=, this]() { deleteTask(widget); });
    connect(widget.get(), &TaskWidget::taskMarkedChanged, this, &CategoryWidget::saveToJson);
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

void CategoryWidget::deleteTask(const std::shared_ptr<TaskWidget>& taskWidget) {
    category.deleteTask(taskWidget->task.getID());
    taskWidget->hide();
    vlayout.removeWidget(taskWidget.get());
    TaskWidgets.remove(taskWidget);
    //category.showTasks();
}

void CategoryWidget::saveToJson() {
    category.saveToJson();
}

