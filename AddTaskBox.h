#ifndef PIC_AEM_PROJEKT_ADDTASKBOX_H
#define PIC_AEM_PROJEKT_ADDTASKBOX_H

#include <QWidget>
#include "todolib\todolib.h"

class QPushButton;
class QTextEdit;
class AddTaskBox : public QWidget{
Q_OBJECT
public:
    explicit AddTaskBox(QWidget *parent = 0);
    void setmainList(todolib::ToDoList &list);
signals:
    void isOver();
private slots:
    void addTaskClicked(bool checked);
private:
    QPushButton *addTaskButton;
    QTextEdit *aTNameTextEdit;
    QTextEdit *aTDecriptionTextEdit;

    todolib::ToDoList *mainList;
};

#endif //PIC_AEM_PROJEKT_ADDTASKBOX_H
