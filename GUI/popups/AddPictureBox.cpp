//
// Created by vera on 07.06.23.
//

#include "AddPictureBox.h"
#include "todolib/todolib.h"

AddPictureBox::AddPictureBox(QWidget *parent) : QWidget(parent) {

    //setFixedSize(400, 400);

    addPictureVLayout = std::make_shared<QVBoxLayout>(this);
    elements.push_back(std::make_shared<AddPictureBoxElementWidget>(
            "/resources/cleaning_pic.png"
            ));
    elements.push_back(std::make_shared<AddPictureBoxElementWidget>(
            "/resources/cleaning_pic_two.png"
    ));
    elements.push_back(std::make_shared<AddPictureBoxElementWidget>(
            "/resources/food_pic.png"
    ));
    elements.push_back(std::make_shared<AddPictureBoxElementWidget>(
            "/resources/sports_pic.png"
    ));
    elements.push_back(std::make_shared<AddPictureBoxElementWidget>(
            "/resources/study_pic.png"
    ));
    elements.push_back(std::make_shared<AddPictureBoxElementWidget>(
            "/resources/study_pic_two.png"
    ));
    for(auto const& element : elements){
        addPictureVLayout->addWidget(element.get());
        connect(element.get(), &AddPictureBoxElementWidget::pictureSelectedSignal, this, &AddPictureBox::pictureSelected);
    }


    noPictureButton = std::make_shared<QRadioButton>();
    noPictureButton->setCheckable(true);
    noPictureButton->setText("None");
    addPictureVLayout->addWidget(noPictureButton.get());
}

void AddPictureBox::closeAddPictureBox() {
    this->hide();
}

void AddPictureBox::pictureSelected(std::string pic) {
    closeAddPictureBox();
    emit picturePathSignal(pic);
}