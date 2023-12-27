/********************************************************************************
** Form generated from reading UI file 'online_list.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINE_LIST_H
#define UI_ONLINE_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OnlinePlayer
{
public:
    QListWidget *listWidget;

    void setupUi(QWidget *OnlinePlayer)
    {
        if (OnlinePlayer->objectName().isEmpty())
            OnlinePlayer->setObjectName("OnlinePlayer");
        OnlinePlayer->resize(220, 511);
        OnlinePlayer->setStyleSheet(QString::fromUtf8("background-image: url(:/background.jpg);"));
        listWidget = new QListWidget(OnlinePlayer);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(0, 0, 221, 511));

        retranslateUi(OnlinePlayer);

        QMetaObject::connectSlotsByName(OnlinePlayer);
    } // setupUi

    void retranslateUi(QWidget *OnlinePlayer)
    {
        OnlinePlayer->setWindowTitle(QCoreApplication::translate("OnlinePlayer", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OnlinePlayer: public Ui_OnlinePlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINE_LIST_H
