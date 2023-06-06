//
// Created by Jan Ole Weighardt on 26.05.23.
//

#include "XpWidget.h"
XpWidget::XpWidget(todolib::Xp &xp, QWidget *parent ) :xp {xp}, QWidget(parent) {

    xpLabel = std::make_shared<QLabel>();

    xpLayout = std::make_shared<QVBoxLayout>();
    xpLayout->addWidget(xpLabel.get());


    xpLabel->setText(QString::number(xp.xptrueNumber));
    setLayout(xpLayout.get());
   // xpFirstNumber();

}
/*void XpWidget::xpFirstNumber(){
    if (0!=xp.xpNumber){
        xpWidgetNumber = xp.xptrueNumber;
    }
}*/
//this two function add or take one to the Xp Number
void XpWidget::xpWidgetFunc1(){
    ++xp.xptrueNumber;
    xpLabel->setText(QString::number(xp.xptrueNumber));

}
void XpWidget::xpWidgetFunc2(){
    --xp.xptrueNumber;
    xpLabel->setText(QString::number(xp.xptrueNumber));
}