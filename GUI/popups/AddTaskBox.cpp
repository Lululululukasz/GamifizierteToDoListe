#include "AddTaskBox.h"

#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QApplication>

AddTaskBox::AddTaskBox(QWidget *parent) : QWidget(parent), task(todolib::Task("", "")) {

    setFixedSize(400, 200);

    nameLabel.setText(QString::fromStdString("Task Name: "));
    layout.addWidget(&nameLabel);
    aTNameTextEdit = std::make_shared<QTextEdit>(this);
    aTNameTextEdit->setGeometry(10, 10, 100, 10);
    layout.addWidget(aTNameTextEdit.get());

    descLabel.setText(QString::fromStdString("Task Description: "));
    layout.addWidget(&descLabel);
    aTDecriptionTextEdit = std::make_shared<QTextEdit>(this);
    aTDecriptionTextEdit->setGeometry(10, 40, 200, 60);
    layout.addWidget(aTDecriptionTextEdit.get());

    addTaskButton = std::make_shared<QPushButton>("Add Task", this);
    addTaskButton->setGeometry(10, 100, 80, 30);
    addTaskButton->setCheckable(true);
    layout.addWidget(addTaskButton.get());

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

bool AddTaskBox::hasTask() const {
    return hasTaskBool;
}

void AddTaskBox::closeAddTaskWindow() {
    this->hide();
}
