#ifndef PIC_AEM_PROJEKT_CONFETTO_H
#define PIC_AEM_PROJEKT_CONFETTO_H

#include <array>
#include <QPoint>
#include <QColor>

/**
 * This represents a single confetto with its movement math stuff.
 */
class Confetto {

private:
    /** X position of the confetto */
    double x;
    /** Y position of the confetto */
    double y;
    /** Width of the confetto */
    double width;
    /** Height of the confetto */
    double height;
    /** Rotation angle of the confetto */
    double angle;
    /** Horizontal speed (v_x) of the confetto. Negative values move to the left */
    double vx;
    /** Vertical speed (v_y) of the confetto. Negative values move to the top */
    double vy;
    /** Rotation speed (clockwise) of the confetto */
    double vrot;
    /** Color of the confetto */
    QColor color;

public:
    /**
     * Creates a confetto.
     *
     * @param x X position
     * @param y Y position
     * @param width Width
     * @param height Height
     * @param angle Angle
     * @param vx Horizontal speed (negative = left, positive = right)
     * @param vy Vertical speed (negative = top, positive = bottom)
     * @param vrot Rotation speed (clockwise)
     * @param color Color
     */
    Confetto(double x, double y, double width, double height, double angle, double vx, double vy, double vrot, QColor color);

    /**
     * Move the confetto by the given speed (scaled down by factor 0.15).
     */
    void moveStep();

    /**
     * Get the boundaries of the confetto.
     *
     * @return Four vertices of the confetto in a vector
     */
    [[nodiscard]] QVector<QPoint> getBoundaries() const;

    /**
     * Get the color of the confetto.
     *
     * @return Color of the confetto
     */
    [[nodiscard]] QColor getColor() const;

};


#endif //PIC_AEM_PROJEKT_CONFETTO_H
