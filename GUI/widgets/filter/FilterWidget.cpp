//
// Created by vera on 06.06.23.
//

#include "FilterWidget.h"
#include <iomanip>
#include <sstream>

FilterWidget::FilterWidget(QWidget *parent) : QWidget(parent) {

    filterVLayout = std::make_shared<QVBoxLayout>();
    setLayout(filterVLayout.get());



    //priorityFilter
    filterForPriorityLabel = std::make_shared<QLabel>();
    filterForPriorityLabel->setText("Show task with these priorities:");
    filterVLayout->addWidget(filterForPriorityLabel.get());

    trivialPriorityCheckbox = std::make_shared<QCheckBox>();
    trivialPriorityCheckbox->setText("priority: trivial");
    filterVLayout->addWidget(trivialPriorityCheckbox.get());

    lowPriorityCheckbox = std::make_shared<QCheckBox>();
    lowPriorityCheckbox->setText("priority: low");
    filterVLayout->addWidget(lowPriorityCheckbox.get());

    mediumPriorityCheckbox = std::make_shared<QCheckBox>();
    mediumPriorityCheckbox->setText("priority: medium");
    filterVLayout->addWidget(mediumPriorityCheckbox.get());

    highPriorityCheckbox = std::make_shared<QCheckBox>();
    highPriorityCheckbox->setText("priority: high");
    filterVLayout->addWidget(highPriorityCheckbox.get());

    urgentPriorityCheckbox = std::make_shared<QCheckBox>();
    urgentPriorityCheckbox->setText("priority: urgent");
    filterVLayout->addWidget(urgentPriorityCheckbox.get());

    //DueDateFilter
    filterForDueDateLabel = std::make_shared<QLabel>();
    filterForDueDateLabel->setText("Show tasks due:");
    filterVLayout->addWidget(filterForDueDateLabel.get());

    todayCheckbox = std::make_shared<QCheckBox>();
    todayCheckbox->setText("today");
    filterVLayout->addWidget(todayCheckbox.get());

    tomorrowCheckbox = std::make_shared<QCheckBox>();
    tomorrowCheckbox->setText("tomorrow");
    filterVLayout->addWidget(tomorrowCheckbox.get());

    thisWeekCheckbox = std::make_shared<QCheckBox>();
    thisWeekCheckbox->setText("this week");
    filterVLayout->addWidget(thisWeekCheckbox.get());

    thisMonthCheckbox = std::make_shared<QCheckBox>();
    thisMonthCheckbox->setText("this month");
    filterVLayout->addWidget(thisMonthCheckbox.get());

    whenEverCheckbox = std::make_shared<QCheckBox>();
    whenEverCheckbox->setText("when ever");
    filterVLayout->addWidget(whenEverCheckbox.get());

    //DurationFilter
    durationFilterHBox = std::make_shared<QHBoxLayout>();
    filterVLayout->addLayout(durationFilterHBox.get());
    durationFilterHBox->setAlignment(Qt::AlignLeft);

    filterForDurationLabel = std::make_shared<QLabel>();
    filterForDurationLabel->setText("Show tasks that take:");
    durationFilterHBox->addWidget(filterForDurationLabel.get(), 0,Qt::AlignLeft | Qt::AlignVCenter);

    showDurationFilterButton = std::make_shared<QToolButton>();
    showDurationFilterButton->setCheckable(true);
    showDurationFilterButton->setArrowType(Qt::RightArrow);
    showDurationFilterButton->setStyleSheet("QToolButton{border: none;}");
    durationFilterHBox->addWidget(showDurationFilterButton.get(), 0, Qt::AlignLeft | Qt::AlignVCenter);

    std::list<double> limits { 0.5, 1, 2, 3, 5, 10, 12 };
    for(auto const& limit : limits) {
        createDurationRadioButton(limit, false);
    }
    createDurationRadioButton(limits.back(), true);
    createDurationRadioButton(std::numeric_limits<double>::infinity(), false);
    durationRadioButtons.back()->setChecked(true);

    connect(showDurationFilterButton.get(), &QToolButton::toggled, [=,this](bool checked) {
        showDurationFilterButton->setArrowType(checked ? Qt::ArrowType::DownArrow : Qt::ArrowType::RightArrow);
        if (checked) showDurationFilter();
        else hideDurationFilter();
    });
}

void FilterWidget::createDurationRadioButton(double limit, bool more) {
    auto radioButton {std::make_shared<QRadioButton>()};
    std::stringstream label;
    if(limit > 1000) {
        label << "show all";
    } else {
        label << (more ? ">=" : "<");
        label << " ";
        label << std::setprecision(3) << limit;
    }
    radioButton->setHidden(true);
    radioButton->setText(QString::fromStdString(label.str()));
    filterVLayout->addWidget(radioButton.get());
    durationRadioButtons.push_back(radioButton);
}

void FilterWidget::showDurationFilter() {
    for(auto const& radioButton : durationRadioButtons) {
        radioButton->setHidden(false);
    }
}

void FilterWidget::hideDurationFilter() {
    for(auto const& radioButton : durationRadioButtons) {
        radioButton->setHidden(true);
    }
}
