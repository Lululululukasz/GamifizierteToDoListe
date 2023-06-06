//
// Created by vera on 06.06.23.
//

#ifndef PIC_AEM_PROJEKT_FILTERWIDGET_H
#define PIC_AEM_PROJEKT_FILTERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QRadioButton>
#include <memory>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>

class FilterWidget : public QWidget {

    Q_OBJECT

public:
    explicit FilterWidget(QWidget *parent = nullptr);

private:

    std::shared_ptr<QVBoxLayout> filterVLayout;
    std::shared_ptr<QLabel> filterForPriorityLabel;
    std::shared_ptr<QCheckBox> trivialPriorityCheckbox;
    std::shared_ptr<QCheckBox> lowPriorityCheckbox;
    std::shared_ptr<QCheckBox> mediumPriorityCheckbox;
    std::shared_ptr<QCheckBox> highPriorityCheckbox;
    std::shared_ptr<QCheckBox> urgentPriorityCheckbox;

    std::shared_ptr<QLabel> filterForDueDateLabel;
    std::shared_ptr<QCheckBox> todayCheckbox;
    std::shared_ptr<QCheckBox> tomorrowCheckbox;
    std::shared_ptr<QCheckBox> thisWeekCheckbox;
    std::shared_ptr<QCheckBox> thisMonthCheckbox;
    std::shared_ptr<QCheckBox> whenEverCheckbox;

    std::shared_ptr<QHBoxLayout> durationFilterHBox;
    std::shared_ptr<QLabel> filterForDurationLabel;
    std::shared_ptr<QToolButton> showDurationFilterButton;
    std::list<std::shared_ptr<QRadioButton>> durationRadioButtons;
    void createDurationRadioButton(double limit, bool more);
    void showDurationFilter();
    void hideDurationFilter();

};


#endif //PIC_AEM_PROJEKT_FILTERWIDGET_H
