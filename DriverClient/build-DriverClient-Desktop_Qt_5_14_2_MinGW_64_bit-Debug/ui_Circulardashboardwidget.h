/********************************************************************************
** Form generated from reading UI file 'Circulardashboardwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIRCULARDASHBOARDWIDGET_H
#define UI_CIRCULARDASHBOARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CircularDashboardWidget
{
public:

    void setupUi(QWidget *CircularDashboardWidget)
    {
        if (CircularDashboardWidget->objectName().isEmpty())
            CircularDashboardWidget->setObjectName(QString::fromUtf8("CircularDashboardWidget"));
        CircularDashboardWidget->resize(400, 300);

        retranslateUi(CircularDashboardWidget);

        QMetaObject::connectSlotsByName(CircularDashboardWidget);
    } // setupUi

    void retranslateUi(QWidget *CircularDashboardWidget)
    {
        CircularDashboardWidget->setWindowTitle(QCoreApplication::translate("CircularDashboardWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CircularDashboardWidget: public Ui_CircularDashboardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCULARDASHBOARDWIDGET_H
