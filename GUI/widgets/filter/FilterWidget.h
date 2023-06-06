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
#include <todolib/todolib.h>

class FilterWidget : public QWidget {

    Q_OBJECT

public:
    explicit FilterWidget(QWidget *parent = nullptr);

private:

    std::shared_ptr<QLabel> filterLabel;
    std::shared_ptr<QVBoxLayout> filterVLayout;

    std::shared_ptr<QHBoxLayout> priorityFilterHLayout;
    std::shared_ptr<QLabel> filterForPriorityLabel;
    std::shared_ptr<QToolButton> showPriorityFilterButton;
    std::list<std::shared_ptr<QCheckBox>> priorityCheckboxes;
    void createPriorityCheckbox(todolib::Task::priority_t priority);
    void showPriorityFilter();
    void hidePriorityFilter();

    std::shared_ptr<QHBoxLayout> dueDateFilterHLayout;
    std::shared_ptr<QLabel> filterForDueDateLabel;
    std::list<std::shared_ptr<QCheckBox>> dueDateCheckboxes;
    void createDueDateCheckbox(std::chrono::days lowerBound, std::chrono::days upperBound, std::string label);

    std::shared_ptr<QHBoxLayout> durationFilterHLayout;
    std::shared_ptr<QLabel> filterForDurationLabel;
    std::shared_ptr<QToolButton> showDurationFilterButton;
    std::list<std::shared_ptr<QRadioButton>> durationRadioButtons;
    void createDurationRadioButton(double limit, bool more);
    void showDurationFilter();
    void hideDurationFilter();

    void paintEvent(QPaintEvent *event) override;

};


#endif //PIC_AEM_PROJEKT_FILTERWIDGET_H
