#ifndef PIC_AEM_PROJEKT_CONFIRMDELETEWINDOW_H
#define PIC_AEM_PROJEKT_CONFIRMDELETEWINDOW_H

#include "todolib/todolib.h"
#include <QWidget>
#include <memory>
#include <QPushButton>
#include <QTextEdit>
#include <QLayout>
#include <QLabel>


class ConfirmDeleteWindow : public QWidget {
Q_OBJECT
signals:
    void confirmDelete();

public slots:
    void catchDeleteTask();
    void confirmInput();

public:
    explicit ConfirmDeleteWindow(QWidget *parent = nullptr);

private:
    QVBoxLayout layout{QVBoxLayout(this)};
    QPushButton deleteButton{QPushButton()};
    QPushButton cancelButton{QPushButton()};
    QLabel instructions{QLabel()};

};

#endif //PIC_AEM_PROJEKT_CONFIRMDELETEWINDOW_Hcx x