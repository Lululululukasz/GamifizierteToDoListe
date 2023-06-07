//
// Created by vera on 07.06.23.
//

#include "AddPictureBoxElementWidget.h"
#include "utility/Globals.h"


AddPictureBoxElementWidget::AddPictureBoxElementWidget(std::string picturePath, QWidget *parent) {
    pictureLayout = std::make_shared<QHBoxLayout>(this);
    pictureRadioButton = std::make_shared<QRadioButton>();
    pictureLabel = std::make_shared<QLabel>();


    pictureLayout->setAlignment(Qt::AlignLeft);
    QPixmap picturePix(Globals::homepath+QString::fromStdString(picturePath));
    pictureLabel->setPixmap(picturePix.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    pictureRadioButton->setCheckable(true);

    pictureLayout->addWidget(pictureRadioButton.get());
    pictureLayout->addWidget(pictureLabel.get());
}
