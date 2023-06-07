//
// Created by vera on 07.06.23.
//

#ifndef PIC_AEM_PROJEKT_ADDTASKELEMENTWIDGET_H
#define PIC_AEM_PROJEKT_ADDTASKELEMENTWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <memory>
#include <QLabel>

class AddTaskElementWidget : public QWidget {
Q_OBJECT
public:
    explicit AddTaskElementWidget(
            QString elementName,
            QString invalidMessage,
            bool required,
            std::function<bool()> validate,
            QWidget* inputElement,
            QWidget *parent = nullptr
        );
    bool updateInvalidState();
    void clearInvalidState();

private:
    std::function<bool()> validate;
    std::shared_ptr<QVBoxLayout> mainLayout;
    std::shared_ptr<QHBoxLayout> elementNameAndStarsLayout;
    std::shared_ptr<QLabel> elementNameLabel;
    std::shared_ptr<QLabel> starLabel;
    std::shared_ptr<QLabel> invalidLabel;

};


#endif //PIC_AEM_PROJEKT_ADDTASKELEMENTWIDGET_H
