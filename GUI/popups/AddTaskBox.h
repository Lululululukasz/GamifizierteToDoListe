#ifndef PIC_AEM_PROJEKT_ADDTASKBOX_H
#define PIC_AEM_PROJEKT_ADDTASKBOX_H

#include "todolib/todolib.h"

#include <QWidget>
#include <memory>
#include <QPushButton>
#include <QTextEdit>
#include <QLayout>
#include <QLabel>
#include <QComboBox>

class AddTaskBox : public QWidget {
Q_OBJECT
public:
    explicit AddTaskBox(QWidget *parent = nullptr);

    void setCategory(todolib::Category &category);

    todolib::Task task;

    [[nodiscard]] bool hasTask() const;

signals:

    void isOver();

private slots:

    void addTaskClicked(bool checked);

    void closeAddTaskWindow();


private:
    bool hasTaskBool{false};
    QVBoxLayout layout {QVBoxLayout(this)};
    std::shared_ptr<QPushButton> addTaskButton;
    QLabel nameLabel {QLabel()};
    std::shared_ptr<QTextEdit> aTNameTextEdit;
    QLabel descLabel {QLabel()};
    std::shared_ptr<QTextEdit> aTDecriptionTextEdit;
    std::shared_ptr<QComboBox> selectPriorityBox;
    QStringList prios {"trivial", "low", "medium", "high", "urgent"};
    std::shared_ptr<QLabel> priorityLabel;

    std::shared_ptr<todolib::Category> category;
};

#endif //PIC_AEM_PROJEKT_ADDTASKBOX_H
