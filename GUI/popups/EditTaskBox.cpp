//
// Created by vera on 08.06.23.
//

#include "EditTaskBox.h"

EditTaskBox::EditTaskBox(todolib::Task &task, QWidget *parent) : editTask(task), AddTaskBox(parent) {
    addTaskButton->setText("Edit Task");
    nameTextEdit->setText(QString::fromStdString(task.name));
    descriptionTextEdit->setText(QString::fromStdString(task.description));
    selectPriorityBox->setCurrentIndex(static_cast<int>(task.getPriority()));
    durationTextEdit->setText(QString::fromStdString(std::to_string(task.getDuration())));
    datePicker->setDueDate(task.getDueDate());
}

void EditTaskBox::addTaskClicked(bool checked) {
    if (!checked) {
        return;
    }
    this->addTaskButton->setChecked(false);
    if(invalidInput()) {
        return;
    }
    hasTaskBool = true;
    editTask.name = this->nameTextEdit->toPlainText().toStdString();
    editTask.description = this->descriptionTextEdit->toPlainText().toStdString();
    editTask.setPriority(static_cast<todolib::Task::priority_t>(selectPriorityBox->currentIndex()));
    editTask.setDuration(this->durationTextEdit->toPlainText().toDouble());
    editTask.setDueDate(datePicker->createDueDate());
    emit isOver();
}

