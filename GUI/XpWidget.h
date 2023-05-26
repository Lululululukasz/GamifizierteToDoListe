//
// Created by Jan Ole Weighardt on 26.05.23.
//

#ifndef AEMPROJEKT_XPWIDGET_H
#define AEMPROJEKT_XPWIDGET_H
#include <QWidget>
#include "todolib/todolib.h"
#include <QLabel>
#include <QVBoxLayout>



class XpWidget : public QWidget {
    Q_OBJECT
    public:
        explicit XpWidget( QWidget *parent = nullptr);
    private:
        std::shared_ptr<QLabel> xpLabel;
        std::shared_ptr<QVBoxLayout> xpLayout;
    };



#endif //AEMPROJEKT_XPWIDGET_H
