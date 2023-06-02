//
// Created by helen on 26.05.2023.
//

#ifndef PIC_AEM_PROJEKT_MAINWINDOW_H
#define PIC_AEM_PROJEKT_MAINWINDOW_H

#include <QStackedLayout>
#include <QWidget>
#include "todolib/todolib.h"
#include "GUI/pages/CategoryViewPage.h"


/**
 * MainWindow
 *
 * The window including the different pages of the program.
 * Each Type of Page needs a slot to open the page and a button that sends a signal to open the page on the MainPage.
 */
class MainWindow : public QWidget {

Q_OBJECT

public:
    MainWindow(todolib::Profile &profile);

public slots:
/**
 * openCategoryViewPage
 * creates a shared pointer to a categoryViewPage and feeds it to the openPage() function
 */ // das würde ein Template sein wenn es ginge
    void openCategoryViewPage();
    void openAchievementsPage(); // same function for Achievements Page



private:
    //todolib::ToDoList &toDoList;
    todolib::Profile &profile;
    QStackedLayout stackedLayout{QStackedLayout(this)};
    std::list<std::shared_ptr<Page>> pages;

    /**
     * openPage
     * opens a Page and connects it to the closePage function
     * @param newpage shared Pointer to the new Page (Page can be of a child of Page)
     */
    void openPage(const std::shared_ptr<Page>& newpage);
    void closePage(const std::shared_ptr<Page>& page);
    void refreshCategoryViewPage(const std::shared_ptr<Page>& newpage);
};


#endif //PIC_AEM_PROJEKT_MAINWINDOW_H
