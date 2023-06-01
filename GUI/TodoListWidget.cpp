#include "TodoListWidget.h"
#include "todolib/Task.h"
#include "TaskWidget.h"
#include "todolib/ToDoList.h"

TodoListWidget::TodoListWidget(todolib::ToDoList& model, QWidget *parent) : model{model}, QWidget{parent} {
    layout = new QVBoxLayout(this);
    auto& category {model.getCategoryByName("General")};
    for(auto& task : category.tasks) {
        auto* taskWidget {new TaskWidget {task}};
        layout->addWidget(taskWidget, 0, Qt::AlignTop);
        taskWidgets.push_back(taskWidget);
        connect(taskWidget, &TaskWidget::taskDeleted, this, [=, this](){
            taskWidgets.remove(taskWidget);
            delete taskWidget;
        });
    }
}