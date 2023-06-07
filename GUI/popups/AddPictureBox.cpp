//
// Created by vera on 07.06.23.
//

#include "AddPictureBox.h"

AddPictureBox::AddPictureBox(QWidget *parent) {

    //setFixedSize(400, 400);

    testLayout = std::make_shared<QVBoxLayout>(this);
    elements.push_back(std::make_shared<AddPictureBoxElementWidget>(
            "/resources/cleaning_pic.png"
            ));
    elements.push_back(std::make_shared<AddPictureBoxElementWidget>(
            "/resources/cleaning_pic_two.png"
    ));
    for(auto const& element : elements){
        testLayout->addWidget(element.get());
    }
}
