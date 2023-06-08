//
// Created by vera on 07.06.23.
//

#include "AddPictureBoxElementWidget.h"

#include <utility>
#include "utility/Globals.h"
#include "GUI/popups/AddPictureBox.h"


AddPictureBoxElementWidget::AddPictureBoxElementWidget(std::string picturePath, QWidget *parent) : QWidget(parent), pic{picturePath} {
    pictureLayout = std::make_shared<QHBoxLayout>(this);
    pictureRadioButton = std::make_shared<QRadioButton>();
    pictureLabel = std::make_shared<QLabel>();

    pictureLayout->setAlignment(Qt::AlignLeft);
    QPixmap picturePix(Globals::homepath+QString::fromStdString(picturePath));
    pictureLabel->setPixmap(picturePix.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    pictureRadioButton->setCheckable(true);

    pictureLayout->addWidget(pictureRadioButton.get());
    pictureLayout->addWidget(pictureLabel.get());

    connect(pictureRadioButton.get(), &QRadioButton::clicked, this, &AddPictureBoxElementWidget::pictureSelected);
}

void AddPictureBoxElementWidget::pictureSelected() {
    emit pictureSelectedSignal(pic);
}
