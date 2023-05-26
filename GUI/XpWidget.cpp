//
// Created by Jan Ole Weighardt on 26.05.23.
//

#include "XpWidget.h"
XpWidget::XpWidget(todolib::Xp &xp, QWidget *parent) : xp{xp}, QWidget(parent) {
    xpLabel = std::make_shared<QLabel>("0", this);
    xpLayout = std::make_shared<QVBoxLayout>(this);
    xpLayout->addWidget(xpLabel.get());
    xpLabel->setText(QString::number(xp));
    setLayout(xpLayout.get());
}
