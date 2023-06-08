//
// Created by helen on 26.05.2023.
//

#include "MainWindow.h"
#include "GUI/pages/MainPage.h"
#include "GUI/pages/AchievementsPage.h"
#include <memory>
#include <QDebug>


MainWindow::MainWindow(todolib::Profile &profile) : profile{profile} {
    /*
    // MainPage automatically Added
    std::shared_ptr<Page> mainPage {std::make_shared<MainPage>(profile)};
    pages.push_back(mainPage);
    stackedLayout.addWidget(mainPage.get());

    connect(mainPage.get(), SIGNAL(openCategoryViewPageSignal()), this, SLOT(openCategoryViewPage()));
    connect(mainPage.get(), SIGNAL(openAchievementsPageSignal()), this, SLOT(openAchievementsPage()));

     */

    openCategoryViewPage();

    resize(1280, 720);
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
    profile.taskFilterParameter.clear();
    std::shared_ptr<Page> newpage {std::make_shared<CategoryViewPage>(profile)};
    openPage(newpage);
    connect(newpage.get(), &Page::refreshPageSignal, this, [=, this]() {refreshCategoryViewPage(newpage);});
    connect(newpage.get(), SIGNAL(openAchievementsPageSignal()), this, SLOT(openAchievementsPage()));
}

void MainWindow::openAchievementsPage() {
    std::shared_ptr<Page> newPage {std::make_shared<AchievementsPage>(profile)};
    openPage(newPage);
} // TODO apply same fix as category

void MainWindow::refreshCategoryViewPage(const std::shared_ptr<Page>& page) {
    closePage(page);
    openCategoryViewPage();
    if (Globals::debug) {
        qDebug() << "refresh";
    }
}


