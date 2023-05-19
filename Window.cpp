#include "Window.h"

#include <QPushButton>
#include <QApplication>

Window::Window(QWidget *parent) : QWidget(parent) {
    setFixedSize(1400, 800);
    mainList = todolib::ToDoList();

    taskButton = new QPushButton("Add Task", this);
    taskButton->setGeometry(10, 100, 80, 30);
    taskButton->setCheckable(true);

    connect(taskButton, SIGNAL(clicked(bool)), this, SLOT (openNewWindow(bool)));
}

void Window::openNewWindow(bool checked){
    if(checked) {
        this->taskButton->setChecked(false);
        taskBox = new AddTaskBox();
        taskBox->setmainList(mainList);//dosnt work.
        taskBox->show();
    }
}

todolib::ToDoList Window::getList(){
    return this->mainList;
}