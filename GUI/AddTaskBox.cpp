#include "AddTaskBox.h"

#include <QPushButton>
#include <QTextEdit>
#include <QApplication>

AddTaskBox::AddTaskBox(QWidget *parent) : QWidget(parent), task(todolib::Task("", "")){

    setFixedSize(400, 200);

    aTNameTextEdit = std::make_shared<QTextEdit>(this);
    aTNameTextEdit->setGeometry(10, 10, 100, 30);

    aTDecriptionTextEdit = std::make_shared<QTextEdit>(this);
    aTDecriptionTextEdit->setGeometry(10, 40, 200, 60);

    addTaskButton = std::make_shared<QPushButton>("Add Task", this);
    addTaskButton->setGeometry(10, 100, 80, 30);
    addTaskButton->setCheckable(true);

    connect(addTaskButton.get(), SIGNAL (clicked(bool)), this, SLOT (addTaskClicked(bool)));
    connect(this, SIGNAL (isOver()), this, SLOT (closeAddTaskWindow()));
}

void AddTaskBox::setCategory(todolib::Category &category){
    this->category = std::make_shared<todolib::Category>(category);
}

void AddTaskBox::addTaskClicked(bool checked)
{
    if (checked) {
        this->addTaskButton->setChecked(false);
        std::string name{this->aTNameTextEdit->toPlainText().toStdString()};
        std::string description{this->aTDecriptionTextEdit->toPlainText().toStdString()};
        // category->addTask(todolib::Task(name, description));
        task = todolib::Task(name, description);
        hasTaskBool = true;
        emit isOver();
    }
}

bool AddTaskBox::hasTask() {
    return hasTaskBool;
}

void AddTaskBox::closeAddTaskWindow() {
    this->hide();
}
