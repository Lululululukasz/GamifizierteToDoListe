//
// Created by vera on 06.06.23.
//

#include "FilterWidget.h"
#include <iomanip>
#include <sstream>
#include <QStyleOption>
#include <QPainter>

FilterWidget::FilterWidget(QWidget *parent) : QWidget(parent) {

    filterVLayout = std::make_shared<QVBoxLayout>();
    setStyleSheet("FilterWidget{border: 1px solid lightgray; background-color: white;}");
    setLayout(filterVLayout.get());

    filterLabel = std::make_shared<QLabel>();
    filterLabel->setText("Filter:");
    auto font {filterLabel->font()};
    font.setPointSize(static_cast<int>(font.pointSize() * 1.5));
    filterLabel->setFont(font);
    filterVLayout->addWidget(filterLabel.get());
    filterLabel->setStyleSheet("QLabel { border-bottom: 1px solid lightgray; padding-bottom: 0.5em; }");


    //priorityFilter
    priorityFilterHLayout = std::make_shared<QHBoxLayout>();
    priorityFilterHLayout->setAlignment(Qt::AlignLeft);

    filterForPriorityLabel = std::make_shared<QLabel>();
    filterForPriorityLabel->setText("Priority");
    priorityFilterHLayout->addWidget(filterForPriorityLabel.get());

    showPriorityFilterButton = std::make_shared<QToolButton>();
    showPriorityFilterButton->setCheckable(true);
    showPriorityFilterButton->setArrowType(Qt::RightArrow);
    showPriorityFilterButton->setStyleSheet("QToolButton{border: none;}");
    priorityFilterHLayout->addWidget(showPriorityFilterButton.get());

    filterVLayout->addLayout(priorityFilterHLayout.get());

    std::list<todolib::Task::priority_t> priorities {
        todolib::Task::trivial,
        todolib::Task::low,
        todolib::Task::medium,
        todolib::Task::high,
        todolib::Task::urgent
    };
    for(auto const& priority : priorities) {
        createPriorityCheckbox(priority);
    }

    connect(showPriorityFilterButton.get(), &QToolButton::toggled, [=,this](bool checked) {
        showPriorityFilterButton->setArrowType(checked ? Qt::ArrowType::DownArrow : Qt::ArrowType::RightArrow);
        if (checked) showPriorityFilter();
        else hidePriorityFilter();
    });

    //DueDateFilter
    filterForDueDateLabel = std::make_shared<QLabel>();
    filterForDueDateLabel->setText("Due on");
    filterVLayout->addWidget(filterForDueDateLabel.get());

    createDueDateCheckbox(std::chrono::days(0), std::chrono::days(0), "today");
    createDueDateCheckbox(std::chrono::days(1), std::chrono::days(1), "tomorrow");
    createDueDateCheckbox(std::chrono::days(0), std::chrono::days(7), "this week");
    createDueDateCheckbox(std::chrono::days(0), std::chrono::days(31), "this month");
    createDueDateCheckbox(std::chrono::days(-100000), std::chrono::days(100000), "whenever");

    //DurationFilter
    durationFilterHLayout = std::make_shared<QHBoxLayout>();
    filterVLayout->addLayout(durationFilterHLayout.get());
    durationFilterHLayout->setAlignment(Qt::AlignLeft);

    filterForDurationLabel = std::make_shared<QLabel>();
    filterForDurationLabel->setText("Duration");
    durationFilterHLayout->addWidget(filterForDurationLabel.get());

    showDurationFilterButton = std::make_shared<QToolButton>();
    showDurationFilterButton->setCheckable(true);
    showDurationFilterButton->setArrowType(Qt::RightArrow);
    showDurationFilterButton->setStyleSheet("QToolButton{border: none;}");
    durationFilterHLayout->addWidget(showDurationFilterButton.get());

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

void FilterWidget::createPriorityCheckbox(todolib::Task::priority_t priority) {
    auto checkBox {std::make_shared<QCheckBox>()};
    checkBox->setText(QString::fromStdString(todolib::Task::getPriorityString(priority)));
    checkBox->setChecked(true);
    filterVLayout->addWidget(checkBox.get());
    priorityCheckboxes.push_back(checkBox);
}

void FilterWidget::createDueDateCheckbox(std::chrono::days lowerBound, std::chrono::days upperBound, std::string label) {
    auto checkBox {std::make_shared<QCheckBox>()};
    checkBox->setText(QString::fromStdString(label));
    checkBox->setChecked(true);
    filterVLayout->addWidget(checkBox.get());
    dueDateCheckboxes.push_back(checkBox);
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

void FilterWidget::paintEvent(QPaintEvent *event) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
