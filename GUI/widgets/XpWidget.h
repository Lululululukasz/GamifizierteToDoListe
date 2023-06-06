//
// Created by Jan Ole Weighardt on 26.05.23.
//

#ifndef AEMPROJEKT_XPWIDGET_H
#define AEMPROJEKT_XPWIDGET_H
#include <QWidget>
#include "todolib/todolib.h"
#include <QProgressBar>
#include <QLabel>
#include <QHBoxLayout>

// This class is here to calculate and show the Xp Progress


class XpWidget : public QWidget {
    Q_OBJECT
    public:
        explicit XpWidget( todolib::Xp &xp,QWidget *parent = nullptr);
    todolib::Xp &xp;


public slots:
    void xpWidgetFuncAdd();
    void xpWidgetFuncSub();

    private:
        std::shared_ptr<QLabel> xpLabel;
        std::shared_ptr<QHBoxLayout> xpLayout;
        std::shared_ptr<QProgressBar>progressBar;
        void levelUp();
        unsigned int levelcap{xp.levelNumber};
         std::string currrentLevel{"Level: " + std::to_string(xp.levelNumber)};
    };



#endif //AEMPROJEKT_XPWIDGET_H
