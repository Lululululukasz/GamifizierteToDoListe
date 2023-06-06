//
// Created by helen on 30.05.2023.
//

#include "Page.h"
#include <QStyle>
#include <QTimer>
#include <utility>

Page::Page(todolib::Profile & profile) : profile{profile} {
    stackedLayout.addWidget(&layoutWidget);
    stackedLayout.setStackingMode(QStackedLayout::StackAll);

    // hNavBar
    closeButton->setIcon(closeButton->style()->standardIcon(QStyle::SP_ArrowBack));
    layoutWidget.hNavBar->addWidget(closeButton.get(), 0, Qt::AlignLeft);
    connect(closeButton.get(), SIGNAL(clicked()), this, SIGNAL(closePageSignal()));

    // XP-Bar
    //layoutWidget.vBodyLayout->addWidget(&placeholderXP);
    addXpWidget();
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
void Page::addXpWidget(){
    std::shared_ptr<XpWidget> xpWidget = std::make_shared<XpWidget>(profile.xp);
    xpWidgets.push_back(xpWidget);
    layoutWidget.vBodyLayout->addWidget(xpWidget.get(),0,Qt::AlignTop);
    connect(this, &Page::xpWidgetSignal1, xpWidget.get(), &XpWidget::xpWidgetFunc1);
    connect(this, &Page::xpWidgetSignal2, xpWidget.get(), &XpWidget::xpWidgetFunc2);
}
