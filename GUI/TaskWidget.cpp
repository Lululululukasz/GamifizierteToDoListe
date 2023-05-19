//
// Created by vera on 14.05.23.
//
#include <QCheckBox>
#include <QHBoxLayout>
#include <QFont>
#include "TaskWidget.h"


CheckBox::CheckBox(QWidget *parent)
        : QWidget(parent) {


    QHBoxLayout *hbox = new QHBoxLayout(this);
    cb = new QCheckBox(this);
    cb->setText("some Task");
    cb->setCheckState(Qt::Unchecked);
    hbox->addWidget(cb, 0, Qt::AlignLeft | Qt::AlignTop);


    connect(cb, &QCheckBox::stateChanged, this, &CheckBox::strikeout_task);
}


void CheckBox::strikeout_task(int state) {


    QFont *font = new QFont;


    if (state == Qt::Checked) {
        font->setStrikeOut(true);
        cb->setFont(*font);
    } else {
        font->setStrikeOut(false);
        cb->setFont(*font);
    }
}
