#ifndef PIC_AEM_PROJEKT_CONFETTO_H
#define PIC_AEM_PROJEKT_CONFETTO_H

#include <array>
#include <QPoint>
#include <QColor>

class Confetto {

private:
    double x;
    double y;
    double width;
    double height;
    double angle;
    double vx;
    double vy;
    double vrot;
    QColor color;

public:
    Confetto(double x, double y, double width, double height, double angle, double vx, double vy, double vrot, QColor color);
    void moveStep();
    [[nodiscard]] QVector<QPoint> getBoundaries() const;
    QColor getColor() const;

};


#endif //PIC_AEM_PROJEKT_CONFETTO_H
