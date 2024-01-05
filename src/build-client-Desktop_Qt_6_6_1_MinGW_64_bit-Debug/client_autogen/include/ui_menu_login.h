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
    QLabel *warning_join;
    QFrame *frame;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *username;
    QLabel *ingame;
    QLabel *wins;
    QLabel *loses;
    QLabel *status;
    QLabel *winrate;
    QPushButton *pushButton;

    void setupUi(QWidget *mainmenulogin)
    {
        if (mainmenulogin->objectName().isEmpty())
            mainmenulogin->setObjectName("mainmenulogin");
        mainmenulogin->resize(726, 503);
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
        JoinRoom->setGeometry(QRect(590, 470, 140, 30));
        JoinRoom->setFont(font);
        JoinRoom->setStyleSheet(QString::fromUtf8(""));
        LeaderBoard = new QPushButton(background);
        LeaderBoard->setObjectName("LeaderBoard");
        LeaderBoard->setGeometry(QRect(730, 470, 140, 30));
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
"font-size: 12px;"));
        joinRoom = new QFrame(mainmenulogin);
        joinRoom->setObjectName("joinRoom");
        joinRoom->setGeometry(QRect(170, 180, 400, 150));
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
        cancel_3->setGeometry(QRect(30, 110, 150, 30));
        join = new QPushButton(joinRoom);
        join->setObjectName("join");
        join->setGeometry(QRect(230, 110, 150, 30));
        warning_join = new QLabel(joinRoom);
        warning_join->setObjectName("warning_join");
        warning_join->setGeometry(QRect(30, 80, 351, 21));
        warning_join->setFont(font2);
        warning_join->setStyleSheet(QString::fromUtf8("font-size: 12px;\n"
"color: red;"));
        frame = new QFrame(mainmenulogin);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(170, 180, 400, 150));
        frame->setStyleSheet(QString::fromUtf8("background: #494F55;\n"
"color: white;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 10, 91, 21));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 30, 91, 21));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 50, 63, 20));
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 70, 63, 20));
        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 90, 63, 20));
        label_8 = new QLabel(frame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 110, 71, 21));
        username = new QLabel(frame);
        username->setObjectName("username");
        username->setGeometry(QRect(120, 10, 200, 20));
        QFont font3;
        font3.setPointSize(12);
        username->setFont(font3);
        ingame = new QLabel(frame);
        ingame->setObjectName("ingame");
        ingame->setGeometry(QRect(120, 30, 200, 20));
        ingame->setFont(font3);
        wins = new QLabel(frame);
        wins->setObjectName("wins");
        wins->setGeometry(QRect(120, 50, 200, 20));
        wins->setFont(font3);
        loses = new QLabel(frame);
        loses->setObjectName("loses");
        loses->setGeometry(QRect(120, 70, 200, 20));
        loses->setFont(font3);
        status = new QLabel(frame);
        status->setObjectName("status");
        status->setGeometry(QRect(120, 90, 200, 20));
        status->setFont(font3);
        winrate = new QLabel(frame);
        winrate->setObjectName("winrate");
        winrate->setGeometry(QRect(120, 110, 200, 20));
        winrate->setFont(font3);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 0, 50, 50));
        QFont font4;
        font4.setPointSize(30);
        font4.setBold(true);
        pushButton->setFont(font4);
        pushButton->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;"));

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
        warning_join->setText(QString());
        label_2->setText(QCoreApplication::translate("mainmenulogin", "USERNAME: ", nullptr));
        label_4->setText(QCoreApplication::translate("mainmenulogin", "INGAME: ", nullptr));
        label_5->setText(QCoreApplication::translate("mainmenulogin", "WINS: ", nullptr));
        label_6->setText(QCoreApplication::translate("mainmenulogin", "LOSES: ", nullptr));
        label_7->setText(QCoreApplication::translate("mainmenulogin", "ELO:", nullptr));
        label_8->setText(QCoreApplication::translate("mainmenulogin", "WINRATE: ", nullptr));
        username->setText(QCoreApplication::translate("mainmenulogin", "TextLabel", nullptr));
        ingame->setText(QCoreApplication::translate("mainmenulogin", "TextLabel", nullptr));
        wins->setText(QCoreApplication::translate("mainmenulogin", "TextLabel", nullptr));
        loses->setText(QCoreApplication::translate("mainmenulogin", "TextLabel", nullptr));
        status->setText(QCoreApplication::translate("mainmenulogin", "TextLabel", nullptr));
        winrate->setText(QCoreApplication::translate("mainmenulogin", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("mainmenulogin", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainmenulogin: public Ui_mainmenulogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_LOGIN_H
