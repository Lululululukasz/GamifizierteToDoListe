//
// Created by vera on 08.06.23.
//

#ifndef PIC_AEM_PROJEKT_EDITTASKBOX_H
#define PIC_AEM_PROJEKT_EDITTASKBOX_H

#include "GUI/popups/AddTaskBox.h"

class EditTaskBox : public AddTaskBox {
Q_OBJECT
public:
    explicit EditTaskBox(todolib::Task& task, QWidget *parent = nullptr);

protected slots:
    void addTaskClicked(bool checked) override;

protected:
    todolib::Task& editTask;

};


#endif //PIC_AEM_PROJEKT_EDITTASKBOX_H
