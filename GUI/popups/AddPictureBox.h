//
// Created by vera on 07.06.23.
//

#ifndef PIC_AEM_PROJEKT_ADDPICTUREBOX_H
#define PIC_AEM_PROJEKT_ADDPICTUREBOX_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <memory>
#include "GUI/widgets/addTaskWidgets/AddPictureBoxElementWidget.h"

class AddPictureBox : public QWidget {
    Q_OBJECT
public:
    explicit AddPictureBox(QWidget *parent = nullptr);

private:
    std::shared_ptr<QVBoxLayout> testLayout;
    std::list<std::shared_ptr<AddPictureBoxElementWidget>> elements;

};


#endif //PIC_AEM_PROJEKT_ADDPICTUREBOX_H
