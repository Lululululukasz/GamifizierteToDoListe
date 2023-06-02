//
// Created by helen on 26.05.2023.
//

#include "MainWindow.h"
#include "MainPage.h"
#include "AchievementsPage.h"
#include <memory>
#include <QDebug>


MainWindow::MainWindow(todolib::ToDoList &todolist) : toDoList{todolist} {
    // MainPage automatically Added
    std::shared_ptr<Page> mainPage {std::make_shared<MainPage>(toDoList)};
    pages.push_back(mainPage);
    stackedLayout.addWidget(mainPage.get());

    connect(mainPage.get(), SIGNAL(openCategoryViewPageSignal()), this, SLOT(openCategoryViewPage()));
    connect(mainPage.get(), SIGNAL(openAchievementsPageSignal()), this, SLOT(openAchievementsPage()));


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
    stackedLayout.removeWidget(page.get());
    pages.remove(page);
}

void MainWindow::openCategoryViewPage() {
    std::shared_ptr<Page> newpage {std::make_shared<CategoryViewPage>(toDoList)};
    openPage(newpage);
    connect(newpage.get(), &Page::refreshPageSignal, this, [=, this]() {refreshCategoryViewPage(newpage);});
}

void MainWindow::openAchievementsPage() {
    std::shared_ptr<Page> newPage {std::make_shared<AchievementsPage>(toDoList)};
    openPage(newPage);
} // TODO apply same fix as category

void MainWindow::refreshCategoryViewPage(const std::shared_ptr<Page>& page) {
    closePage(page);
    openCategoryViewPage();
    qDebug() << "refresh";
}


