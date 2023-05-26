//
// Created by Jan Ole Weighardt on 26.05.23.
//

#include "XpWidget.h"
XpWidget::XpWidget( QWidget *parent) : QWidget(parent) {

    xpLabel = std::make_shared<QLabel>();

    xpLayout = std::make_shared<QVBoxLayout>();
    xpLayout->addWidget(xpLabel.get());

    xpLabel->setText(QString::number(todolib::Xp::xpZahl));
    setLayout(xpLayout.get());
}
