#include "TaskWidget.h"

#include <QCheckBox>
#include <QHBoxLayout>
#include <QFont>
#include <QStyle>
#include <QPushButton>

TaskWidget::TaskWidget(todolib::Task &task, QWidget *parent)
        : task{task}, QWidget(parent) {

    auto *hbox = new QHBoxLayout(this);
    taskcheckbox = new QCheckBox(this);
    taskcheckbox ->setText(QString::fromStdString(task.name));
    taskcheckbox ->setCheckState(Qt::Unchecked);
    taskdeletebutton = new QPushButton();
    taskdeletebutton->setIcon(taskdeletebutton -> style()->standardIcon(QStyle::SP_TrashIcon));
    hbox->addWidget(taskcheckbox, 0, Qt::AlignLeft | Qt::AlignTop);
    hbox->addWidget(taskdeletebutton, 0, Qt::AlignRight | Qt::AlignTop);

    connect(taskdeletebutton,&QPushButton::clicked, this, &TaskWidget::delete_task);
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

void TaskWidget::delete_task() {
    emit taskDeleted();
}
