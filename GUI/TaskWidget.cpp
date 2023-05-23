#include "TaskWidget.h"

#include <QCheckBox>
#include <QHBoxLayout>
#include <QFont>
#include <QStyle>
#include <QPushButton>
#include <QToolButton>


TaskWidget::TaskWidget(todolib::Task &task, QWidget *parent)
        : task{task}, QWidget(parent) {

    hbox = std::make_shared<QHBoxLayout>();
    vbox = std::make_shared<QVBoxLayout>(this);

    taskCheckbox = std::make_shared<QCheckBox>(this);
    taskCheckbox->setCheckState(Qt::Unchecked);

    taskNameLabel = std::make_shared<QLabel>(this);
    taskNameLabel->setText(QString::fromStdString(task.name));

    taskDeleteButton = std::make_shared<QPushButton>();
    taskDeleteButton->setIcon(taskDeleteButton->style()->standardIcon(QStyle::SP_TrashIcon));

    showDescriptionButton = std::make_shared<QToolButton>(this);
    showDescriptionButton->setCheckable(true);
    showDescriptionButton->setArrowType(Qt::RightArrow);
    showDescriptionButton->setStyleSheet("QToolButton{border: none;}");

    taskDescriptionLabel = std::make_shared<QLabel>();
    taskDescriptionLabel->setWordWrap(true);
    taskDescriptionLabel->setText(QString::fromStdString(task.description));

    vbox->addLayout(hbox.get());
    hbox->addWidget(taskCheckbox.get(), 0, Qt::AlignLeft | Qt::AlignVCenter);
    hbox->addWidget(showDescriptionButton.get(), 0, Qt::AlignLeft | Qt::AlignVCenter);
    hbox->addWidget(taskNameLabel.get(), 1, Qt::AlignLeft | Qt::AlignVCenter);
    hbox->addWidget(taskDeleteButton.get(), 0, Qt::AlignRight | Qt::AlignVCenter);

    connect(taskDeleteButton.get(), &QPushButton::clicked, this, &TaskWidget::deleteTask);
    connect(taskCheckbox.get(), &QCheckBox::stateChanged, this, &TaskWidget::strikeoutTask);
    connect(showDescriptionButton.get(), &QToolButton::toggled, [=,this](bool checked) {
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
    vbox->addWidget(taskDescriptionLabel.get(), 0, Qt::AlignLeft | Qt::AlignVCenter);
}

void TaskWidget::hideDescription() {

    hbox->removeWidget(taskDescriptionLabel.get());
    taskDescriptionLabel->setVisible(false);

}

