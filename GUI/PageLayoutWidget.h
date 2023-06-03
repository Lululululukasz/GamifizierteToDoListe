//
// Created by vera on 03.06.23.
//

#ifndef PIC_AEM_PROJEKT_PAGELAYOUTWIDGET_H
#define PIC_AEM_PROJEKT_PAGELAYOUTWIDGET_H


#include <QWidget>

class PageLayoutWidget : public QWidget {
public:
    PageLayoutWidget(std::shared_ptr<QLayout> layout);
};


#endif //PIC_AEM_PROJEKT_PAGELAYOUTWIDGET_H
