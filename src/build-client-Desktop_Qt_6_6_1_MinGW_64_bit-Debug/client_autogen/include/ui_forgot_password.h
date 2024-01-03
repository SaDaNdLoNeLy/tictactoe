/********************************************************************************
** Form generated from reading UI file 'forgot_password.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGOT_PASSWORD_H
#define UI_FORGOT_PASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_forgot_password
{
public:

    void setupUi(QWidget *forgot_password)
    {
        if (forgot_password->objectName().isEmpty())
            forgot_password->setObjectName("forgot_password");
        forgot_password->resize(400, 300);

        retranslateUi(forgot_password);

        QMetaObject::connectSlotsByName(forgot_password);
    } // setupUi

    void retranslateUi(QWidget *forgot_password)
    {
        forgot_password->setWindowTitle(QCoreApplication::translate("forgot_password", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class forgot_password: public Ui_forgot_password {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGOT_PASSWORD_H
