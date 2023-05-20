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


private:
    QCheckBox* taskcheckbox;
    QPushButton* taskdeletebutton;


private slots:
    void strikeout_task(int);


};
#endif //PIC_AEM_PROJEKT_CHECKBOX_H
