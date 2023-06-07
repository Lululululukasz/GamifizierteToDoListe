#include "ConfirmDeleteWindow.h"
#include <QInputDialog>


ConfirmDeleteWindow::ConfirmDeleteWindow() {
    instructions.setText(QString::fromStdString("Are you sure you want to delete this Task?"));
    layout.addWidget(&instructions);

    layout.addWidget(&deleteButton);

    connect(&deleteButton, SIGNAL (clicked(bool)), this, SLOT (deleteButtonClicked(bool)));
    connect(&deleteButton, &QPushButton::clicked, this, &ConfirmDeleteWindow::confirmDelete);

    layout.addWidget(&cancelButton);
    connect(&cancelButton, &QPushButton::clicked, this, [&, this]() {this-> hide();});
    show();
}

void ConfirmDeleteWindow::deleteButtonClicked(bool checked)
{
    if (checked) {
        isConfirmed();
    }
}

bool ConfirmDeleteWindow::isConfirmed() const {
    return confirmedClick;
}
/*
void ConfirmDeleteWindow::catchDeleteTask() {
    ConfirmDeleteWindow();
}
void ConfirmDeleteWindow::openConfirmDeleteWindow() {
    openPopUp = std::make_shared<CategoryWidget>();
    connect(CategoryWidget.get(), &CategoryWidget::confirmDelete, this, CategoryWidget::catchConfirmDelete());
    //connect(widgetA, &WidgetAType::widgetASignal, widgetB, &WidgetBType::widgetBSlot);
}
 */