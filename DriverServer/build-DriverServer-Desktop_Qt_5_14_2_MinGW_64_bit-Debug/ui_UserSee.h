/********************************************************************************
** Form generated from reading UI file 'UserSee.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSEE_H
#define UI_USERSEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserSee
{
public:
    QGroupBox *groupBox;
    QTextEdit *UseNameEdit;

    void setupUi(QWidget *UserSee)
    {
        if (UserSee->objectName().isEmpty())
            UserSee->setObjectName(QString::fromUtf8("UserSee"));
        UserSee->resize(409, 632);
        groupBox = new QGroupBox(UserSee);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 391, 611));
        UseNameEdit = new QTextEdit(groupBox);
        UseNameEdit->setObjectName(QString::fromUtf8("UseNameEdit"));
        UseNameEdit->setGeometry(QRect(10, 20, 371, 581));
        UseNameEdit->setReadOnly(true);

        retranslateUi(UserSee);

        QMetaObject::connectSlotsByName(UserSee);
    } // setupUi

    void retranslateUi(QWidget *UserSee)
    {
        UserSee->setWindowTitle(QCoreApplication::translate("UserSee", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("UserSee", "\345\234\250\347\272\277\350\275\246\350\276\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserSee: public Ui_UserSee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSEE_H
