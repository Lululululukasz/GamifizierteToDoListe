#include "GUI/popups/AddTaskBox.h"

#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QApplication>
#include <QStringList>

AddTaskBox::AddTaskBox(QWidget *parent) : QWidget(parent), task(todolib::Task("", "")) {

    setFixedSize(400, 400);

    nameLabel.setText(QString::fromStdString("Task Name: "));
    layout.addWidget(&nameLabel);
    aTNameTextEdit = std::make_shared<QTextEdit>(this);
    aTNameTextEdit->setGeometry(10, 10, 100, 10);
    layout.addWidget(aTNameTextEdit.get());

    descLabel.setText(QString::fromStdString("Task Description: "));
    layout.addWidget(&descLabel);
    aTDecriptionTextEdit = std::make_shared<QTextEdit>(this);
    aTDecriptionTextEdit->setGeometry(10, 40, 200, 60);
    layout.addWidget(aTDecriptionTextEdit.get());

    priorityLabel = std::make_shared<QLabel>();
    priorityLabel->setText("Select how high the priority of the task is:");
    layout.addWidget(priorityLabel.get());

    selectPriorityBox = std::make_shared<QComboBox>(this);
    selectPriorityBox->addItems(prios);
    layout.addWidget(selectPriorityBox.get());

    durationLabel = std::make_shared<QLabel>();
    durationLabel->setText("How many hours do you think this task will take?");
    layout.addWidget(durationLabel.get());

    durationTextEdit = std::make_shared<QTextEdit>(this);
    durationTextEdit->setGeometry(10, 10, 100, 10);
    layout.addWidget(durationTextEdit.get());

    dueDateLabel = std::make_shared<QLabel>();
    dueDateLabel->setText("When should this task be done?");
    layout.addWidget(dueDateLabel.get());

    dateLayout = std::make_shared<QHBoxLayout>(this);
    layout.addLayout(dateLayout.get());

    selectDayBox = std::make_shared<QComboBox>(this);
    selectDayBox->addItems(day);
    selectDayBox->setPlaceholderText("day");
    dateLayout->addWidget(selectDayBox.get());

    selectMonthBox = std::make_shared<QComboBox>(this);
    selectMonthBox->addItems(month);
    selectMonthBox->setPlaceholderText("month");
    dateLayout->addWidget(selectMonthBox.get());

    selectYearBox = std::make_shared<QComboBox>(this);
    selectYearBox->addItems(year);
    selectYearBox->setPlaceholderText("year");
    dateLayout->addWidget(selectYearBox.get());

    addTaskButton = std::make_shared<QPushButton>("Add Task", this);
    addTaskButton->setGeometry(10, 100, 80, 30);
    addTaskButton->setCheckable(true);
    layout.addWidget(addTaskButton.get());

    connect(addTaskButton.get(), SIGNAL (clicked(bool)), this, SLOT (addTaskClicked(bool)));
    connect(this, SIGNAL (isOver()), this, SLOT (closeAddTaskWindow()));
}

void AddTaskBox::setCategory(todolib::Category &category){
    this->category = std::make_shared<todolib::Category>(category);
}

void AddTaskBox::addTaskClicked(bool checked)
{
    if (checked) {
        this->addTaskButton->setChecked(false);
        std::string name{this->aTNameTextEdit->toPlainText().toStdString()};
        std::string description{this->aTDecriptionTextEdit->toPlainText().toStdString()};
        // category->addTask(todolib::Task(name, description));
        task = todolib::Task(name, description);
        hasTaskBool = true;
        task.setPriority(static_cast<todolib::Task::priority_t>(selectPriorityBox->currentIndex()));
        task.setDuration(this->durationTextEdit->toPlainText().toDouble());
        task.setdueDate(std::chrono::year_month_day(
                std::chrono::year(selectYearBox->currentIndex() + 2023),
                std::chrono::month(selectMonthBox->currentIndex() + 1),
                std::chrono::day(selectDayBox->currentIndex() + 1)
                ));
        emit isOver();
    }
}

bool AddTaskBox::hasTask() const {
    return hasTaskBool;
}

void AddTaskBox::closeAddTaskWindow() {
    this->hide();
}


