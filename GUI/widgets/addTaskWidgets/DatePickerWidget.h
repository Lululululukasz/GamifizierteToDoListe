//
// Created by vera on 06.06.23.
//

#ifndef PIC_AEM_PROJEKT_DATEPICKERWIDGET_H
#define PIC_AEM_PROJEKT_DATEPICKERWIDGET_H

#include <QStringList>
#include <memory>
#include <QComboBox>
#include <QHBoxLayout>


class DatePickerWidget : public QWidget{
    Q_OBJECT
public:
    explicit DatePickerWidget(QWidget *parent = nullptr);
private:
    QStringList days {"select a days", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
    QStringList months {"select a months", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    QStringList years{"select a years", "2023", "2024", "2025", "2026", "2027", "2028", "2029", "2030", "2031", "2032", "2033"};
    std::shared_ptr<QComboBox> selectDayBox;
    std::shared_ptr<QComboBox> selectMonthBox;
    std::shared_ptr<QComboBox> selectYearBox;
    std::shared_ptr<QHBoxLayout> dateLayout;

    signals:
    void hideInvalidDateSignal();

private slots:
    void hideInvalidSignal();

public:
    std::chrono::year_month_day createDueDate();
    bool invalidDate();

};


#endif //PIC_AEM_PROJEKT_DATEPICKERWIDGET_H
