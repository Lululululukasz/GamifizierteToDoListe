#include "TaskWidget.h"

#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFont>
#include <QStyle>
#include <QPushButton>
#include <QToolButton>


TaskWidget::TaskWidget(todolib::Task &task, QWidget *parent)
        : task{task}, QWidget(parent) {

    hbox = new QHBoxLayout();
    vbox = new QVBoxLayout(this);

    taskCheckbox = new QCheckBox(this);
    taskCheckbox->setCheckState(Qt::Unchecked);

    taskNameLabel = new QLabel(this);
    taskNameLabel->setText(QString::fromStdString(task.name));

    taskDeleteButton = new QPushButton();
    taskDeleteButton->setIcon(taskDeleteButton->style()->standardIcon(QStyle::SP_TrashIcon));

    showDescriptionButton = new QToolButton(this);
    showDescriptionButton->setCheckable(true);
    showDescriptionButton->setArrowType(Qt::RightArrow);
    showDescriptionButton->setStyleSheet("QToolButton{border: none;}");

    taskDescriptionLabel = new QLabel();
    taskDescriptionLabel->setWordWrap(true);
    taskDescriptionLabel->setText(QString::fromStdString(task.description));

    vbox->addLayout(hbox);
    hbox->addWidget(taskCheckbox, 0, Qt::AlignLeft | Qt::AlignVCenter);
    hbox->addWidget(showDescriptionButton, 0, Qt::AlignLeft | Qt::AlignVCenter);
    hbox->addWidget(taskNameLabel, 1, Qt::AlignLeft | Qt::AlignVCenter);
    hbox->addWidget(taskDeleteButton, 0, Qt::AlignRight | Qt::AlignVCenter);

    connect(taskDeleteButton, &QPushButton::clicked, this, &TaskWidget::deleteTask);
    connect(taskCheckbox, &QCheckBox::stateChanged, this, &TaskWidget::strikeoutTask);
    connect(showDescriptionButton, &QToolButton::toggled, [=](bool checked) {
        showDescriptionButton->setArrowType(checked ? Qt::ArrowType::DownArrow : Qt::ArrowType::RightArrow);
        if (checked) showDescription();
        else hideDescription();
    });

}

void TaskWidget::strikeoutTask(int state) {

    QFont *font = new QFont;

    if (state == Qt::Checked) {
        font->setStrikeOut(true);
        taskNameLabel->setFont(*font);
    } else {
        font->setStrikeOut(false);
        taskNameLabel->setFont(*font);
    }
}

void TaskWidget::deleteTask() {
    emit taskDeleted();
}

void TaskWidget::showDescription() {
    taskDescriptionLabel->setVisible(true);
    vbox->addWidget(taskDescriptionLabel, 0, Qt::AlignLeft | Qt::AlignVCenter);
}

void TaskWidget::hideDescription() {

    hbox->removeWidget(taskDescriptionLabel);
    taskDescriptionLabel->setVisible(false);

}

