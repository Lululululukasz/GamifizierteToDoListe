#ifndef PIC_AEM_PROJEKT_CHECKBOX_H
#define PIC_AEM_PROJEKT_CHECKBOX_H
#include "todolib/Task.h"
#include "ConfettiAnimation/DrawConfetti.h"

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
    explicit TaskWidget(todolib::Task &task, QWidget *parent = nullptr);

    todolib::Task &task;

signals:
    void deleteTaskSignal();

private:

    std::shared_ptr<QHBoxLayout> hbox;
    std::shared_ptr<QVBoxLayout> vbox;
    std::shared_ptr<QCheckBox> taskCheckbox;
    std::shared_ptr<QLabel> taskNameLabel;
    std::shared_ptr<QPushButton> taskDeleteButton;
    std::shared_ptr<QToolButton> showDescriptionButton;
    std::shared_ptr<QLabel> taskDescriptionLabel;
    std::shared_ptr<QFont> font;
    //std::shared_ptr<ConfettiVideo> confetti;
    std::shared_ptr<DrawConfetti> confetti;
//    std::list<std::shared_ptr<DrawConfetti>> drawConfetti;
//    std::list<std::shared_ptr<QPropertyAnimation>> confettiAnimation;
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
