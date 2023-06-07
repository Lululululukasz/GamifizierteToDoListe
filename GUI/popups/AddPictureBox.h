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
#include "GUI/widgets/addTaskWidgets/AddPictureBoxElementWidget.h"

class AddPictureBox : public QWidget {
    Q_OBJECT
public:
    explicit AddPictureBox(QWidget *parent = nullptr);

    signals:
   void picturePathSignal(std::string picturePath);
private:
    std::shared_ptr<QVBoxLayout> addPictureVLayout;
    std::shared_ptr<QHBoxLayout> noPictureHLayout;
    std::list<std::shared_ptr<AddPictureBoxElementWidget>> elements;
    std::shared_ptr<QRadioButton> noPictureButton;
    std::shared_ptr<AddPictureBoxElementWidget> elementWidget;

private slots:
    void closeAddPictureBox();
    void pictureSelected(std::string pic);

};


#endif //PIC_AEM_PROJEKT_ADDPICTUREBOX_H
