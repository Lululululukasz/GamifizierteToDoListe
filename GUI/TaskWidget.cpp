//
// Created by vera on 14.05.23.
//
#include <QCheckBox>
#include <QHBoxLayout>
#include <QFont>
#include "TaskWidget.h"
#include <QPushButton>



TaskWidget::TaskWidget(QWidget *parent)
        : QWidget(parent) {


    QHBoxLayout *hbox = new QHBoxLayout(this);
    taskcheckbox = new QCheckBox(this);
    taskcheckbox ->setText("some Task");
    taskcheckbox ->setCheckState(Qt::Unchecked);
    taskdeletebutton = new QPushButton("button");
    taskdeletebutton->setGeometry(50,100,150,80);
    hbox->addWidget(taskcheckbox, 0, Qt::AlignLeft | Qt::AlignTop);
    hbox->addWidget(taskdeletebutton, Qt::AlignRight, Qt::AlignTop);


    //taskdeletebutton->show();

    //QObject::connect(button,&QPushButton::clicked,insert());
    connect(taskcheckbox, &QCheckBox::stateChanged, this, &TaskWidget::strikeout_task);
}


void TaskWidget::strikeout_task(int state) {


    QFont *font = new QFont;


    if (state == Qt::Checked) {
        font->setStrikeOut(true);
        taskcheckbox->setFont(*font);
    } else {
        font->setStrikeOut(false);
        taskcheckbox->setFont(*font);
    }
}
