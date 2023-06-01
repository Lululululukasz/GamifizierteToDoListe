//
// Created by Jan Ole Weighardt on 26.05.23.
//

#ifndef AEMPROJEKT_XPWIDGET_H
#define AEMPROJEKT_XPWIDGET_H
#include <QWidget>
#include "todolib/todolib.h"
#include "CategoryWidget.h"
#include <QLabel>
#include <QVBoxLayout>



class XpWidget : public QWidget {
    Q_OBJECT
    public:
        explicit XpWidget(/*todolib::ToDoList &toDoList,*/ QWidget *parent = nullptr);
    /*todolib::ToDoList &xpobjekt;*/
    int xpWidgetZahl;

public slots:
    void xpWidgetFunc(bool xpWidgetbool);

    private:
        std::shared_ptr<QLabel> xpLabel;
        std::shared_ptr<QVBoxLayout> xpLayout;

    };



#endif //AEMPROJEKT_XPWIDGET_H
