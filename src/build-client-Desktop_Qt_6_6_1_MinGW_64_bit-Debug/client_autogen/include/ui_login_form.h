/********************************************************************************
** Form generated from reading UI file 'login_form.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_FORM_H
#define UI_LOGIN_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginform
{
public:
    QFrame *frame;
    QLabel *label;
    QPushButton *login_btn;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *forgot;
    QLabel *label_2;
    QPushButton *Register;
    QPushButton *show_password;
    QLabel *warning_username;
    QLabel *warning_password;
    QPushButton *pushButton;
    QPushButton *Back_btn;
    QFrame *frame_2;

    void setupUi(QWidget *loginform)
    {
        if (loginform->objectName().isEmpty())
            loginform->setObjectName("loginform");
        loginform->resize(360, 480);
        QFont font;
        font.setFamilies({QString::fromUtf8("century gothic")});
        font.setBold(true);
        loginform->setFont(font);
        loginform->setAutoFillBackground(false);
        loginform->setStyleSheet(QString::fromUtf8("*{\n"
"	font-family: century gothic;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"#loginform{\n"
"	background-image: url(:/bg-01.jpg);\n"
" 	border: none;\n"
"}\n"
"\n"
"QFrame{\n"
"	background: #333;\n"
" 	border-radius: 10px;\n"
"}\n"
"\n"
"#login_btn{\n"
"	background: red;\n"
"	color: white;\n"
"}\n"
"\n"
"#login_btn:hover{\n"
"	background-color: #00FFFF;\n"
"	color: red;\n"
"	border: none;\n"
"}\n"
"\n"
"QLineEdit{\n"
"	background: transparent;\n"
"	border: none;\n"
"	color: #717072;\n"
"	border-bottom: 1px solid #707172;\n"
"	border-radius: 0px;\n"
"}\n"
"\n"
"#Back_btn{\n"
"	border: none;\n"
"	background: transparent;\n"
"	color: white;\n"
"}\n"
"\n"
"#label_2{\n"
"	color: #808080;\n"
"	font-size:12px;\n"
"}\n"
"\n"
"#Register{\n"
"	color: white;\n"
"	font-size: 14px;\n"
"	background: #333;\n"
"	border: none;\n"
"}\n"
"\n"
"#forgot{\n"
"	font-size: 12px;\n"
"	color: white;\n"
"	background: transparent;\n"
"	border: none;\n"
"}\n"
"\n"
"#img{\n"
"	background: transparent;\n"
"}\n"
"\n"
"#show_password{\n"
"	backg"
                        "round: transparent;\n"
"	border: none;\n"
"}\n"
"\n"
"#warning_username, #warning_password{\n"
"	font-size: 9px;\n"
"	padding-left: 5px;\n"
"	color: red;\n"
"	font-weight: bold;\n"
"	text-align: left;\n"
"}\n"
""));
        frame = new QFrame(loginform);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(30, 40, 300, 400));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 50, 121, 41));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: white;\n"
"text-align: center;\n"
"background: transparent;"));
        login_btn = new QPushButton(frame);
        login_btn->setObjectName("login_btn");
        login_btn->setGeometry(QRect(30, 270, 240, 40));
        login_btn->setFont(font);
        login_btn->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-radius: 10px;"));
        username = new QLineEdit(frame);
        username->setObjectName("username");
        username->setGeometry(QRect(30, 110, 240, 30));
        username->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));
        username->setCursorPosition(0);
        username->setPlaceholderText(QString::fromUtf8("Username"));
        username->setClearButtonEnabled(true);
        password = new QLineEdit(frame);
        password->setObjectName("password");
        password->setGeometry(QRect(30, 170, 240, 30));
        password->setFocusPolicy(Qt::StrongFocus);
        password->setContextMenuPolicy(Qt::DefaultContextMenu);
        password->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));
        password->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        password->setFrame(false);
        password->setEchoMode(QLineEdit::Password);
        password->setClearButtonEnabled(true);
        forgot = new QPushButton(frame);
        forgot->setObjectName("forgot");
        forgot->setGeometry(QRect(160, 240, 111, 21));
        forgot->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 340, 141, 16));
        Register = new QPushButton(frame);
        Register->setObjectName("Register");
        Register->setGeometry(QRect(120, 360, 75, 24));
        Register->setFont(font);
        show_password = new QPushButton(frame);
        show_password->setObjectName("show_password");
        show_password->setGeometry(QRect(270, 170, 30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/hide-password.svg"), QSize(), QIcon::Normal, QIcon::Off);
        show_password->setIcon(icon);
        warning_username = new QLabel(frame);
        warning_username->setObjectName("warning_username");
        warning_username->setGeometry(QRect(30, 140, 240, 16));
        warning_password = new QLabel(frame);
        warning_password->setObjectName("warning_password");
        warning_password->setGeometry(QRect(30, 200, 240, 16));
        pushButton = new QPushButton(loginform);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 10, 60, 60));
        pushButton->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border-radius: 30px;\n"
"background: red;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/user-regular.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(30, 30));
        Back_btn = new QPushButton(loginform);
        Back_btn->setObjectName("Back_btn");
        Back_btn->setGeometry(QRect(0, 10, 51, 16));
        Back_btn->setFont(font);
        Back_btn->setStyleSheet(QString::fromUtf8("color: black;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/arrow-left-solid.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Back_btn->setIcon(icon2);
        Back_btn->setIconSize(QSize(50, 30));
        frame_2 = new QFrame(loginform);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 0, 360, 480));
        frame_2->setStyleSheet(QString::fromUtf8("border-radius: 0px;\n"
"background-image: url(:/bg-01.jpg);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->raise();
        frame->raise();
        pushButton->raise();
        Back_btn->raise();

        retranslateUi(loginform);

        QMetaObject::connectSlotsByName(loginform);
    } // setupUi

    void retranslateUi(QWidget *loginform)
    {
        loginform->setWindowTitle(QCoreApplication::translate("loginform", "Login", nullptr));
        label->setText(QCoreApplication::translate("loginform", "LOGIN HERE", nullptr));
        login_btn->setText(QCoreApplication::translate("loginform", "Login", nullptr));
        username->setInputMask(QString());
        username->setText(QString());
        password->setText(QString());
        password->setPlaceholderText(QCoreApplication::translate("loginform", "Password", nullptr));
        forgot->setText(QCoreApplication::translate("loginform", "Forgot password?", nullptr));
        label_2->setText(QCoreApplication::translate("loginform", "Have not account yet?", nullptr));
        Register->setText(QCoreApplication::translate("loginform", "SIGN UP", nullptr));
        show_password->setText(QString());
        warning_username->setText(QString());
        warning_password->setText(QString());
        pushButton->setText(QString());
        Back_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class loginform: public Ui_loginform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_FORM_H
