//
// Created by helen on 26.05.2023.
//

#include "MainWindow.h"
#include "MainPage.h"
#include <memory>
#include <QDebug>


MainWindow::MainWindow(todolib::ToDoList &todolist) : toDoList{todolist} {
    // MainPage automatically Added
    std::shared_ptr<Page> mainPage {std::make_shared<MainPage>(toDoList)};
    pages.push_back(mainPage);
    stackedLayout.addWidget(mainPage.get());

    connect(mainPage.get(), SIGNAL(openCategoryViewPageSignal()), this, SLOT(openCategoryViewPage()));


    resize(400, 400);
    setWindowTitle("To-Do List");
    show();
}

void MainWindow::openPage(const std::shared_ptr<Page>& newpage) {
    pages.push_back(newpage);
    stackedLayout.addWidget(newpage.get());
    stackedLayout.setCurrentIndex(stackedLayout.indexOf(newpage.get()));

    connect(newpage.get(), &Page::closePageSignal, this, [=, this]() {closePage(newpage);});
}

void MainWindow::closePage(const std::shared_ptr<Page>& page) {

    for (auto task : toDoList.showAllTasks()) {
        qDebug() << "MainWindow prä close window: " << QString::fromStdString(task.name) << ": " << ((task.getDoneStatus()) ? "true" : "false");
    }

    stackedLayout.removeWidget(page.get());
    pages.remove(page);

    for (auto task : toDoList.showAllTasks()) {
        qDebug() << "MainWindow post close window: " << QString::fromStdString(task.name) << ": " << ((task.getDoneStatus()) ? "true" : "false");
    }

}

void MainWindow::openCategoryViewPage() {
    std::shared_ptr<Page> newpage {std::make_shared<CategoryViewPage>(toDoList)};
    openPage(newpage);
    connect(newpage.get(), SIGNAL(refreshPage()), this, SLOT(refreshCategoryViewPage(newpage)));
}

void MainWindow::refreshCategoryViewPage(const std::shared_ptr<CategoryViewPage>& page) {
    closePage(page);
    openCategoryViewPage();
    qDebug() << "refresh";
}


