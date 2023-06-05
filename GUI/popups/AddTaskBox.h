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
#include <QHBoxLayout>

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
    std::shared_ptr<QLabel> durationLabel;
    std::shared_ptr<QTextEdit> durationTextEdit;
    std::shared_ptr<QLabel> dueDateLabel;
    QStringList day {"day", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
    QStringList month {"month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    QStringList year{"year", "2023", "2024", "2025", "2026", "2027", "2028", "2029", "2030", "2031", "2032", "2033"};
    std::shared_ptr<QComboBox> selectDayBox;
    std::shared_ptr<QComboBox> selectMonthBox;
    std::shared_ptr<QComboBox> selectYearBox;
    std::shared_ptr<QHBoxLayout> dateLayout;
    std::shared_ptr<QLabel> invalidDateLabel;
    std::shared_ptr<todolib::Category> category;

    bool invalidDate();
};

#endif //PIC_AEM_PROJEKT_ADDTASKBOX_H
