//
// Created by Jan Ole Weighardt on 23.05.23.
//

#include "GUI/CategoryWidget.h"

CategoryWidget::CategoryWidget(const QString& name, QList<QStringList>& categories, QVBoxLayout& layout, int index)
        : QWidget()
        , m_name(name)
        , m_categories(categories)
        , m_layout(&layout)
        , m_index(index)
{
    QVBoxLayout* categoryLayout = new QVBoxLayout(this);

    m_label = new QLabel(name);
    categoryLayout->addWidget(m_label);

    QPushButton* deleteButton = new QPushButton("Delete");
    categoryLayout->addWidget(deleteButton);

    connect(deleteButton, &QPushButton::clicked, this, &CategoryWidget::deleteCategory);

    setLayout(categoryLayout);
}

void CategoryWidget::deleteCategory()
{
    int index = m_layout->indexOf(this);
    QLayoutItem* item = m_layout->takeAt(index);
    delete item;

    m_categories.removeAt(m_index);
    m_label->clear();

    // Aktualisiere die Indexe der verbleibenden CategoryWidgets
    updateIndexes();

    parentWidget()->adjustSize();
}

void CategoryWidget::updateIndexes()
{
    // Aktualisiere die Indexe der CategoryWidgets, die sich nach dem gelÃ¶schten Widget befinden
    for (int i = m_index + 1; i < m_layout->count(); ++i)
    {
        QWidget* widget = m_layout->itemAt(i)->widget();
        if (widget)
        {
            CategoryWidget* categoryWidget = qobject_cast<CategoryWidget*>(widget);
            if (categoryWidget)
            {
                categoryWidget->updateIndex(i - 1);
            }
        }
    }
}

void CategoryWidget::updateIndex(int newIndex) {
    m_index = newIndex;
}