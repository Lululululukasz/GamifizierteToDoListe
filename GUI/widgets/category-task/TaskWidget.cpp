#include "TaskWidget.h"
#include "GUI/Points.h"
#include "utility/Globals.h"
#include "todolib/todolib.h"

#include <random>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QFont>
#include <QStyle>
#include <QPushButton>
#include <QToolButton>
#include <QSound>
#include <QtDebug>


TaskWidget::TaskWidget(todolib::Task &task, QWidget *parent)
        : task{task}, QWidget(parent) {

    //layouts
    hbox = std::make_shared<QHBoxLayout>();
    vbox = std::make_shared<QVBoxLayout>(this);

    //font
    font = std::make_shared<QFont>();

    //taskCheckbox
    taskCheckbox = std::make_shared<QCheckBox>(this);


    //taskNameLabel
    taskNameLabel = std::make_shared<QLabel>(this);
    taskNameLabel->setText(QString::fromStdString(task.name));


    //taskDeleteButton
    taskDeleteButton = std::make_shared<QPushButton>();
    taskDeleteButton->setText("  Delete");
    taskDeleteButton->setIcon(taskDeleteButton->style()->standardIcon(QStyle::SP_TrashIcon));

    //showDescriptionButton
    showDescriptionButton = std::make_shared<QToolButton>(this);
    showDescriptionButton->setCheckable(true);
    showDescriptionButton->setArrowType(Qt::RightArrow);
    showDescriptionButton->setStyleSheet("QToolButton{border: none;}");

    //taskDescriptionLabel
    taskDescriptionLabel = std::make_shared<QLabel>();
    taskDescriptionLabel->setWordWrap(true);
    taskDescriptionLabel->setText(QString::fromStdString(task.description));

    //adding widgets to the layouts
    vbox->addLayout(hbox.get());
    hbox->addWidget(taskCheckbox.get(), 0, Qt::AlignLeft | Qt::AlignVCenter);
    hbox->addWidget(showDescriptionButton.get(), 0, Qt::AlignLeft | Qt::AlignVCenter);
    hbox->addWidget(taskNameLabel.get(), 1, Qt::AlignLeft | Qt::AlignVCenter);
    hbox->addWidget(taskDeleteButton.get(), 0, Qt::AlignRight | Qt::AlignVCenter);

    //connecting to the slots below
    connect(taskDeleteButton.get(), &QPushButton::clicked, this, &TaskWidget::deleteTask);
    connect(taskCheckbox.get(), &QCheckBox::stateChanged, this, [=,this](bool checked){
        if (checked) taskDone();
        else taskUndone();
    });
    if(task.getDoneStatus()){
        taskCheckbox->setCheckState(Qt::Checked);
    } else {
        taskCheckbox->setCheckState(Qt::Unchecked);
    }
    connect(showDescriptionButton.get(), &QToolButton::toggled, [=,this](bool checked) {
        showDescriptionButton->setArrowType(checked ? Qt::ArrowType::DownArrow : Qt::ArrowType::RightArrow);
        if (checked) showDescription();
        else hideDescription();
    });

}

//changes the state of the taskNameLabel to strikedout or not strikedout
void TaskWidget::taskDone() {

        font->setStrikeOut(true);
        taskNameLabel->setFont(*font);

        if(!task.getDoneStatus()) {
            task.setAsDone();
            //The Values for the points are provisional and should later be changed to whatever you want.
            Points::getinstance().addPoints(1,1,'n');
            playRandomSound();
        }
}

//emits the deleteTaskSignal that is used in CategoryWidget
void TaskWidget::deleteTask() {
    emit deleteTaskSignal();
}

//shows the description of a task when the showDescriptionButton is checked
void TaskWidget::showDescription() {
    taskDescriptionLabel->setVisible(true);
    vbox->addWidget(taskDescriptionLabel.get(), 0, Qt::AlignLeft | Qt::AlignVCenter);
}

//hides the description of a task when the showDescriptionButton is unchecked
void TaskWidget::hideDescription() {

    hbox->removeWidget(taskDescriptionLabel.get());
    taskDescriptionLabel->setVisible(false);

}

//plays a random sound out of three when a TaskCheckbox gets checked
void TaskWidget::playRandomSound() {
    std::random_device randomDevice;
    std::uniform_int_distribution<std::mt19937::result_type> randomSound(1, 3);


    switch (randomSound(randomDevice)) {
        case 1:
            QSound::play(Globals::homepath+"/resources/taskDoneSound_amazing.wav");
            break;
        case 2:
            QSound::play(Globals::homepath+"/resources/taskDoneSound_incredible.wav");
            break;
        case 3:
            QSound::play(Globals::homepath+"/resources/taskDoneSound_outstanding.wav");
            break;
    }
}

void TaskWidget::taskUndone() {

    font->setStrikeOut(false);
    taskNameLabel->setFont(*font);
    if(task.getDoneStatus()) {
        task.setAsUndone();
        Points::getinstance().subPoints(1, 'n');
    }

}





