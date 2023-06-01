#ifndef PIC_AEM_PROJEKT_CHECKBOX_H
#define PIC_AEM_PROJEKT_CHECKBOX_H
#include "todolib/Task.h"
#include "XpWidget.h"
#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QToolButton>
#include <QLabel>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QVBoxLayout>


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
    void xpWidgetSignal(bool xpsignal);
private:

    std::shared_ptr<QHBoxLayout> hbox;
    std::shared_ptr<QVBoxLayout> vbox;
    std::shared_ptr<QCheckBox> taskCheckbox;
    std::shared_ptr<QLabel> taskNameLabel;
    std::shared_ptr<QPushButton> taskDeleteButton;
    std::shared_ptr<QToolButton> showDescriptionButton;
    std::shared_ptr<QLabel> taskDescriptionLabel;

private slots:
    void strikeoutTask(int state);
    void deleteTask();
    void showDescription();
    void hideDescription();

};
#endif //PIC_AEM_PROJEKT_CHECKBOX_H
