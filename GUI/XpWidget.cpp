//
// Created by Jan Ole Weighardt on 26.05.23.
//

#include "XpWidget.h"
XpWidget::XpWidget(/*todolib::ToDoList &toDoList,*/ QWidget *parent) : /*xpobjekt{toDoList},*/ QWidget(parent) {
    int xpWidgetZahl = 0;
    xpLabel = std::make_shared<QLabel>();

    xpLayout = std::make_shared<QVBoxLayout>();
    xpLayout->addWidget(xpLabel.get());

    xpLabel->setText(QString::number(xpWidgetZahl));
    setLayout(xpLayout.get());

    connect(, SIGNAL(xpWidgetSignal(bool)), this, SLOT(xpWidgetFunc(bool)));
}
void XpWidget::xpWidgetFunc(bool xpWidgetbool){
    if (xpWidgetbool){
        xpWidgetZahl++;
    }else{
        xpWidgetZahl--;
    }
}
