//
// Created by helen on 26.05.2023.
//

#include "MainWindow.h"
#include "MainPage.h"
#include <memory>


MainWindow::MainWindow(todolib::ToDoList &todolist) : toDoList{todolist} {
    std::shared_ptr<Page> mainPage {std::make_shared<MainPage>(toDoList)};
    pages.push_back(mainPage);
    stackedLayout.addWidget(mainPage.get());

    connect(mainPage.get(), SIGNAL(openCategoryViewPageSignal()), this, SLOT(openCategoryViewPage()));

    resize(400, 400);
    setWindowTitle("To-Do List");
    show();
}

void MainWindow::openCategoryViewPage() {
    std::shared_ptr<Page> newpage {std::make_shared<CategoryViewPage>(toDoList)};
    pages.push_back(newpage);
    stackedLayout.addWidget(newpage.get());
    stackedLayout.setCurrentIndex(stackedLayout.indexOf(newpage.get()));
}


