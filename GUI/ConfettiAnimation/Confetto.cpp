//
// Created by vera on 01.06.23.
//

#include "Confetto.h"

#include <utility>
#include <cmath>

#include <iostream>

Confetto::Confetto(double x, double y, double width, double height, double angle, double vx, double vy, double vrot, QColor color) :
  x(x), y(y), width(width), height(height), angle(angle / 180 * M_PI), vx(vx), vy(vy), vrot(vrot / 180 * M_PI), color(std::move(color)) {}

void Confetto::moveStep() {
    double const scale {0.15};
    x += vx * scale;
    y += vy * scale;
    angle += vrot * scale;
    vy += 5 * scale;
}

QVector<QPoint> Confetto::getBoundaries() const {
    return {
        QPoint(x, y),
        QPoint(x + width * cos(angle), y + width * sin(angle)),
        QPoint(x + width * cos(angle) + height * sin(angle), y + width * sin(angle) + height * cos(angle)),
        QPoint(x + height * sin(angle), y + height * cos(angle))
    };
}

QColor Confetto::getColor() const {
    return color;
}
