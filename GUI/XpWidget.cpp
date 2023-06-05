//
// Created by Jan Ole Weighardt on 26.05.23.
//

#include "XpWidget.h"
XpWidget::XpWidget(todolib::Xp &xp, QWidget *parent ) :xp {xp}, QWidget(parent) {

    xpLabel = std::make_shared<QLabel>();

    xpLayout = std::make_shared<QVBoxLayout>();
    xpLayout->addWidget(xpLabel.get());

    xpLabel->setText(QString::number(xpWidgetNumber));
    setLayout(xpLayout.get());
    xpFirstNumber();

}
void XpWidget::xpFirstNumber(){
    if (xp.xpZahl=!0){
        xpWidgetNumber = xp.xpZahl;
    }else{
        xpWidgetNumber = 0;
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