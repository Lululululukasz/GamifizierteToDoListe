#include "Window.h"

#include <QPushButton>
#include <QApplication>

Window::Window(QWidget *parent) : QWidget(parent) {
    setFixedSize(1400, 800);
    mainList = std::shared_ptr<todolib::ToDoList>();

    taskButton = std::make_shared<QPushButton>("Add Task", this);
    taskButton->setGeometry(10, 100, 80, 30);
    taskButton->setCheckable(true);

    connect(taskButton.get(), SIGNAL(clicked(bool)), this, SLOT (openNewWindow(bool)));
}

void Window::openNewWindow(bool checked){
    if(checked) {
        this->taskButton->setChecked(false);
        taskBox = std::make_shared<AddTaskBox>();
        auto mainListPtr = std::shared_ptr<todolib::ToDoList>(mainList);
        taskBox->setmainList(mainListPtr);
        taskBox->show();
    }
}
