#include "GUI/popups/AddTaskBox.h"

#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QApplication>
#include <QStringList>
#include <iostream>
#include <cmath>

AddTaskBox::AddTaskBox(QWidget *parent) : QWidget(parent), task(todolib::Task("", "")) {

    setFixedSize(400, 450);

    //stars
    for(auto i {0}; i < 3; i++) {
        auto starLabel {std::make_shared<QLabel>()};
        starLabel->setText("*");
        starLabel->setText("QLabel{color = orange;}");
        starLabels.push_back(starLabel);
    }

    //taskName
    nameLabel.setText(QString::fromStdString("Task Name: "));
    layout.addWidget(&nameLabel);
    aTNameTextEdit = std::make_shared<QTextEdit>(this);
    aTNameTextEdit->setGeometry(10, 10, 100, 10);
    layout.addWidget(aTNameTextEdit.get());


    //invalidName
    invalidNameLabel = std::make_shared<QLabel>();
    invalidNameLabel->setHidden(true);
    layout.addWidget(invalidNameLabel.get());

    //taskDescription
    descLabel.setText(QString::fromStdString("Task Description: "));
    layout.addWidget(&descLabel);
    aTDecriptionTextEdit = std::make_shared<QTextEdit>(this);
    aTDecriptionTextEdit->setGeometry(10, 40, 200, 60);
    layout.addWidget(aTDecriptionTextEdit.get());

    //taskPriority
    priorityLabel = std::make_shared<QLabel>();
    priorityLabel->setText("Select how high the priority of the task is:");
    layout.addWidget(priorityLabel.get());

    selectPriorityBox = std::make_shared<QComboBox>(this);
    selectPriorityBox->addItems(prios);
    layout.addWidget(selectPriorityBox.get());

    //invalidPriority
    invalidPriorityLabel = std::make_shared<QLabel>();
    invalidPriorityLabel->setHidden(true);
    layout.addWidget(invalidPriorityLabel.get());

    //taskDuration
    durationLabel = std::make_shared<QLabel>();
    durationLabel->setText("How many hours do you think this task will take?");
    layout.addWidget(durationLabel.get());

    durationTextEdit = std::make_shared<QTextEdit>(this);
    durationTextEdit->setGeometry(10, 10, 100, 10);
    durationTextEdit->setPlaceholderText("Please enter a number");
    layout.addWidget(durationTextEdit.get());

    //invalidDuration
    invalidDurationLabel = std::make_shared<QLabel>();
    invalidDurationLabel->setHidden("true");
    layout.addWidget(invalidDurationLabel.get());

    //taskDueDate
    dueDateLabel = std::make_shared<QLabel>();
    dueDateLabel->setText("When should this task be done?");
    layout.addWidget(dueDateLabel.get());

    dateLayout = std::make_shared<QHBoxLayout>(this);
    layout.addLayout(dateLayout.get());

    selectDayBox = std::make_shared<QComboBox>(this);
    selectDayBox->addItems(days);
    dateLayout->addWidget(selectDayBox.get());

    selectMonthBox = std::make_shared<QComboBox>(this);
    selectMonthBox->addItems(months);
    dateLayout->addWidget(selectMonthBox.get());

    selectYearBox = std::make_shared<QComboBox>(this);
    selectYearBox->addItems(years);
    dateLayout->addWidget(selectYearBox.get());

    //invalidDate
    invalidDateLabel = std::make_shared<QLabel>();
    invalidDateLabel->setHidden("true");
    layout.addWidget(invalidDateLabel.get());

    //addTask
    addTaskButton = std::make_shared<QPushButton>("Add Task", this);
    addTaskButton->setGeometry(10, 100, 80, 30);
    addTaskButton->setCheckable(true);
    layout.addWidget(addTaskButton.get());

    connect(selectPriorityBox.get(), static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [=,this]{
        invalidPriorityLabel->setHidden(true);
    });
    connect(selectDayBox.get(), static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [=, this] {
        invalidDateLabel->setHidden(true);
    });
    connect(selectMonthBox.get(), static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [=, this] {
        invalidDateLabel->setHidden(true);
    });
    connect(selectYearBox.get(), static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [=, this] {
        invalidDateLabel->setHidden(true);
    });
    connect(durationTextEdit.get(), &QTextEdit::textChanged, [=,this]{
        invalidDurationLabel->setHidden(true);
    });
    connect(aTNameTextEdit.get(), &QTextEdit::textChanged, [=,this]{
        invalidNameLabel->setHidden(true);
    });
    connect(addTaskButton.get(), SIGNAL (clicked(bool)), this, SLOT (addTaskClicked(bool)));
    connect(this, SIGNAL (isOver()), this, SLOT (closeAddTaskWindow()));
}

void AddTaskBox::setCategory(todolib::Category &category){
    this->category = std::make_shared<todolib::Category>(category);
}

bool AddTaskBox::invalidDate() {

    int day = selectDayBox->currentIndex();
    int month = selectMonthBox->currentIndex();
    int year = selectYearBox->currentIndex() + 2022;

    if(day == 0 || month == 0 || year == 0) {
        return true;
    } else if(day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)){
        return true;
    } else if(day == 30 && month == 2 ){
        return true;
    } else if(day == 29 && month == 2 && !(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))){
        return true;
    } else if (pastDate()) {
        return true;
    } else {
        return false;
    }
}

bool AddTaskBox::invalidPriority() {
    if(selectPriorityBox->currentIndex() == 0){
        return true;
    } else {
        return false;
    }
}

bool AddTaskBox::pastDate() {
    auto now = std::chrono::system_clock::now();
    auto today = std::chrono::floor<std::chrono::days>(now);
    std::chrono::year_month_day dateToday{today};

    std::chrono::year_month_day dueDate {std::chrono::year(selectYearBox->currentIndex() + 2022),
                                         std::chrono::month(selectMonthBox->currentIndex()),
                                         std::chrono::day(selectDayBox->currentIndex())};


    if(dueDate < dateToday){
        return true;
    } else {
        return false;
    }
}

bool AddTaskBox::invalidDuration() {
    if(durationTextEdit->toPlainText().toStdString().length() == 0){
        return false;
    } else {
    try {std::stod(durationTextEdit->toPlainText().toStdString());
    } catch(std::exception &notANumber){
        return true;
    }}
        return false;
}

bool AddTaskBox::invalidName() {
    if(aTNameTextEdit->toPlainText().toStdString().length() == 0){
        return true;
    }
        return false;
}

bool AddTaskBox::invalidInput() {
    if(invalidPriority()){
        invalidPriorityLabel->setText("Please enter a priority.");
        invalidPriorityLabel->setStyleSheet("QLabel{color: red};");
        invalidPriorityLabel->setHidden(false);
    }
    if(invalidDate()){
        invalidDateLabel->setText("Please enter a valid date.");
        invalidDateLabel->setStyleSheet("QLabel{color: red};");
        invalidDateLabel->setHidden(false);
    }
    if(invalidDuration()){
        invalidDurationLabel->setText("Please enter a number");
        invalidDurationLabel->setStyleSheet("QLabel{color: red};");
        invalidDurationLabel->setHidden(false);
    }
    if(invalidName()){
        invalidNameLabel->setText("Please enter a name");
        invalidNameLabel->setStyleSheet("QLabel{color: red};");
        invalidNameLabel->setHidden(false);
    }
    if(invalidPriority() || invalidDate() || invalidDuration() || invalidName()){
        return true;
    } else {
        return false;
    }
}


void AddTaskBox::addTaskClicked(bool checked)
{
    if (checked) {
        if(invalidInput()){
            this->addTaskButton->setChecked(false);
        } else {
            this->addTaskButton->setChecked(false);
            std::string name{this->aTNameTextEdit->toPlainText().toStdString()};
            std::string description{this->aTDecriptionTextEdit->toPlainText().toStdString()};
            // category->addTask(todolib::Task(name, description));
            task = todolib::Task(name, description);
            hasTaskBool = true;
            task.setPriority(static_cast<todolib::Task::priority_t>(selectPriorityBox->currentIndex()));
            task.setDuration(this->durationTextEdit->toPlainText().toDouble());
            task.setdueDate(std::chrono::year_month_day(
                    std::chrono::year(selectYearBox->currentIndex() + 2022),
                    std::chrono::month(selectMonthBox->currentIndex()),
                    std::chrono::day(selectDayBox->currentIndex())
            ));
            emit isOver();
        }
    }
}

bool AddTaskBox::hasTask() const {
    return hasTaskBool;
}

void AddTaskBox::closeAddTaskWindow() {
    this->hide();
}








