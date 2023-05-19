#ifndef PIC_AEM_PROJEKT_WINDOW_H
#define PIC_AEM_PROJEKT_WINDOW_H

#include <QWidget>
#include "AddTaskBox.h"
#include "todolib\todolib.h"

class QPushButton;
class Window : public QWidget{
Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);
    todolib::ToDoList getList();
private slots:
    void openNewWindow(bool checked);
private:
    QPushButton *taskButton;

    AddTaskBox *taskBox;

    todolib::ToDoList mainList;
};


#endif //PIC_AEM_PROJEKT_WINDOW_H
