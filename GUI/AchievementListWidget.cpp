//
// Created by trashpanda on 26.05.23.
//

#include "AchievementListWidget.h"
#include "AchievementWidget.h"
#include "CategoryWidget.h"

AchievementListWidget::AchievementListWidget(todolib::AchievementList &achievementList, QWidget *parent)
: achievements{achievementList} {

    setLayout(&vlayout);

    // List of Achievements
     for (todolib::Achievement &a : achievements.getAchievements()) {
         //std::shared_ptr<AchievementWidget> widget {std::make_shared<AchievementWidget>(a)};
         //vlayout.addWidget(widget.get(), 0, Qt::AlignTop);

         //vlayout.addWidget(new AchievementWidget(a), 0, Qt::AlignTop);


         QLabel test1 {QLabel()};
         test1.setText(QString::fromStdString("test1"));
         vlayout.addWidget(&test1, 0, Qt::AlignTop);
     }


    //todolib::Achievement x {"Achievement Name", "bla bla bla bla bla bla bla bla bla bla bla bla"};
    //vlayout.addWidget(new AchievementWidget(x), 0, Qt::AlignTop);



    QLabel test2 {QLabel()};
    test2.setText(QString::fromStdString("test2"));
    vlayout.addWidget(&test2, 0, Qt::AlignTop);
    //vlayout.addWidget(&test2, 1, Qt::AlignLeft | Qt::AlignVCenter);
}

void AchievementListWidget::addAchievementWidget(todolib::Achievement &task) {

}
