//
// Created by helen on 30.05.2023.
//

#ifndef PIC_AEM_PROJEKT_MAINPAGE_H
#define PIC_AEM_PROJEKT_MAINPAGE_H

#include "Page.h"
#include "todolib/todolib.h"
#include "GUI/widgets/filter/FilterWidget.h"
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <memory>
#include <QCheckBox>
#include <QRadioButton>

/**
 * MainPage
 * Default Base Page including buttons to open all other pages.
 * To add a new type of page it needs its own button and signal that are connected in the constructor.
 */
class MainPage : public Page {

Q_OBJECT

public:
    /**
     * MainPage Constructor
     * Adds and connects the button for each type of page.
     * @param toDoList
     */
    explicit MainPage(todolib::ToDoList &toDoList);

    signals:
    void openCategoryViewPageSignal();
    void openAchievementsPageSignal();

private:
    QLabel header {QLabel("Kontra Krastination")};
    QPushButton categoryViewPageButton{QPushButton("Open the Category View")};
    QPushButton achievementsPageButton{QPushButton("Open the Achievements Page")};

    std::shared_ptr<FilterWidget> filterWidget;

    QLabel placeholderSearchbar {QLabel("Searchbar")};
    QLabel placeholderBody {QLabel("Body")};
    QLabel placeholderFilter {QLabel("Filter")};
    QLabel placeholderAddButton {QLabel("AddButton")};

};


#endif //PIC_AEM_PROJEKT_MAINPAGE_H
