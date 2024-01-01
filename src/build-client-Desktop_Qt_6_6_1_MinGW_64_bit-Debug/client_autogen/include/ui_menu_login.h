/********************************************************************************
** Form generated from reading UI file 'menu_login.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_LOGIN_H
#define UI_MENU_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainmenulogin
{
public:
    QFrame *background;
    QPushButton *logout;
    QPushButton *CreateRoom;
    QPushButton *JoinRoom;
    QPushButton *LeaderBoard;
    QPushButton *EditProfile;
    QFrame *createRoom;
    QLabel *label;
    QLineEdit *roomNameInput;
    QPushButton *cancel;
    QPushButton *create;
    QLabel *warning_create;
    QFrame *joinRoom;
    QLabel *label_3;
    QLineEdit *joinInput;
    QPushButton *cancel_3;
    QPushButton *join;

    void setupUi(QWidget *mainmenulogin)
    {
        if (mainmenulogin->objectName().isEmpty())
            mainmenulogin->setObjectName("mainmenulogin");
        mainmenulogin->resize(730, 510);
        mainmenulogin->setStyleSheet(QString::fromUtf8("#createRoom{\n"
"	background: #494F55;\n"
"}\n"
"\n"
"#joinRoom{\n"
"	background: #494F55;\n"
"}\n"
"\n"
"\n"
"#label{\n"
"	color: white;\n"
"}\n"
"\n"
"#label_3{\n"
"	color: white;\n"
"}\n"
"\n"
"#create{\n"
"	\n"
"}\n"
"\n"
"#roomNameInput{\n"
"	background: none;\n"
"	border: none;\n"
"}"));
        background = new QFrame(mainmenulogin);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 730, 510));
        QFont font;
        font.setFamilies({QString::fromUtf8("century")});
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        background->setFont(font);
        background->setStyleSheet(QString::fromUtf8("*{\n"
"	font-size: 12px;\n"
"	font-family: century;\n"
"}\n"
"\n"
"#background{\n"
"	background-image: url(:/background.jpg);\n"
"}\n"
"\n"
"#header{\n"
"	font-size: 40px;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background: transparent;\n"
"	border:none;\n"
"	color: white;\n"
"	font-size: 20px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"#OnlineList{\n"
"	\n"
"}\n"
"\n"
"#logout{\n"
"	text-align: right;\n"
"}\n"
"\n"
"#OnlineList{\n"
"	background: white;\n"
"}"));
        background->setFrameShape(QFrame::StyledPanel);
        background->setFrameShadow(QFrame::Raised);
        logout = new QPushButton(background);
        logout->setObjectName("logout");
        logout->setGeometry(QRect(670, 10, 50, 30));
        logout->setFont(font);
        logout->setStyleSheet(QString::fromUtf8("transform: rotate(90);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/right-from-bracket-solid.svg"), QSize(), QIcon::Normal, QIcon::Off);
        logout->setIcon(icon);
        logout->setIconSize(QSize(50, 50));
        CreateRoom = new QPushButton(background);
        CreateRoom->setObjectName("CreateRoom");
        CreateRoom->setGeometry(QRect(10, 470, 140, 30));
        CreateRoom->setFont(font);
        JoinRoom = new QPushButton(background);
        JoinRoom->setObjectName("JoinRoom");
        JoinRoom->setGeometry(QRect(220, 470, 140, 30));
        JoinRoom->setFont(font);
        JoinRoom->setStyleSheet(QString::fromUtf8(""));
        LeaderBoard = new QPushButton(background);
        LeaderBoard->setObjectName("LeaderBoard");
        LeaderBoard->setGeometry(QRect(410, 470, 140, 30));
        LeaderBoard->setFont(font);
        EditProfile = new QPushButton(background);
        EditProfile->setObjectName("EditProfile");
        EditProfile->setGeometry(QRect(10, 10, 140, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("century")});
        font1.setBold(true);
        EditProfile->setFont(font1);
        createRoom = new QFrame(mainmenulogin);
        createRoom->setObjectName("createRoom");
        createRoom->setGeometry(QRect(170, 180, 400, 150));
        createRoom->setFrameShape(QFrame::StyledPanel);
        createRoom->setFrameShadow(QFrame::Raised);
        label = new QLabel(createRoom);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 301, 21));
        roomNameInput = new QLineEdit(createRoom);
        roomNameInput->setObjectName("roomNameInput");
        roomNameInput->setGeometry(QRect(30, 50, 350, 30));
        cancel = new QPushButton(createRoom);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(30, 110, 150, 30));
        create = new QPushButton(createRoom);
        create->setObjectName("create");
        create->setGeometry(QRect(230, 110, 150, 30));
        warning_create = new QLabel(createRoom);
        warning_create->setObjectName("warning_create");
        warning_create->setGeometry(QRect(30, 80, 351, 21));
        QFont font2;
        font2.setBold(true);
        warning_create->setFont(font2);
        warning_create->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-size: 15px;"));
        joinRoom = new QFrame(mainmenulogin);
        joinRoom->setObjectName("joinRoom");
        joinRoom->setGeometry(QRect(170, 20, 400, 150));
        joinRoom->setFrameShape(QFrame::StyledPanel);
        joinRoom->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(joinRoom);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 20, 181, 21));
        joinInput = new QLineEdit(joinRoom);
        joinInput->setObjectName("joinInput");
        joinInput->setGeometry(QRect(30, 50, 350, 30));
        cancel_3 = new QPushButton(joinRoom);
        cancel_3->setObjectName("cancel_3");
        cancel_3->setGeometry(QRect(30, 90, 150, 30));
        join = new QPushButton(joinRoom);
        join->setObjectName("join");
        join->setGeometry(QRect(230, 90, 150, 30));

        retranslateUi(mainmenulogin);

        QMetaObject::connectSlotsByName(mainmenulogin);
    } // setupUi

    void retranslateUi(QWidget *mainmenulogin)
    {
        mainmenulogin->setWindowTitle(QCoreApplication::translate("mainmenulogin", "Form", nullptr));
        logout->setText(QString());
        CreateRoom->setText(QCoreApplication::translate("mainmenulogin", "Create Room", nullptr));
        JoinRoom->setText(QCoreApplication::translate("mainmenulogin", "Join Room", nullptr));
        LeaderBoard->setText(QCoreApplication::translate("mainmenulogin", "Leader Board", nullptr));
        EditProfile->setText(QCoreApplication::translate("mainmenulogin", "Edit Profile", nullptr));
        label->setText(QCoreApplication::translate("mainmenulogin", "Insert room name to create", nullptr));
        cancel->setText(QCoreApplication::translate("mainmenulogin", "Cancel", nullptr));
        create->setText(QCoreApplication::translate("mainmenulogin", "Create", nullptr));
        warning_create->setText(QString());
        label_3->setText(QCoreApplication::translate("mainmenulogin", "Insert room name to join", nullptr));
        cancel_3->setText(QCoreApplication::translate("mainmenulogin", "Cancel", nullptr));
        join->setText(QCoreApplication::translate("mainmenulogin", "Join", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainmenulogin: public Ui_mainmenulogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_LOGIN_H
