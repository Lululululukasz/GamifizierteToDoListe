#include "Window.h"

#include <QPushButton>
#include <QTextEdit>
#include <QApplication>

Window::Window(QWidget *parent) : QWidget(parent){
    setFixedSize(400, 200);
    mainList = todolib::ToDoList();

    aTNameTextEdit = new QTextEdit(this);
    aTNameTextEdit->setGeometry(10, 10, 100, 30);

    aTDecriptionTextEdit = new QTextEdit(this);
    aTDecriptionTextEdit->setGeometry(10, 40, 200, 60);

    addTaskButton = new QPushButton("Add Task", this);
    addTaskButton->setGeometry(10, 100, 80, 30);
    addTaskButton->setCheckable(true);

    connect(addTaskButton, SIGNAL (clicked(bool)), this, SLOT (addTaskClicked(bool)));
}

void Window::addTaskClicked(bool checked)
{
    if (checked) {
        this->addTaskButton->setChecked(false);
        std::string name{this->aTNameTextEdit->toPlainText().toStdString()};
        std::string description{this->aTDecriptionTextEdit->toPlainText().toStdString()};
        mainList.getCategoryByName("General").addTask(todolib::Task(name, description));
        mainList.showAllTasks();
    }
}