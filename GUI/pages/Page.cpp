//
// Created by helen on 30.05.2023.
//

#include "Page.h"
#include <QStyle>
#include <QTimer>
#include <utility>

Page::Page(todolib::ToDoList &toDoList) : toDoList{toDoList} {
    stackedLayout.addWidget(&layoutWidget);

    // hNavBar
    closeButton->setIcon(closeButton->style()->standardIcon(QStyle::SP_ArrowBack));
    layoutWidget.hNavBar->addWidget(closeButton.get(), 0, Qt::AlignLeft);
    connect(closeButton.get(), SIGNAL(clicked()), this, SIGNAL(closePageSignal()));

    // XP-Bar
    // vBodyLayout->addWidget();
}

/**
 * This adds an overlay widget to the stacked vOuterLayout which
 * is automatically removed after 2 seconds.
 *
 * @param _overlay Widget to overlay
 */
void Page::setOverlay(std::shared_ptr<QWidget> _overlay) {
    this->overlay = std::move(_overlay);
    stackedLayout.insertWidget(1, this->overlay.get());
    stackedLayout.setCurrentIndex(1);

    auto *overlayRemoveTimer = new QTimer(this);
    connect(overlayRemoveTimer, &QTimer::timeout, [overlayRemoveTimer, this] {
        delete overlayRemoveTimer;
        stackedLayout.removeWidget(this->overlay.get());
        this->overlay = nullptr;
    });
    overlayRemoveTimer->start(2000);
}
