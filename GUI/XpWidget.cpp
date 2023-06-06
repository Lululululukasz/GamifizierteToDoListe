//
// Created by Jan Ole Weighardt on 26.05.23.
//

#include "XpWidget.h"
XpWidget::XpWidget(todolib::Xp &xp, QWidget *parent ) :xp {xp}, QWidget(parent) {

    xpLabel = std::make_shared<QLabel>();

    xpLayout = std::make_shared<QVBoxLayout>();
    xpLayout->addWidget(xpLabel.get());

    xpFirstNumber();
    xpLabel->setText(QString::number(xpWidgetNumber));
    setLayout(xpLayout.get());


}
void XpWidget::xpFirstNumber(){
    if (0!=xp.xptrueNumber){
        xpWidgetNumber = xp.xptrueNumber;
    }
}
//this two function add or take one to the Xp Number
void XpWidget::xpWidgetFunc1(){
    ++xpWidgetNumber;
    xpLabel->setText(QString::number(xpWidgetNumber));
    xp.xpFunc(xpWidgetNumber);
}
void XpWidget::xpWidgetFunc2(){
    --xpWidgetNumber;
    xpLabel->setText(QString::number(xpWidgetNumber));
    xp.xpFunc(xpWidgetNumber);
}