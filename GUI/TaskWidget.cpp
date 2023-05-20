#include <QCheckBox>
#include <QHBoxLayout>
#include <QFont>
#include <QStyle>
#include "TaskWidget.h"
#include <QPushButton>


TaskWidget::TaskWidget(QWidget *parent)
        : QWidget(parent) {

    QHBoxLayout *hbox = new QHBoxLayout(this);
    taskcheckbox = new QCheckBox(this);
    taskcheckbox ->setText("some Task");
    taskcheckbox ->setCheckState(Qt::Unchecked);
    taskdeletebutton = new QPushButton();
    taskdeletebutton->setIcon(taskdeletebutton -> style()->standardIcon(QStyle::SP_TrashIcon));
    hbox->addWidget(taskcheckbox, 0, Qt::AlignLeft | Qt::AlignTop);
    hbox->addWidget(taskdeletebutton, 0, Qt::AlignRight | Qt::AlignTop);

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
