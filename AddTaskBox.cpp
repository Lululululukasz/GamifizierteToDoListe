#include "AddTaskBox.h"

#include <QPushButton>
#include <QTextEdit>
#include <QApplication>

AddTaskBox::AddTaskBox(QWidget *parent) : QWidget(parent){
    setFixedSize(400, 200);

    aTNameTextEdit = std::make_shared<QTextEdit>(this);
    aTNameTextEdit->setGeometry(10, 10, 100, 30);

    aTDecriptionTextEdit = std::make_shared<QTextEdit>(this);
    aTDecriptionTextEdit->setGeometry(10, 40, 200, 60);

    addTaskButton = std::make_shared<QPushButton>("Add Task", this);
    addTaskButton->setGeometry(10, 100, 80, 30);
    addTaskButton->setCheckable(true);

    connect(addTaskButton.get(), SIGNAL (clicked(bool)), this, SLOT (addTaskClicked(bool)));
    connect(this, SIGNAL (isOver()), QApplication::instance(), SLOT (quit()));
}

void AddTaskBox::setmainList(std::shared_ptr<todolib::ToDoList> &list){
    this->mainList = list;
}

void AddTaskBox::addTaskClicked(bool checked)
{
    if (checked) {
        this->addTaskButton->setChecked(false);
        std::string name{this->aTNameTextEdit->toPlainText().toStdString()};
        std::string description{this->aTDecriptionTextEdit->toPlainText().toStdString()};
        mainList->getCategoryByName("General").addTask(todolib::Task(name, description));
        mainList->showAllTasks();
        emit isOver();
    }
}