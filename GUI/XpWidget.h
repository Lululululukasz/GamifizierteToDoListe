//
// Created by Jan Ole Weighardt on 26.05.23.
//

#ifndef AEMPROJEKT_XPWIDGET_H
#define AEMPROJEKT_XPWIDGET_H
#include <QWidget>
#include "todolib/todolib.h"
#include "CategoryWidget.h"
#include <QLabel>
#include <QVBoxLayout>
// This class is here to calculate and show the Xp Progress


class XpWidget : public QWidget {
    Q_OBJECT
    public:
        explicit XpWidget( todolib::Xp &xp,QWidget *parent = nullptr);
    todolib::Xp &xp;

    int xpWidgetNumber {55};

public slots:
    void xpWidgetFunc1();
    void xpWidgetFunc2();

    private:
        std::shared_ptr<QLabel> xpLabel;
        std::shared_ptr<QVBoxLayout> xpLayout;
        void xpFirstNumber();
    };



#endif //AEMPROJEKT_XPWIDGET_H
