#include "TaskWidget.h"
#include "GUI/Points.h"
#include "utility/Globals.h"
#include "todolib/todolib.h"
#include "GUI/ConfettiAnimation/DrawConfetti.h"

#include <random>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QFont>
#include <QStyle>
#include <QPushButton>
#include <QToolButton>
#include <QSound>
#include <QGraphicsRotation>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>

void TaskWidget::update() {
    taskNameLabel->setText(QString::fromStdString(task.name));

    QString descriptionText = "Description: " + QString::fromStdString(task.description);
    taskDescriptionLabel->setText(descriptionText);

    int year = static_cast<int>(task.getDueDate().year());
    unsigned month = static_cast<unsigned>(task.getDueDate().month());
    QStringList monthList {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    QString monthString = monthList[month - 1];
    unsigned day = static_cast<unsigned>(task.getDueDate().day());
    if(day<=3) {
        QStringList dayList {"1st", "2nd", "3rd"};
        QString dayString = dayList[day - 1];
        QString dueDateText = "Due on: " + dayString + " of " + monthString + " " + QString::number(year);
        taskDueDateLabel->setText(dueDateText);
    } else if(day == 21 || day == 22 || day == 23){
        QStringList dayList {"21st", "22nd", "23rd"};
        QString dayString = dayList[day - 21];
        QString dueDateText = "Due on: " + dayString + " of " + monthString + " " + QString::number(year);
        taskDueDateLabel->setText(dueDateText);
    }else{
        QString dueDateText = "Due on: " + QString::number(day)  + "th" + " of " + monthString + " " + QString::number(year);
        taskDueDateLabel->setText(dueDateText);
    }

    QString priorityText = "Priority: " + QString::fromStdString(task.getPriorityString());
    taskPriorityLabel->setText(priorityText);

    QString durationText = "Duration: " + QString::number(task.getDuration());
    taskDurationLabel->setText(durationText);

    taskCheckbox->setCheckState(task.getDoneStatus() ? Qt::Checked : Qt::Unchecked);
}

TaskWidget::TaskWidget(todolib::Task &task, todolib::Category& category,  Page &page, QWidget *parent)
        : task{task}, catgory{category}, page{page}, QWidget(parent) {

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

    editTaskButton = std::make_shared<QPushButton>();
    editTaskButton->setIcon(QIcon(Globals::homepath+"/resources/edit_icon.png"));

    //showDescriptionButton
    showDescriptionButton = std::make_shared<QToolButton>(this);
    showDescriptionButton->setCheckable(true);
    showDescriptionButton->setArrowType(Qt::RightArrow);
    showDescriptionButton->setStyleSheet("QToolButton{border: none;}");

    //taskDescriptionLabel
    taskDescriptionLabel = std::make_shared<QLabel>();
    taskDescriptionLabel->setWordWrap(true);
    QString descriptionText = "Description: " + QString::fromStdString(task.description);
    taskDescriptionLabel->setText(descriptionText);

    taskPriorityLabel = std::make_shared<QLabel>();
    QString priorityText = "Priority: " + QString::fromStdString(task.getPriorityString());
    taskPriorityLabel->setText(priorityText);

    //taskDurationLabel
    taskDurationLabel = std::make_shared<QLabel>();
    QString durationText = "Duration: " + QString::number(task.getDuration());
    taskDurationLabel->setText(durationText);

    //taskDueDateLabel
    taskDueDateLabel = std::make_shared<QLabel>();
    int year = static_cast<int>(task.getDueDate().year());
    unsigned month = static_cast<unsigned>(task.getDueDate().month());
    QStringList monthList {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    QString monthString = monthList[month - 1];
    unsigned day = static_cast<unsigned>(task.getDueDate().day());
    if(day<=3) {
        QStringList dayList {"1st", "2nd", "3rd"};
        QString dayString = dayList[day - 1];
        QString dueDateText = "Due on: " + dayString + " of " + monthString + " " + QString::number(year);
        taskDueDateLabel->setText(dueDateText);
    } else if(day == 21 || day == 22 || day == 23){
        QStringList dayList {"21st", "22nd", "23rd"};
        QString dayString = dayList[day - 21];
        QString dueDateText = "Due on: " + dayString + " of " + monthString + " " + QString::number(year);
        taskDueDateLabel->setText(dueDateText);
    }else{
        QString dueDateText = "Due on: " + QString::number(day)  + "th" + " of " + monthString + " " + QString::number(year);
        taskDueDateLabel->setText(dueDateText);
    }

    //pictureLabel
    pictureLabel = std::make_shared<QLabel>();
    if(task.getPicture().empty()){
        pictureLabel->setHidden(true);
    } else {
        picturePixmap = Globals::homepath + QString::fromStdString(task.getPicture());
        pictureLabel->setPixmap(picturePixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }


    //adding widgets to the layouts
    vbox->addLayout(hbox.get());
    hbox->addWidget(taskCheckbox.get(), 0, Qt::AlignLeft | Qt::AlignVCenter);
    hbox->addWidget(showDescriptionButton.get(), 0, Qt::AlignLeft | Qt::AlignVCenter);
    hbox->addWidget(taskNameLabel.get(), 1, Qt::AlignLeft | Qt::AlignVCenter);
    hbox->addWidget(editTaskButton.get(), 0, Qt::AlignRight | Qt::AlignVCenter);
    hbox->addWidget(taskDeleteButton.get(), 0, Qt::AlignRight | Qt::AlignVCenter);

    //connecting to the slots below
    connect(taskDeleteButton.get(), &QPushButton::clicked, this, &TaskWidget::deleteButtonPressed);
    connect(editTaskButton.get(), &QPushButton::clicked, this, &TaskWidget::editTask);
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

    update();
}

//changes the state of the taskNameLabel to strikedout or not strikedout
void TaskWidget::taskDone() {

        font->setStrikeOut(true);
        taskNameLabel->setFont(*font);

        if(!task.getDoneStatus()) {
            task.setAsDone();
            emit xpWidgetSignalAdd();// Emit the Signal for Xp Number +1
            //The Values for the points are provisional and should later be changed to whatever you want.
            Points::getinstance().addPoints(1,1,'n');
            playRandomSound();
            emit taskMarkedChanged();
            playConfettiAnimation();
             catgory.saveToJson();
        }
}

void TaskWidget::taskUndone() {

    font->setStrikeOut(false);
    taskNameLabel->setFont(*font);
    if(task.getDoneStatus()) {
        task.setAsUndone();
         emit xpWidgetSignalSub();// Emit the Signal Xp Number -1 sends the signal through CategoryWidget to CategoryViewPage to Page where it aktivates the function
        Points::getinstance().subPoints(1, 'n');
        catgory.saveToJson();
    }

}

void TaskWidget::editTask() {
    editTaskBox = std::make_shared<EditTaskBox>(task);
    editTaskBox->show();
    connect(editTaskBox.get(), &EditTaskBox::isOver, this, [=, this]() {
        task.saveToJson();
        update();
    });
}

//emits the deleteTaskSignal that is used in CategoryWidget
void TaskWidget::deleteTask() {
    catgory.deleteTask(task.getID());
    catgory.saveToJson();
}

//shows the description of a task when the showDescriptionButton is checked
void TaskWidget::showDescription() {

    vbox->addWidget(taskDescriptionLabel.get(), 0, Qt::AlignLeft | Qt::AlignVCenter);
    taskDescriptionLabel->setVisible(true);
    vbox->addWidget(taskPriorityLabel.get());
    taskPriorityLabel->setVisible(true);
    vbox->addWidget(taskDurationLabel.get());
    taskDurationLabel->setVisible(true);
    vbox->addWidget(taskDueDateLabel.get());
    taskDueDateLabel->setVisible(true);
    vbox->addWidget(pictureLabel.get());
    pictureLabel->setVisible(true);
}

//hides the description of a task when the showDescriptionButton is unchecked
void TaskWidget::hideDescription() {

    vbox->removeWidget(taskDescriptionLabel.get());
    taskDescriptionLabel->setVisible(false);
    vbox->removeWidget(taskPriorityLabel.get());
    taskPriorityLabel->setVisible(false);
    vbox->removeWidget(taskDurationLabel.get());
    taskDurationLabel->setVisible(false);
    vbox->removeWidget(taskDueDateLabel.get());
    taskDueDateLabel->setVisible(false);
    vbox->removeWidget(pictureLabel.get());
    pictureLabel->setVisible(false);

}

//plays a random sound out of three when a TaskCheckbox gets checked
void TaskWidget::playRandomSound() {
    std::random_device randomDevice;
    std::uniform_int_distribution<std::mt19937::result_type> randomSound(1, 3);


    switch (randomSound(randomDevice)) {
        case 1:
            QSound::play(Globals::soundpath+"taskDoneSound_amazing.wav");
            break;
        case 2:
            QSound::play(Globals::soundpath+"taskDoneSound_incredible.wav");
            break;
        case 3:
            QSound::play(Globals::soundpath+"taskDoneSound_outstanding.wav");
            break;
    }
}

void TaskWidget::playConfettiAnimation() {
    confetti = std::make_shared<DrawConfetti>();
    page.setOverlay(confetti);
}