//
// Created by Jan Ole Weighardt on 23.05.23.
//

#ifndef AEMPROJEKT_CATEGORYWIDGET_H
#define AEMPROJEKT_CATEGORYWIDGET_H

#include "todolib/todolib.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QInputDialog>
#include <QWidget>


class CategoryWidget:public QWidget {

Q_OBJECT

public:
    explicit CategoryWidget(const QString& name, QList<QStringList>& categories, QVBoxLayout& layout, int index);

public slots:
    void deleteCategory();

private:
    QString m_name;
    QList<QStringList>& m_categories;
    QVBoxLayout* m_layout;
    int m_index;
    QLabel* m_label;

    void updateIndexes();
    void updateIndex(int newIndex);
};

#endif //AEMPROJEKT_CATEGORYWIDGET_H
