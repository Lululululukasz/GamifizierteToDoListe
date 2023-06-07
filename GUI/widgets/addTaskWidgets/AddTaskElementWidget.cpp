//
// Created by vera on 07.06.23.
//

#include "AddTaskElementWidget.h"

#include <utility>

AddTaskElementWidget::AddTaskElementWidget(QString elementName, QString invalidMessage, bool required, std::function<bool()> validate, QWidget* inputElement, QWidget *parent)
: validate(std::move(validate)) {
    mainLayout = std::make_shared<QVBoxLayout>(this);

    elementNameAndStarsLayout = std::make_shared<QHBoxLayout>();
    elementNameAndStarsLayout->setAlignment(Qt::AlignLeft);

    elementNameLabel = std::make_shared<QLabel>();
    elementNameLabel->setText(elementName);
    elementNameAndStarsLayout->addWidget(elementNameLabel.get());

    if(required) {
        starLabel = std::make_shared<QLabel>();
        starLabel->setText("*");
        starLabel->setStyleSheet("QLabel{color: orange;}");
        elementNameAndStarsLayout->addWidget(starLabel.get());
    }

    mainLayout->addLayout(elementNameAndStarsLayout.get());
    mainLayout->addWidget(inputElement);

    invalidLabel = std::make_shared<QLabel>();
    invalidLabel->setText(invalidMessage);
    invalidLabel->setHidden(true);
    invalidLabel->setStyleSheet("QLabel { color: red; }");
    mainLayout->addWidget(invalidLabel.get());
}

void AddTaskElementWidget::clearInvalidState() {
    invalidLabel->setHidden(true);
}

bool AddTaskElementWidget::updateInvalidState() {
    auto valid {validate()};
    invalidLabel->setHidden(valid);
    return valid;
}
