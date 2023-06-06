//
// Created by helen on 30.05.2023.
//

#ifndef PIC_AEM_PROJEKT_PAGE_H
#define PIC_AEM_PROJEKT_PAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "todolib/todolib.h"
#include "GUI/PageLayoutWidget.h"
#include <QPushButton>
#include <memory>
#include <QStackedLayout>
#include <QLabel>
#include "GUI/widgets/XpWidget.h"

/**
 * Page
 * parent class for pages including a closeSignal, a vOuterLayout and a back button
 */
class Page : public QWidget {

Q_OBJECT

public:
    explicit Page(todolib::Profile& profile);
    void setOverlay(std::shared_ptr<QWidget> _overlay);
    void addXpWidget();
signals:
    void closePageSignal();
    void refreshPageSignal();
    void xpWidgetSignal1();
    void xpWidgetSignal2();

protected:
    todolib::Profile& profile ;
    PageLayoutWidget layoutWidget {PageLayoutWidget()};
    std::shared_ptr<QPushButton> closeButton {std::make_shared<QPushButton>()};
    QLabel placeholderXP {QLabel("XP Bar")};

private:
    QStackedLayout stackedLayout {QStackedLayout(this)};
    std::shared_ptr<QWidget> overlay;
    std::list<std::shared_ptr<XpWidget>> xpWidgets;

};


#endif //PIC_AEM_PROJEKT_PAGE_H
