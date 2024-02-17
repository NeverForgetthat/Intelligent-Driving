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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *OpenSerialButton;
    QTextEdit *SendMsgEdit;
    QPushButton *Send2CenterButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *Sensorlabel;
    QComboBox *SensorcomboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Checklabel;
    QComboBox *CheckcomboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Portlabel;
    QComboBox *PortcomboBox;
    QGroupBox *groupBox_2;
    QPushButton *ChangenNameButton;
    QLineEdit *UserNameEdit;
    QGroupBox *groupBox_3;
    QTextEdit *SensorDataEdit;
    QGroupBox *groupBox_4;
    QLabel *CarViewLabel;
    QGroupBox *groupBox_6;
    QLCDNumber *CarCountlcd;
    QGroupBox *groupBox_7;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QLineEdit *Press1Edit;
    QLineEdit *Press2Edit;
    QLineEdit *Press3Edit;
    QLineEdit *Press4Edit;
    QGroupBox *groupBox_10;
    QProgressBar *OilBar;
    QGroupBox *groupBox_5;
    QLabel *NetConditionlabel;
    QPushButton *ClearNetButton;
    QLabel *IPlabel;
    QLineEdit *IPEdit;
    QLabel *NetPortlabel;
    QLineEdit *NetPortEdit;
    QPushButton *NetStartButton;
    QLabel *NetStatelabel;
    QPushButton *NetStopButton;
    QTextEdit *NetMsgEdit;
    QPushButton *OpenFileButton;
    QPushButton *SaveFileButton;
    QPushButton *ReadFileButton;
    QPushButton *SearchButton;
    QGroupBox *groupBox_8;
    QPushButton *StartButton;
    QPushButton *StopButton;
    QPushButton *ContinueButton;
    QPushButton *PauseButton;
    QGroupBox *groupBox_9;
    QDial *Beauty1;
    QDial *Beauty2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1082, 981);
        OpenSerialButton = new QPushButton(Widget);
        OpenSerialButton->setObjectName(QString::fromUtf8("OpenSerialButton"));
        OpenSerialButton->setGeometry(QRect(70, 920, 181, 41));
        SendMsgEdit = new QTextEdit(Widget);
        SendMsgEdit->setObjectName(QString::fromUtf8("SendMsgEdit"));
        SendMsgEdit->setGeometry(QRect(310, 750, 761, 161));
        Send2CenterButton = new QPushButton(Widget);
        Send2CenterButton->setObjectName(QString::fromUtf8("Send2CenterButton"));
        Send2CenterButton->setGeometry(QRect(840, 920, 231, 41));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(60, 750, 201, 161));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Sensorlabel = new QLabel(groupBox);
        Sensorlabel->setObjectName(QString::fromUtf8("Sensorlabel"));

        horizontalLayout->addWidget(Sensorlabel);

        SensorcomboBox = new QComboBox(groupBox);
        SensorcomboBox->setObjectName(QString::fromUtf8("SensorcomboBox"));

        horizontalLayout->addWidget(SensorcomboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Checklabel = new QLabel(groupBox);
        Checklabel->setObjectName(QString::fromUtf8("Checklabel"));

        horizontalLayout_2->addWidget(Checklabel);

        CheckcomboBox = new QComboBox(groupBox);
        CheckcomboBox->setObjectName(QString::fromUtf8("CheckcomboBox"));

        horizontalLayout_2->addWidget(CheckcomboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Portlabel = new QLabel(groupBox);
        Portlabel->setObjectName(QString::fromUtf8("Portlabel"));

        horizontalLayout_3->addWidget(Portlabel);

        PortcomboBox = new QComboBox(groupBox);
        PortcomboBox->setObjectName(QString::fromUtf8("PortcomboBox"));

        horizontalLayout_3->addWidget(PortcomboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 10, 221, 61));
        ChangenNameButton = new QPushButton(groupBox_2);
        ChangenNameButton->setObjectName(QString::fromUtf8("ChangenNameButton"));
        ChangenNameButton->setGeometry(QRect(140, 20, 71, 28));
        UserNameEdit = new QLineEdit(groupBox_2);
        UserNameEdit->setObjectName(QString::fromUtf8("UserNameEdit"));
        UserNameEdit->setGeometry(QRect(10, 20, 113, 31));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 80, 381, 571));
        SensorDataEdit = new QTextEdit(groupBox_3);
        SensorDataEdit->setObjectName(QString::fromUtf8("SensorDataEdit"));
        SensorDataEdit->setGeometry(QRect(20, 20, 351, 541));
        SensorDataEdit->setReadOnly(true);
        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(420, 10, 651, 351));
        CarViewLabel = new QLabel(groupBox_4);
        CarViewLabel->setObjectName(QString::fromUtf8("CarViewLabel"));
        CarViewLabel->setGeometry(QRect(90, 90, 171, 241));
        groupBox_6 = new QGroupBox(groupBox_4);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(370, 20, 241, 81));
        CarCountlcd = new QLCDNumber(groupBox_6);
        CarCountlcd->setObjectName(QString::fromUtf8("CarCountlcd"));
        CarCountlcd->setGeometry(QRect(50, 20, 171, 51));
        groupBox_7 = new QGroupBox(groupBox_4);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(370, 120, 241, 201));
        line = new QFrame(groupBox_4);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(210, 260, 31, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(groupBox_4);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(110, 260, 31, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(groupBox_4);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(210, 180, 31, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(groupBox_4);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(110, 180, 31, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        Press1Edit = new QLineEdit(groupBox_4);
        Press1Edit->setObjectName(QString::fromUtf8("Press1Edit"));
        Press1Edit->setGeometry(QRect(250, 180, 81, 21));
        Press1Edit->setFrame(false);
        Press1Edit->setDragEnabled(false);
        Press1Edit->setReadOnly(true);
        Press2Edit = new QLineEdit(groupBox_4);
        Press2Edit->setObjectName(QString::fromUtf8("Press2Edit"));
        Press2Edit->setGeometry(QRect(250, 260, 81, 21));
        Press2Edit->setFrame(false);
        Press2Edit->setReadOnly(true);
        Press3Edit = new QLineEdit(groupBox_4);
        Press3Edit->setObjectName(QString::fromUtf8("Press3Edit"));
        Press3Edit->setGeometry(QRect(30, 260, 71, 21));
        Press3Edit->setFrame(false);
        Press3Edit->setDragEnabled(false);
        Press3Edit->setReadOnly(true);
        Press4Edit = new QLineEdit(groupBox_4);
        Press4Edit->setObjectName(QString::fromUtf8("Press4Edit"));
        Press4Edit->setGeometry(QRect(30, 180, 71, 21));
        Press4Edit->setFrame(false);
        Press4Edit->setDragEnabled(false);
        Press4Edit->setReadOnly(true);
        groupBox_10 = new QGroupBox(groupBox_4);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(140, 20, 211, 51));
        OilBar = new QProgressBar(groupBox_10);
        OilBar->setObjectName(QString::fromUtf8("OilBar"));
        OilBar->setGeometry(QRect(10, 20, 191, 23));
        OilBar->setValue(24);
        groupBox_5 = new QGroupBox(Widget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(420, 370, 431, 101));
        NetConditionlabel = new QLabel(groupBox_5);
        NetConditionlabel->setObjectName(QString::fromUtf8("NetConditionlabel"));
        NetConditionlabel->setGeometry(QRect(10, 30, 81, 16));
        ClearNetButton = new QPushButton(groupBox_5);
        ClearNetButton->setObjectName(QString::fromUtf8("ClearNetButton"));
        ClearNetButton->setGeometry(QRect(190, 20, 131, 31));
        IPlabel = new QLabel(groupBox_5);
        IPlabel->setObjectName(QString::fromUtf8("IPlabel"));
        IPlabel->setGeometry(QRect(10, 70, 72, 15));
        IPEdit = new QLineEdit(groupBox_5);
        IPEdit->setObjectName(QString::fromUtf8("IPEdit"));
        IPEdit->setGeometry(QRect(40, 60, 151, 31));
        NetPortlabel = new QLabel(groupBox_5);
        NetPortlabel->setObjectName(QString::fromUtf8("NetPortlabel"));
        NetPortlabel->setGeometry(QRect(210, 70, 41, 16));
        NetPortEdit = new QLineEdit(groupBox_5);
        NetPortEdit->setObjectName(QString::fromUtf8("NetPortEdit"));
        NetPortEdit->setGeometry(QRect(250, 60, 71, 31));
        NetStartButton = new QPushButton(groupBox_5);
        NetStartButton->setObjectName(QString::fromUtf8("NetStartButton"));
        NetStartButton->setGeometry(QRect(340, 20, 71, 31));
        NetStatelabel = new QLabel(groupBox_5);
        NetStatelabel->setObjectName(QString::fromUtf8("NetStatelabel"));
        NetStatelabel->setGeometry(QRect(100, 20, 31, 31));
        NetStopButton = new QPushButton(groupBox_5);
        NetStopButton->setObjectName(QString::fromUtf8("NetStopButton"));
        NetStopButton->setGeometry(QRect(340, 60, 71, 31));
        NetMsgEdit = new QTextEdit(Widget);
        NetMsgEdit->setObjectName(QString::fromUtf8("NetMsgEdit"));
        NetMsgEdit->setGeometry(QRect(420, 480, 651, 171));
        NetMsgEdit->setReadOnly(true);
        OpenFileButton = new QPushButton(Widget);
        OpenFileButton->setObjectName(QString::fromUtf8("OpenFileButton"));
        OpenFileButton->setGeometry(QRect(440, 670, 121, 51));
        SaveFileButton = new QPushButton(Widget);
        SaveFileButton->setObjectName(QString::fromUtf8("SaveFileButton"));
        SaveFileButton->setGeometry(QRect(600, 670, 121, 51));
        ReadFileButton = new QPushButton(Widget);
        ReadFileButton->setObjectName(QString::fromUtf8("ReadFileButton"));
        ReadFileButton->setGeometry(QRect(770, 670, 121, 51));
        SearchButton = new QPushButton(Widget);
        SearchButton->setObjectName(QString::fromUtf8("SearchButton"));
        SearchButton->setGeometry(QRect(930, 670, 121, 51));
        groupBox_8 = new QGroupBox(Widget);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(20, 670, 381, 61));
        StartButton = new QPushButton(groupBox_8);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));
        StartButton->setGeometry(QRect(20, 10, 71, 41));
        StopButton = new QPushButton(groupBox_8);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));
        StopButton->setGeometry(QRect(290, 10, 71, 41));
        ContinueButton = new QPushButton(groupBox_8);
        ContinueButton->setObjectName(QString::fromUtf8("ContinueButton"));
        ContinueButton->setGeometry(QRect(200, 10, 71, 41));
        PauseButton = new QPushButton(groupBox_8);
        PauseButton->setObjectName(QString::fromUtf8("PauseButton"));
        PauseButton->setGeometry(QRect(110, 10, 71, 41));
        groupBox_9 = new QGroupBox(Widget);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(420, 660, 651, 71));
        Beauty1 = new QDial(Widget);
        Beauty1->setObjectName(QString::fromUtf8("Beauty1"));
        Beauty1->setGeometry(QRect(880, 390, 71, 71));
        Beauty2 = new QDial(Widget);
        Beauty2->setObjectName(QString::fromUtf8("Beauty2"));
        Beauty2->setGeometry(QRect(980, 390, 71, 71));
        groupBox_9->raise();
        groupBox_8->raise();
        OpenSerialButton->raise();
        SendMsgEdit->raise();
        Send2CenterButton->raise();
        groupBox->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        groupBox_4->raise();
        groupBox_5->raise();
        NetMsgEdit->raise();
        OpenFileButton->raise();
        SaveFileButton->raise();
        ReadFileButton->raise();
        SearchButton->raise();
        Beauty1->raise();
        Beauty2->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        OpenSerialButton->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        Send2CenterButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\345\210\260\344\270\255\345\277\203", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        Sensorlabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:12pt;\">\344\274\240\346\204\237\345\231\250</span></p></body></html>", nullptr));
        Checklabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\240\241\346\243\200\344\275\215</span></p></body></html>", nullptr));
        Portlabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\263\242\347\211\271\347\216\207</span></p></body></html>", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", nullptr));
        ChangenNameButton->setText(QCoreApplication::translate("Widget", "\344\277\256\346\224\271", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "\344\274\240\346\204\237\345\231\250\346\225\260\346\215\256", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Widget", "\346\231\272\350\203\275\351\251\276\351\251\266\350\210\261", nullptr));
#if QT_CONFIG(tooltip)
        CarViewLabel->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p>\350\277\231\351\207\214\346\234\211\344\270\252\346\261\275\350\275\246</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        CarViewLabel->setWhatsThis(QCoreApplication::translate("Widget", "<html><head/><body><p>\350\277\231\351\207\214\346\234\211\344\270\200\350\276\206\350\275\246</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        CarViewLabel->setText(QCoreApplication::translate("Widget", "  \350\277\231\351\207\214\345\201\234\346\224\276\344\272\206\344\270\200\350\276\206\346\261\275\350\275\246", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("Widget", "\344\270\244\345\205\254\351\207\214\345\206\205\350\275\246\350\276\206\346\225\260", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("Widget", "\351\200\237\345\272\246\347\233\230", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("Widget", "\346\262\271\351\207\217", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Widget", "\344\270\255\345\277\203\346\234\215\345\212\241\345\231\250", nullptr));
        NetConditionlabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:10pt;\">\347\275\221\347\273\234\347\212\266\346\200\201\357\274\232</span></p></body></html>", nullptr));
        ClearNetButton->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\347\275\221\347\273\234\346\266\210\346\201\257", nullptr));
        IPlabel->setText(QCoreApplication::translate("Widget", "IP:", nullptr));
        NetPortlabel->setText(QCoreApplication::translate("Widget", "\347\253\257\345\217\243\357\274\232", nullptr));
        NetStartButton->setText(QCoreApplication::translate("Widget", "\345\220\257\345\212\250\346\234\215\345\212\241", nullptr));
        NetStatelabel->setText(QString());
        NetStopButton->setText(QCoreApplication::translate("Widget", "\346\226\255\345\274\200\346\234\215\345\212\241", nullptr));
        OpenFileButton->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        SaveFileButton->setText(QCoreApplication::translate("Widget", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        ReadFileButton->setText(QCoreApplication::translate("Widget", "\350\257\273\345\217\226\346\225\260\346\215\256", nullptr));
        SearchButton->setText(QCoreApplication::translate("Widget", "\346\237\245\350\257\242\346\225\260\346\215\256", nullptr));
        groupBox_8->setTitle(QString());
        StartButton->setText(QCoreApplication::translate("Widget", "\345\220\257\345\212\250", nullptr));
        StopButton->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242", nullptr));
        ContinueButton->setText(QCoreApplication::translate("Widget", "\347\273\247\347\273\255", nullptr));
        PauseButton->setText(QCoreApplication::translate("Widget", "\346\232\202\345\201\234", nullptr));
        groupBox_9->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
