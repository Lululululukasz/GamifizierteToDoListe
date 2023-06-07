//
// Created by vera on 06.06.23.
//

#include "DatePickerWidget.h"


DatePickerWidget::DatePickerWidget(QWidget *parent) {
    dateLayout = std::make_shared<QHBoxLayout>(this);

    selectDayBox = std::make_shared<QComboBox>(this);
    selectDayBox->addItems(days);
    dateLayout->addWidget(selectDayBox.get());

    selectMonthBox = std::make_shared<QComboBox>(this);
    selectMonthBox->addItems(months);
    dateLayout->addWidget(selectMonthBox.get());

    selectYearBox = std::make_shared<QComboBox>(this);
    selectYearBox->addItems(years);
    dateLayout->addWidget(selectYearBox.get());

    connect(selectDayBox.get(), static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &DatePickerWidget::hideInvalidSignal);
    connect(selectMonthBox.get(), static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &DatePickerWidget::hideInvalidSignal);
    connect(selectYearBox.get(), static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &DatePickerWidget::hideInvalidSignal);
}

void DatePickerWidget::hideInvalidSignal() {
    emit hideInvalidDateSignal();
}

bool DatePickerWidget::invalidDate() {

    int day = selectDayBox->currentIndex();
    int month = selectMonthBox->currentIndex();
    int year = selectYearBox->currentIndex() + 2022;

    if(day == 0 || month == 0 || year == 0) {
        return true;
    } else if(day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)){
        return true;
    } else if(day == 30 && month == 2 ){
        return true;
    } else if(day == 29 && month == 2 && !(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))){
        return true;
//    } else if (pastDate()) {
//        return true;
    } else {
        return false;
    }
}

std::chrono::year_month_day DatePickerWidget::createDueDate() {
    std::chrono::year_month_day dueDate {std::chrono::year(selectYearBox->currentIndex() + 2022),
                                         std::chrono::month(selectMonthBox->currentIndex()),
                                         std::chrono::day(selectDayBox->currentIndex())};

    return dueDate;
}


