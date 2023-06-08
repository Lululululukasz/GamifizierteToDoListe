//
// Created by Jan Ole Weighardt on 26.05.23.
//

#include "XpWidget.h"
XpWidget::XpWidget(todolib::Xp &xp, QWidget *parent ) :xp {xp}, QWidget(parent) {
    progressBar = std::make_shared<QProgressBar>();
    progressBar->setRange(0,levelcap);

    xpLabel = std::make_shared<QLabel>();
    xpLayout = std::make_shared<QHBoxLayout>();

    xpLayout->addWidget(xpLabel.get());

    progressBar->setValue(xp.xptrueNumber);

    xpLabel->setText(QString::fromStdString(currrentLevel));
    xpLayout->addWidget(progressBar.get());

    setLayout(xpLayout.get());


}


//this two function add or take one to the Xp Number
void XpWidget::xpWidgetFuncAdd(){
    xp.setxptrueNumber(++xp.xptrueNumber);
    levelUp();
    progressBar->setValue(xp.xptrueNumber);
    levelcap=xp.levelNumber;
    progressBar->setRange(0,levelcap);

}
void XpWidget::levelUp(){
    if (levelcap==xp.xptrueNumber){
        xp.setxptrueNumber(0);
        xp.setlevelNumber(++xp.levelNumber);
        currrentLevel= "Level: " + std::to_string(xp.levelNumber);
        levelcap=xp.levelNumber;
        progressBar->reset();
        xpLabel->setText(QString::fromStdString(currrentLevel));

    }

}
void XpWidget::xpWidgetFuncSub(){
    xp.setxptrueNumber(--xp.xptrueNumber);
    progressBar->setValue(xp.xptrueNumber);
    levelcap=xp.levelNumber;
    if(xp.xptrueNumber<0){
        xp.setxptrueNumber(0);
        progressBar->setValue(0);
    }

}