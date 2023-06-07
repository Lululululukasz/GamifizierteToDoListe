#ifndef PIC_AEM_PROJEKT_CHECKBOX_H
#define PIC_AEM_PROJEKT_CHECKBOX_H
#include "todolib/todo-System/Task.h"
#include "GUI/ConfettiAnimation/DrawConfetti.h"
#include "GUI/pages/Page.h"

#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QToolButton>
#include <QLabel>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsScene>


/** The hbox is the horizontal box that is the first element in the vertical box vbox. It
 * consists of the taskNameLabel, the taskCheckbox, which when checked
 * strikes out the taskNameLabel and plays a sound, the taskDeleteButton which when pressed emits the deleteTaskSignal
 * and the showDescriptionButton, which when checked adds the taskDescriptionLabel to the vbox.
 */


class TaskWidget : public QWidget {

Q_OBJECT

public:
    explicit TaskWidget(todolib::Task &task, Page &page, QWidget *parent = nullptr);

    todolib::Task &task;

signals:
    void deleteTaskSignal();
    void xpWidgetSignalAdd();
    void xpWidgetSignalSub();
    void taskMarkedChanged();

private:
    Page &page;
    std::shared_ptr<QHBoxLayout> hbox;
    std::shared_ptr<QVBoxLayout> vbox;
    std::shared_ptr<QCheckBox> taskCheckbox;
    std::shared_ptr<QLabel> taskNameLabel;
    std::shared_ptr<QPushButton> taskDeleteButton;
    std::shared_ptr<QToolButton> showDescriptionButton;
    std::shared_ptr<QLabel> taskDescriptionLabel;
    std::shared_ptr<QLabel> taskPriorityLabel;
    std::shared_ptr<QLabel> taskDurationLabel;
    std::shared_ptr<QLabel> taskDueDateLabel;
    std::shared_ptr<QFont> font;
    std::shared_ptr<DrawConfetti> confetti;
    std::shared_ptr<QGraphicsScene> scene;


    static void playRandomSound();
    void playConfettiAnimation();

private slots:
    void taskDone();
    void taskUndone();
    void deleteTask();
    void showDescription();
    void hideDescription();
};
#endif //PIC_AEM_PROJEKT_CHECKBOX_H
