#ifndef PIC_AEM_PROJEKT_CHECKBOX_H
#define PIC_AEM_PROJEKT_CHECKBOX_H
#include "todolib/Task.h"
#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QToolButton>
#include <QLabel>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QVBoxLayout>


class TaskWidget : public QWidget {

Q_OBJECT

public:
    explicit TaskWidget(todolib::Task &task,QWidget *parent = nullptr);

signals:
    void taskDeleted();

private:
    todolib::Task &task;
    QHBoxLayout* hbox;
    QVBoxLayout* vbox;
    QCheckBox* taskCheckbox;
    QLabel* taskNameLabel;
    QPushButton* taskDeleteButton;
    QToolButton* showDescriptionButton;
    QLabel* taskDescriptionLabel;

private slots:
    void strikeoutTask(int state);
    void deleteTask();
    void showDescription();
    void hideDescription();

};
#endif //PIC_AEM_PROJEKT_CHECKBOX_H
