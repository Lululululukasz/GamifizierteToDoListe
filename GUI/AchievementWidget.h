//
// Created by trashpanda on 26.05.23.
//

#ifndef PIC_AEM_PROJEKT_ACHIEVEMENTWIDGET_H
#define PIC_AEM_PROJEKT_ACHIEVEMENTWIDGET_H


#include "todolib/todolib.h"
#include "AchievementWidget.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QIcon>

class AchievementWidget : public QWidget {

    Q_OBJECT

public:
    explicit AchievementWidget(todolib::Achievement &achievement, QWidget *parent = nullptr);

private:
    QVBoxLayout vlayout {QVBoxLayout()};
    QHBoxLayout hlayout {QHBoxLayout()};

    QLabel achievementName {QLabel()};
    QLabel achievementDescription {QLabel()};
    QLabel achievementIcon {QLabel()};

// TODO: Quelle des icons (resources/konfetti.png) angeben in der readme
// https://www.flaticon.com/de/kostenloses-icon/konfetti_5016950?term=celebration&page=1&position=6&origin=search&related_id=5016950
// <a href="https://www.flaticon.com/de/kostenlose-icons/feier" title="feier Icons">Feier Icons erstellt von Good Ware - Flaticon</a>

};

#endif //PIC_AEM_PROJEKT_ACHIEVEMENTWIDGET_H
