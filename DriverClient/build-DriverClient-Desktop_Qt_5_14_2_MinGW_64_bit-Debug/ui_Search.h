/********************************************************************************
** Form generated from reading UI file 'Search.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QGroupBox *groupBox;
    QTextEdit *DataViewEdit;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *Typelabel;
    QComboBox *SensorcomboBox;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *Beginlabel;
    QDateTimeEdit *BeginTimeEdit;
    QLabel *Endlabel;
    QDateTimeEdit *EndTimeEdit;
    QPushButton *SearchButton;

    void setupUi(QWidget *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName(QString::fromUtf8("Search"));
        Search->resize(699, 526);
        groupBox = new QGroupBox(Search);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 401, 481));
        DataViewEdit = new QTextEdit(groupBox);
        DataViewEdit->setObjectName(QString::fromUtf8("DataViewEdit"));
        DataViewEdit->setGeometry(QRect(20, 30, 361, 431));
        DataViewEdit->setReadOnly(true);
        groupBox_2 = new QGroupBox(Search);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(460, 20, 211, 101));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 195, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Typelabel = new QLabel(layoutWidget);
        Typelabel->setObjectName(QString::fromUtf8("Typelabel"));

        horizontalLayout->addWidget(Typelabel);

        SensorcomboBox = new QComboBox(layoutWidget);
        SensorcomboBox->setObjectName(QString::fromUtf8("SensorcomboBox"));

        horizontalLayout->addWidget(SensorcomboBox);

        groupBox_3 = new QGroupBox(Search);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(460, 160, 211, 191));
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 50, 162, 100));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Beginlabel = new QLabel(layoutWidget1);
        Beginlabel->setObjectName(QString::fromUtf8("Beginlabel"));

        verticalLayout->addWidget(Beginlabel);

        BeginTimeEdit = new QDateTimeEdit(layoutWidget1);
        BeginTimeEdit->setObjectName(QString::fromUtf8("BeginTimeEdit"));
        BeginTimeEdit->setDateTime(QDateTime(QDate(2024, 2, 19), QTime(0, 0, 0)));

        verticalLayout->addWidget(BeginTimeEdit);

        Endlabel = new QLabel(layoutWidget1);
        Endlabel->setObjectName(QString::fromUtf8("Endlabel"));

        verticalLayout->addWidget(Endlabel);

        EndTimeEdit = new QDateTimeEdit(layoutWidget1);
        EndTimeEdit->setObjectName(QString::fromUtf8("EndTimeEdit"));
        EndTimeEdit->setDateTime(QDateTime(QDate(2024, 2, 19), QTime(0, 0, 0)));

        verticalLayout->addWidget(EndTimeEdit);

        SearchButton = new QPushButton(Search);
        SearchButton->setObjectName(QString::fromUtf8("SearchButton"));
        SearchButton->setGeometry(QRect(480, 400, 181, 71));

        retranslateUi(Search);

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QWidget *Search)
    {
        Search->setWindowTitle(QCoreApplication::translate("Search", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Search", "\346\225\260\346\215\256\346\237\245\350\257\242", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Search", "\346\214\207\345\256\232\347\261\273\345\236\213", nullptr));
        Typelabel->setText(QCoreApplication::translate("Search", "<html><head/><body><p><span style=\" font-size:10pt;\">\344\274\240\346\204\237\345\231\250\347\261\273\345\236\213</span></p></body></html>", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Search", "\346\214\207\345\256\232\346\227\266\351\227\264", nullptr));
        Beginlabel->setText(QCoreApplication::translate("Search", "<html><head/><body><p><span style=\" font-size:10pt;\">\350\265\267\345\247\213\346\227\266\351\227\264\357\274\232</span></p></body></html>", nullptr));
        Endlabel->setText(QCoreApplication::translate("Search", "<html><head/><body><p><span style=\" font-size:10pt;\">\347\273\210\346\255\242\346\227\266\351\227\264\357\274\232</span></p></body></html>", nullptr));
        SearchButton->setText(QCoreApplication::translate("Search", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
