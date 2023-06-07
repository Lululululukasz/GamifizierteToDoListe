#ifndef PIC_AEM_PROJEKT_ADDTASKBOX_H
#define PIC_AEM_PROJEKT_ADDTASKBOX_H

#include "todolib/todolib.h"
#include "GUI/widgets/addTaskWidgets/DatePickerWidget.h"
#include "GUI/widgets/addTaskWidgets/AddTaskElementWidget.h"

#include <QWidget>
#include <memory>
#include <vector>
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

    std::vector<std::shared_ptr<AddTaskElementWidget>> elements;

    std::shared_ptr<QPushButton> addTaskButton;
    std::shared_ptr<QTextEdit> nameTextEdit;
    std::shared_ptr<QTextEdit> descriptionTextEdit;
    std::shared_ptr<QComboBox> selectPriorityBox;
    QStringList prios {"select a priority", "trivial", "low", "medium", "high", "urgent"};
    std::shared_ptr<QTextEdit> durationTextEdit;
    std::shared_ptr<DatePickerWidget> datePicker;

    std::shared_ptr<todolib::Category> category;

    /**
     * checks if the date the user entered is in the past
     * @return true of false
     */
    bool pastDate();
    /**
     * checks if there were any invalid inputs
     * @return true of false
     */
    bool invalidInput();
};

#endif //PIC_AEM_PROJEKT_ADDTASKBOX_H
