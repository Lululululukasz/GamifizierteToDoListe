#ifndef PIC_AEM_PROJEKT_CHECKBOX_H
#define PIC_AEM_PROJEKT_CHECKBOX_H
#include <QWidget>
#include <QCheckBox>


class CheckBox : public QWidget {


Q_OBJECT


public:
    explicit CheckBox(QWidget *parent = nullptr);


private:
    QCheckBox* cb;


private slots:
    void strikeout_task(int);


};
#endif //PIC_AEM_PROJEKT_CHECKBOX_H
