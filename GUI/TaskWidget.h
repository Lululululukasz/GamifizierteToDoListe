#ifndef PIC_AEM_PROJEKT_CHECKBOX_H
#define PIC_AEM_PROJEKT_CHECKBOX_H
#include "todolib/Task.h"
#include <QWidget>
#include <QCheckBox>
#include <QPushButton>


class TaskWidget : public QWidget {

Q_OBJECT

public:
    explicit TaskWidget(todolib::Task &task,QWidget *parent = nullptr);

signals:
    void taskDeleted();

private:
    todolib::Task &task;
    QCheckBox* taskcheckbox;
    QPushButton* taskdeletebutton;

private slots:
    void strikeout_task(int);
    void delete_task();

};
#endif //PIC_AEM_PROJEKT_CHECKBOX_H
