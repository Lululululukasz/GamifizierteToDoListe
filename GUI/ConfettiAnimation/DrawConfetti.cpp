//
// Created by vera on 31.05.23.
//
#include "DrawConfetti.h"
#include <random>
#include <QTimer>


DrawConfetti::DrawConfetti() {
    std::random_device randomDevice;
    std::uniform_int_distribution<std::mt19937::result_type> randomSize(4, 8);
    std::uniform_int_distribution<std::mt19937::result_type> randomPosition(0, 50);
    std::uniform_int_distribution<std::mt19937::result_type> randomSpeed(6, 10);
    std::uniform_int_distribution<std::mt19937::result_type> randomSide(0, 1);
    for(int i {0}; i < 100; i++) {
        auto side = randomSide(randomDevice) ? -1 : 1;
        confettos.emplace_back(
                50 + side * (randomPosition(randomDevice)), 100,
                randomSize(randomDevice), randomSize(randomDevice),
                0,
                -side * randomSpeed(randomDevice),
                -18,
                5 * randomSpeed(randomDevice),
                generateColor()
        );
    }

    auto *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateAnimation()));
    timer->start(10);
}

void DrawConfetti::updateAnimation() {
    for(auto& confetto : confettos) {
        confetto.moveStep();
    }
    update();
}

QSize DrawConfetti::minimumSizeHint() const {
    return {100, 100};
}

void DrawConfetti::paintEvent(QPaintEvent *event) {
    QPainter painter{this};
    for(auto const& confetto : confettos) {
        painter.setBrush(QBrush(confetto.getColor()));
        painter.setPen(QPen(confetto.getColor()));
        painter.drawPolygon(QPolygon({ confetto.getBoundaries() }));
    }
}

QColor DrawConfetti::generateColor() {
    std::random_device randomDevice;
    std::uniform_int_distribution<std::mt19937::result_type> randomColor(1, 6);
    switch (randomColor(randomDevice)){
        case 1:
            return QColorConstants::Cyan;
        case 2:
            return QColorConstants::Red;
        case 3:
            return QColorConstants::Magenta;
        case 4:
            return QColorConstants::Green;
        case 5:
            return QColorConstants::Yellow;
        case 6:
            return QColorConstants::Blue;

    }
}
