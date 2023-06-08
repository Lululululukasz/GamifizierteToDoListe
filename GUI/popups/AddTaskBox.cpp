#include "GUI/popups/AddTaskBox.h"
#include "GUI/widgets/addTaskWidgets/DatePickerWidget.h"
#include "GUI/widgets/addTaskWidgets/AddTaskElementWidget.h"

#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QApplication>
#include <QStringList>
#include <iostream>
#include <cmath>
#include <utility>

AddTaskBox::AddTaskBox(QWidget *parent) : QWidget(parent), task(todolib::Task("", "")) {
    setFixedSize(400, 600);

    nameTextEdit = std::make_shared<QTextEdit>(this);
    nameTextEdit->setGeometry(10, 10, 100, 10);
    elements.push_back(std::make_shared<AddTaskElementWidget>(
            "Task Name",
            "Please enter a name",
            true,
            [this] { return nameTextEdit->toPlainText().toStdString().length() > 0; },
            nameTextEdit.get()
        ));
    connect(nameTextEdit.get(), &QTextEdit::textChanged, [=,this]{
        elements[0]->clearInvalidState();
    });

    descriptionTextEdit = std::make_shared<QTextEdit>(this);
    descriptionTextEdit->setGeometry(10, 40, 200, 60);
    elements.push_back(std::make_shared<AddTaskElementWidget>(
            "Task Description",
            "",
            false,
            [] { return true; },
            descriptionTextEdit.get()
        ));

    selectPriorityBox = std::make_shared<QComboBox>(this);
    selectPriorityBox->addItems(prios);
    elements.push_back(std::make_shared<AddTaskElementWidget>(
            "Priority",
            "Please enter a priorityFilter.",
            true,
            [this] { return selectPriorityBox->currentIndex() > 0; },
            selectPriorityBox.get()
        ));
    connect(selectPriorityBox.get(), static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [=,this]{
        elements[2]->clearInvalidState();
    });

    durationTextEdit = std::make_shared<QTextEdit>(this);
    durationTextEdit->setGeometry(10, 10, 100, 10);
    durationTextEdit->setPlaceholderText("Please enter a number");
    elements.push_back(std::make_shared<AddTaskElementWidget>(
            "How many hours do you think this will take?",
            "Please enter a number",
            false,
            [this] {
                if(durationTextEdit->toPlainText().toStdString().length() == 0) {
                    return true;
                }
                try {
                    std::stod(durationTextEdit->toPlainText().toStdString());
                } catch(std::exception &notANumber) {
                    return false;
                }
                return true;
            },
            durationTextEdit.get()
        ));
    connect(durationTextEdit.get(), &QTextEdit::textChanged, [=,this]{
        elements[3]->clearInvalidState();
    });

    datePicker = std::make_shared<DatePickerWidget>();
    elements.push_back(std::make_shared<AddTaskElementWidget>(
            "When should this task be done?",
            "Please enter a valid date.",
            true,
            [this] { return !datePicker->invalidDate() && !pastDate(); },
            datePicker.get()
        ));
    connect(datePicker.get(), &DatePickerWidget::hideInvalidDateSignal, [=,this]{
        elements[4]->clearInvalidState();
    });

    for(auto const& element : elements) {
        layout.addWidget(element.get());
    }

    addPictureButton = std::make_shared<QPushButton>();
    addPictureButton->setText("Add a picture");
    addPictureButton->setIcon(QIcon(Globals::homepath+"/resources/material_design_plus.png"));
    addPictureButton->setStyleSheet("QPushButton{border: none; margin-bottom: 15px}");
    addPictureButton->setCheckable(true);
    layout.addWidget(addPictureButton.get());
    connect(addPictureButton.get(), SIGNAL(clicked(bool)), this, SLOT (openAddPictureWindow(bool)));

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

bool AddTaskBox::pastDate() {
    auto now = std::chrono::system_clock::now();
    auto today = std::chrono::floor<std::chrono::days>(now);
    std::chrono::year_month_day dateToday{today};
    std::chrono::year_month_day dueDate = datePicker->createDueDate();
    if(dueDate < dateToday){
        return true;
    } else {
        return false;
    }
}

bool AddTaskBox::invalidInput() {
    auto valid {true};
    for(auto const& element : elements) {
        if(!element->updateInvalidState()) {
            valid = false;
        }
    }
    return !valid;
}

void AddTaskBox::openAddPictureWindow(bool checked) {
if(checked){
    this->addPictureButton->setChecked(false);
    addPictureBox = std::make_shared<AddPictureBox>();
    addPictureBox->show();
    connect(addPictureBox.get(), &AddPictureBox::picturePathSignal, this, &AddTaskBox::savePicturePath);
    connect(addPictureBox.get(), &AddPictureBox::noPictureSelectedSignal, this, &AddTaskBox::noPicturePath);
}
}


void AddTaskBox::addTaskClicked(bool checked)
{
    if (checked) {
        if(invalidInput()){
            this->addTaskButton->setChecked(false);
        } else {
            this->addTaskButton->setChecked(false);
            std::string name{this->nameTextEdit->toPlainText().toStdString()};
            std::string description{this->descriptionTextEdit->toPlainText().toStdString()};
            // category.addTask(todolib::Task(name, description));
            task = todolib::Task(name, description);
            hasTaskBool = true;
            task.setPriority(static_cast<todolib::Task::priority_t>(selectPriorityBox->currentIndex()));
            task.setDuration(this->durationTextEdit->toPlainText().toDouble());
            task.setDueDate(datePicker->createDueDate());
            task.setPicture(picturePath);
            emit isOver();
        }
    }
}

void AddTaskBox::savePicturePath(std::string picture) {
    picturePath  = picture;
}

bool AddTaskBox::hasTask() const {
    return hasTaskBool;
}

void AddTaskBox::closeAddTaskWindow() {
    this->hide();
}

void AddTaskBox::noPicturePath() {
    picturePath = "";
}


