#ifndef PIC_AEM_PROJEKT_ADDTASKBOX_H
#define PIC_AEM_PROJEKT_ADDTASKBOX_H

#include "todolib/todolib.h"

#include <QWidget>
#include <memory>
#include <QPushButton>
#include <QTextEdit>

class AddTaskBox : public QWidget {
Q_OBJECT
public:
    explicit AddTaskBox(QWidget *parent = nullptr);

    void setCategory(todolib::Category &category);

    todolib::Task task;

    bool hasTask();

signals:

    void isOver();

private slots:

    void addTaskClicked(bool checked);

    void closeAddTaskWindow();

private:
    bool hasTaskBool{false};
    std::shared_ptr<QPushButton> addTaskButton;
    std::shared_ptr<QTextEdit> aTNameTextEdit;
    std::shared_ptr<QTextEdit> aTDecriptionTextEdit;

    std::shared_ptr<todolib::Category> category;
};

#endif //PIC_AEM_PROJEKT_ADDTASKBOX_H
