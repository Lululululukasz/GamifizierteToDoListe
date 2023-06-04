//
// Created by vera on 03.06.23.
//

#include <QLayout>
#include "PageLayoutWidget.h"

PageLayoutWidget::PageLayoutWidget(std::shared_ptr<QLayout> layout) {
    this->setLayout(layout.get());
}
