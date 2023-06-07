//
// Created by vera on 03.06.23.
//

#include <QLayout>
#include "PageLayoutWidget.h"

PageLayoutWidget::PageLayoutWidget() {
    this->setLayout(vOuterLayout.get());



    vOuterLayout->addLayout(hNavBar.get());
    vOuterLayout->addLayout(hOuterBodyLayout.get());
    hOuterBodyLayout->addLayout(vSideBar.get(), 1);
    vSideBar->setAlignment(Qt::AlignTop);
    hOuterBodyLayout->addLayout(vBodyLayout.get(), 3);
    vBodyLayout->setAlignment(Qt::AlignTop);
}


