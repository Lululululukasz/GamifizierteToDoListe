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
#include <QPushButton>

class AddPictureBoxElementWidget : public QWidget {
    Q_OBJECT
public:
    explicit AddPictureBoxElementWidget(
            std::string picturePath,
            QWidget *parent = nullptr);
    signals:
    void pictureSelectedSignal(std::string picture);

private:
    std::string pic;
    std::shared_ptr<QHBoxLayout> pictureLayout;
    std::shared_ptr<QRadioButton> pictureRadioButton;
    std::shared_ptr<QLabel> pictureLabel;
    void pictureSelected();

};


#endif //PIC_AEM_PROJEKT_ADDPICTUREBOXELEMENTWIDGET_H
