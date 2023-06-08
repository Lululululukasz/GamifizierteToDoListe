//
// Created by vera on 07.06.23.
//

#ifndef PIC_AEM_PROJEKT_ADDPICTUREBOX_H
#define PIC_AEM_PROJEKT_ADDPICTUREBOX_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <memory>
#include <QHBoxLayout>
#include <QPushButton>
#include "GUI/widgets/addTaskWidgets/AddPictureBoxElementWidget.h"

class AddPictureBox : public QWidget {
    Q_OBJECT
public:
    explicit AddPictureBox(QWidget *parent = nullptr);

    signals:
   void picturePathSignal(std::string picturePath);
   void noPictureSelectedSignal();

private:
    std::shared_ptr<QVBoxLayout> addPictureVLayout;
    std::shared_ptr<QHBoxLayout> noPictureHLayout;
    std::list<std::shared_ptr<AddPictureBoxElementWidget>> elements;
    std::shared_ptr<QPushButton> noPictureButton;
    std::shared_ptr<AddPictureBoxElementWidget> elementWidget;

private slots:
    void closeAddPictureBox();
    void pictureSelected(std::string pic);
    void noPictureSelected();

};


#endif //PIC_AEM_PROJEKT_ADDPICTUREBOX_H
