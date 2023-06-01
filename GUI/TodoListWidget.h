#ifndef PIC_AEM_PROJEKT_TODOLISTWIDGET_H
#define PIC_AEM_PROJEKT_TODOLISTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "TaskWidget.h"
#include "todolib/ToDoList.h"

class TodoListWidget : public QWidget {

    Q_OBJECT

public:
    explicit TodoListWidget(todolib::ToDoList& model, QWidget *parent = nullptr);

private:
    todolib::ToDoList& model;
    QVBoxLayout* layout;
    std::list<TaskWidget*> taskWidgets;

};


#endif //PIC_AEM_PROJEKT_TODOLISTWIDGET_H
