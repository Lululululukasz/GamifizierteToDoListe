//
// Created by vera on 07.06.23.
//

#ifndef PIC_AEM_PROJEKT_ADDPICTUREBOXELEMENTWIDGET_H
#define PIC_AEM_PROJEKT_ADDPICTUREBOXELEMENTWIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QLabel>
#include <QHBoxLayout>
#include <memory>
#include <QPixmap>

class AddPictureBoxElementWidget : public QWidget {
    Q_OBJECT
public:
    explicit AddPictureBoxElementWidget(
            std::string picturePath,
            QWidget *parent = nullptr
                    );

private:
    std::shared_ptr<QHBoxLayout> pictureLayout;
    std::shared_ptr<QRadioButton> pictureRadioButton;
    std::shared_ptr<QLabel> pictureLabel;



};


#endif //PIC_AEM_PROJEKT_ADDPICTUREBOXELEMENTWIDGET_H
