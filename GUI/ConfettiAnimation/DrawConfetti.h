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

/**
 * This draws a set of confettos (sometimes also called "confetti") to the widget.
 * The confettos are rocketed upwards and fall down by gravitation.
 */
class DrawConfetti : public QWidget {
    Q_OBJECT

public:
    /**
     * Create a DrawConfetti object.
     */
    explicit DrawConfetti();

    [[nodiscard]] QSize minimumSizeHint() const override;
    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

public slots:
    /**
     * Moves the confettos by one step.
     * This is triggered every 10 msecs by a timer.
     * After that, it updates the screen with the new positions.
     */
    void updateAnimation();

protected:
    /** List of managed confettos */
    std::list<Confetto> confettos;

    /**
     * Returns a random color.
     *
     * @return A random color
     */
    static QColor generateColor();

};


#endif //PIC_AEM_PROJEKT_DRAWCONFETTI_H
