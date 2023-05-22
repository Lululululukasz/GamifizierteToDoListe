#ifndef PIC_AEM_PROJEKT_WINDOW_H
#define PIC_AEM_PROJEKT_WINDOW_H

#include "AddTaskBox.h"
#include "todolib/todolib.h"

#include <QWidget>
#include <QPushButton>
#include <memory>

class Window : public QWidget{

    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);

private slots:
    void openNewWindow(bool checked);

private:
    std::shared_ptr<QPushButton> taskButton;
    std::shared_ptr<AddTaskBox> taskBox;

    std::shared_ptr<todolib::ToDoList> mainList;
};


#endif //PIC_AEM_PROJEKT_WINDOW_H
