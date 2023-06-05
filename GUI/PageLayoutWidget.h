//
// Created by vera on 03.06.23.
//

#ifndef PIC_AEM_PROJEKT_PAGELAYOUTWIDGET_H
#define PIC_AEM_PROJEKT_PAGELAYOUTWIDGET_H


#include <QWidget>

class PageLayoutWidget : public QWidget {
public:
    PageLayoutWidget();

    std::shared_ptr<QVBoxLayout> vOuterLayout {std::make_shared<QVBoxLayout>()};
    std::shared_ptr<QHBoxLayout> hNavBar {std::make_shared<QHBoxLayout>()};
    std::shared_ptr<QHBoxLayout> hOuterBodyLayout {std::make_shared<QHBoxLayout>()};
    std::shared_ptr<QVBoxLayout> vSideBar {std::make_shared<QVBoxLayout>()};
    std::shared_ptr<QVBoxLayout> vBodyLayout {std::make_shared<QVBoxLayout>()};
};


#endif //PIC_AEM_PROJEKT_PAGELAYOUTWIDGET_H
