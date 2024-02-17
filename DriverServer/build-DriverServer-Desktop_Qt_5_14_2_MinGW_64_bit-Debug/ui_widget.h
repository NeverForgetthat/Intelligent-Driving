/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QTextEdit *CarDataEdit;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QTextEdit *MsgViewEdit;
    QTextEdit *MsgSendEdit;
    QPushButton *MsgSendButton;
    QGroupBox *groupBox_4;
    QPushButton *StartButton;
    QLabel *Linklabel;
    QLabel *StateViewlabel;
    QPushButton *PauseButton;
    QPushButton *StopButton;
    QPushButton *UserSeeButton;
    QPushButton *SaveButton;
    QPushButton *ReadButton;
    QPushButton *SearchButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *IPlabel;
    QLineEdit *IPEdit;
    QLabel *Portlabel;
    QLineEdit *PortEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1135, 870);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 531, 641));
        CarDataEdit = new QTextEdit(groupBox);
        CarDataEdit->setObjectName(QString::fromUtf8("CarDataEdit"));
        CarDataEdit->setGeometry(QRect(20, 30, 491, 591));
        CarDataEdit->setReadOnly(true);
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(570, 20, 541, 331));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(570, 360, 551, 301));
        MsgViewEdit = new QTextEdit(groupBox_3);
        MsgViewEdit->setObjectName(QString::fromUtf8("MsgViewEdit"));
        MsgViewEdit->setGeometry(QRect(10, 20, 531, 271));
        MsgViewEdit->setReadOnly(true);
        MsgSendEdit = new QTextEdit(Widget);
        MsgSendEdit->setObjectName(QString::fromUtf8("MsgSendEdit"));
        MsgSendEdit->setGeometry(QRect(570, 670, 551, 101));
        MsgSendButton = new QPushButton(Widget);
        MsgSendButton->setObjectName(QString::fromUtf8("MsgSendButton"));
        MsgSendButton->setGeometry(QRect(892, 790, 231, 51));
        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 670, 531, 171));
        StartButton = new QPushButton(groupBox_4);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));
        StartButton->setGeometry(QRect(380, 30, 131, 31));
        Linklabel = new QLabel(groupBox_4);
        Linklabel->setObjectName(QString::fromUtf8("Linklabel"));
        Linklabel->setGeometry(QRect(20, 90, 81, 21));
        StateViewlabel = new QLabel(groupBox_4);
        StateViewlabel->setObjectName(QString::fromUtf8("StateViewlabel"));
        StateViewlabel->setGeometry(QRect(110, 80, 31, 31));
        PauseButton = new QPushButton(groupBox_4);
        PauseButton->setObjectName(QString::fromUtf8("PauseButton"));
        PauseButton->setGeometry(QRect(220, 80, 131, 31));
        StopButton = new QPushButton(groupBox_4);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));
        StopButton->setGeometry(QRect(380, 80, 131, 31));
        UserSeeButton = new QPushButton(groupBox_4);
        UserSeeButton->setObjectName(QString::fromUtf8("UserSeeButton"));
        UserSeeButton->setGeometry(QRect(10, 130, 101, 31));
        SaveButton = new QPushButton(groupBox_4);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(130, 130, 101, 31));
        ReadButton = new QPushButton(groupBox_4);
        ReadButton->setObjectName(QString::fromUtf8("ReadButton"));
        ReadButton->setGeometry(QRect(250, 130, 101, 31));
        SearchButton = new QPushButton(groupBox_4);
        SearchButton->setObjectName(QString::fromUtf8("SearchButton"));
        SearchButton->setGeometry(QRect(380, 130, 131, 31));
        layoutWidget = new QWidget(groupBox_4);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 331, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        IPlabel = new QLabel(layoutWidget);
        IPlabel->setObjectName(QString::fromUtf8("IPlabel"));

        horizontalLayout->addWidget(IPlabel);

        IPEdit = new QLineEdit(layoutWidget);
        IPEdit->setObjectName(QString::fromUtf8("IPEdit"));

        horizontalLayout->addWidget(IPEdit);

        Portlabel = new QLabel(layoutWidget);
        Portlabel->setObjectName(QString::fromUtf8("Portlabel"));

        horizontalLayout->addWidget(Portlabel);

        PortEdit = new QLineEdit(layoutWidget);
        PortEdit->setObjectName(QString::fromUtf8("PortEdit"));

        horizontalLayout->addWidget(PortEdit);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\350\275\246\350\276\206\346\225\260\346\215\256", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\347\233\221\350\247\206\344\270\255\345\277\203", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "\346\266\210\346\201\257\345\214\272", nullptr));
        MsgSendButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Widget", "\346\216\247\345\210\266\344\270\255\345\277\203", nullptr));
        StartButton->setText(QCoreApplication::translate("Widget", "\345\220\257\345\212\250\346\234\215\345\212\241", nullptr));
        Linklabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:10pt;\">\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232</span></p></body></html>", nullptr));
        StateViewlabel->setText(QString());
        PauseButton->setText(QCoreApplication::translate("Widget", "\346\232\202\345\201\234\346\234\215\345\212\241", nullptr));
        StopButton->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\346\234\215\345\212\241", nullptr));
        UserSeeButton->setText(QCoreApplication::translate("Widget", "\345\234\250\347\272\277\350\275\246\350\276\206\346\237\245\347\234\213", nullptr));
        SaveButton->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\344\277\235\345\255\230", nullptr));
        ReadButton->setText(QCoreApplication::translate("Widget", "\350\257\273\345\217\226\346\225\260\346\215\256", nullptr));
        SearchButton->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\346\237\245\350\257\242", nullptr));
        IPlabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p>IP</p></body></html>", nullptr));
        Portlabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:10pt;\">\347\253\257\345\217\243</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
