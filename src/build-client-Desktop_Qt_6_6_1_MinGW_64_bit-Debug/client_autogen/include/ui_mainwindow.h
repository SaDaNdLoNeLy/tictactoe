/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *playoffline;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(674, 505);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	text-align:left;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-30, 0, 731, 511));
        label->setStyleSheet(QString::fromUtf8("image: url(:/background.jpg);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 20, 421, 121));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(40);
        font.setBold(false);
        font.setItalic(false);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"font: 400 \"Pacifico\";\n"
""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(520, 430, 140, 31));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("inter")});
        font1.setPointSize(18);
        pushButton->setFont(font1);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"background: none;\n"
"border: 1px red;\n"
"color: white;\n"
"font-family: inter;"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(30, 430, 140, 31));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setFont(font1);
        pushButton_2->setAutoFillBackground(false);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"background: none;\n"
"border: 1px red;\n"
"color: white;\n"
"font-family: inter;"));
        playoffline = new QPushButton(centralwidget);
        playoffline->setObjectName("playoffline");
        playoffline->setGeometry(QRect(270, 430, 140, 31));
        sizePolicy.setHeightForWidth(playoffline->sizePolicy().hasHeightForWidth());
        playoffline->setSizePolicy(sizePolicy);
        playoffline->setFont(font1);
        playoffline->setAutoFillBackground(false);
        playoffline->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"background: none;\n"
"border: 1px red;\n"
"color: white;\n"
"font-family: inter;"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Tic-Tac-Toe Online", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Tic-tac-toe Online", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Play Online", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        playoffline->setText(QCoreApplication::translate("MainWindow", "Play Offline", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
