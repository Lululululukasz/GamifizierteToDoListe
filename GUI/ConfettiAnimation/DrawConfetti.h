//
// Created by vera on 31.05.23.
//

#ifndef PIC_AEM_PROJEKT_DRAWCONFETTI_H
#define PIC_AEM_PROJEKT_DRAWCONFETTI_H

#include <QPainter>
#include <memory>
#include <QWidget>
#include <QPaintEvent>
#include <QPropertyAnimation>
#include "Confetto.h"

class DrawConfetti : public QWidget {
    Q_OBJECT

public:
    explicit DrawConfetti();
    QSize minimumSizeHint() const override;
    void paintEvent(QPaintEvent *event) override;

public slots:
    void updateAnimation();

protected:
    std::list<Confetto> confettos;
    static QColor generateColor();

};


#endif //PIC_AEM_PROJEKT_DRAWCONFETTI_H
