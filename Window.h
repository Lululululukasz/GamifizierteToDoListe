#ifndef PIC_AEM_PROJEKT_WINDOW_H
#define PIC_AEM_PROJEKT_WINDOW_H

#include <QWidget>
#include "todolib\todolib.h"

class QPushButton;
class QTextEdit;
class Window : public QWidget
{
Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);
private slots:
    void addTaskClicked(bool checked);
private:
    QPushButton *addTaskButton;
    QTextEdit *aTNameTextEdit;
    QTextEdit *aTDecriptionTextEdit;

    todolib::ToDoList mainList;
};

#endif //PIC_AEM_PROJEKT_WINDOW_H
