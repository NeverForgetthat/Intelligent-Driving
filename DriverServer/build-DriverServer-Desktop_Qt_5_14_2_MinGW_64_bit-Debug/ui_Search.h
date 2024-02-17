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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QGroupBox *groupBox;
    QTextEdit *CarDatatextEdit;
    QGroupBox *groupBox_2;
    QLineEdit *UserNameEdit;
    QGroupBox *groupBox_3;
    QComboBox *SensorcomboBox;
    QGroupBox *groupBox_4;
    QLabel *Beginlabel;
    QDateTimeEdit *BeginTimeEdit;
    QDateTimeEdit *EndTimeEdit;
    QLabel *Endlabel;
    QPushButton *SearchButton;

    void setupUi(QWidget *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName(QString::fromUtf8("Search"));
        Search->resize(705, 592);
        groupBox = new QGroupBox(Search);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 461, 571));
        CarDatatextEdit = new QTextEdit(groupBox);
        CarDatatextEdit->setObjectName(QString::fromUtf8("CarDatatextEdit"));
        CarDatatextEdit->setGeometry(QRect(10, 20, 441, 541));
        CarDatatextEdit->setReadOnly(true);
        groupBox_2 = new QGroupBox(Search);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(490, 20, 201, 91));
        UserNameEdit = new QLineEdit(groupBox_2);
        UserNameEdit->setObjectName(QString::fromUtf8("UserNameEdit"));
        UserNameEdit->setGeometry(QRect(10, 30, 181, 41));
        groupBox_3 = new QGroupBox(Search);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(490, 140, 201, 81));
        SensorcomboBox = new QComboBox(groupBox_3);
        SensorcomboBox->setObjectName(QString::fromUtf8("SensorcomboBox"));
        SensorcomboBox->setGeometry(QRect(20, 30, 161, 31));
        groupBox_4 = new QGroupBox(Search);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(490, 260, 201, 191));
        Beginlabel = new QLabel(groupBox_4);
        Beginlabel->setObjectName(QString::fromUtf8("Beginlabel"));
        Beginlabel->setGeometry(QRect(10, 30, 81, 21));
        BeginTimeEdit = new QDateTimeEdit(groupBox_4);
        BeginTimeEdit->setObjectName(QString::fromUtf8("BeginTimeEdit"));
        BeginTimeEdit->setGeometry(QRect(10, 60, 181, 31));
        BeginTimeEdit->setDateTime(QDateTime(QDate(2024, 2, 19), QTime(0, 0, 0)));
        EndTimeEdit = new QDateTimeEdit(groupBox_4);
        EndTimeEdit->setObjectName(QString::fromUtf8("EndTimeEdit"));
        EndTimeEdit->setGeometry(QRect(10, 140, 181, 31));
        EndTimeEdit->setDateTime(QDateTime(QDate(2024, 2, 19), QTime(0, 0, 0)));
        Endlabel = new QLabel(groupBox_4);
        Endlabel->setObjectName(QString::fromUtf8("Endlabel"));
        Endlabel->setGeometry(QRect(10, 110, 81, 21));
        SearchButton = new QPushButton(Search);
        SearchButton->setObjectName(QString::fromUtf8("SearchButton"));
        SearchButton->setGeometry(QRect(490, 480, 201, 71));

        retranslateUi(Search);

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QWidget *Search)
    {
        Search->setWindowTitle(QCoreApplication::translate("Search", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Search", "\350\275\246\350\276\206\346\225\260\346\215\256", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Search", "\347\224\250\346\210\267\345\220\215", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Search", "\346\225\260\346\215\256\347\261\273\345\236\213", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Search", "\346\227\266\351\227\264\347\255\233\351\200\211", nullptr));
        Beginlabel->setText(QCoreApplication::translate("Search", "<html><head/><body><p><span style=\" font-size:10pt;\">\350\265\267\345\247\213\346\227\266\351\227\264\357\274\232</span></p></body></html>", nullptr));
        Endlabel->setText(QCoreApplication::translate("Search", "<html><head/><body><p><span style=\" font-size:10pt;\">\346\210\252\346\255\242\346\227\266\351\227\264\357\274\232</span></p></body></html>", nullptr));
        SearchButton->setText(QCoreApplication::translate("Search", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
