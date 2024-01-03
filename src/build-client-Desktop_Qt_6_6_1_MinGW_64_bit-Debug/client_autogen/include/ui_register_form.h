/********************************************************************************
** Form generated from reading UI file 'register_form.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_FORM_H
#define UI_REGISTER_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registerform
{
public:
    QFrame *frame;
    QLabel *label;
    QPushButton *register_btn;
    QLineEdit *username;
    QLineEdit *password;
    QLabel *label_2;
    QPushButton *Login;
    QPushButton *show_password;
    QLineEdit *confirm_password;
    QPushButton *show_confirm_password;
    QLabel *warning_username;
    QLabel *warning_password;
    QLabel *warning_confirm_password;
    QLineEdit *ingame;
    QPushButton *pushButton;
    QFrame *frame_2;
    QPushButton *Back_btn;

    void setupUi(QWidget *registerform)
    {
        if (registerform->objectName().isEmpty())
            registerform->setObjectName("registerform");
        registerform->resize(360, 480);
        registerform->setStyleSheet(QString::fromUtf8("*{\n"
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
"#register_btn{\n"
"	background: red;\n"
"	color: white;\n"
"}\n"
"\n"
"#register_btn:hover{\n"
"	background-color: #00FFFF;\n"
"	color: red;\n"
"	border: none;\n"
"	cursor: arrow- cursor;\n"
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
"#Login{\n"
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
""
                        "\n"
"#show_password{\n"
"	background: transparent;\n"
"	border: none;\n"
"}\n"
"\n"
"#show_confirm_password{\n"
"	background: transparent;\n"
"	border: none;\n"
"}\n"
"\n"
"#warning_username, #warning_password, #warning_confirm_password{\n"
"	font-size: 9px;\n"
"	padding-left: 5px;\n"
"	color: red;\n"
"	font-weight: bold;\n"
"	text-align: left;\n"
"}\n"
"\n"
""));
        frame = new QFrame(registerform);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(30, 40, 300, 400));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 30, 141, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("century gothic")});
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: white;\n"
"text-align: center;\n"
"background: transparent;"));
        register_btn = new QPushButton(frame);
        register_btn->setObjectName("register_btn");
        register_btn->setGeometry(QRect(30, 300, 240, 40));
        register_btn->setFont(font);
        register_btn->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-radius: 10px;"));
        username = new QLineEdit(frame);
        username->setObjectName("username");
        username->setGeometry(QRect(30, 80, 240, 30));
        username->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));
        username->setCursorPosition(0);
        username->setPlaceholderText(QString::fromUtf8("Username"));
        username->setClearButtonEnabled(true);
        password = new QLineEdit(frame);
        password->setObjectName("password");
        password->setGeometry(QRect(30, 140, 240, 30));
        password->setFocusPolicy(Qt::StrongFocus);
        password->setContextMenuPolicy(Qt::DefaultContextMenu);
        password->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));
        password->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        password->setFrame(false);
        password->setEchoMode(QLineEdit::Password);
        password->setClearButtonEnabled(true);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 350, 161, 16));
        Login = new QPushButton(frame);
        Login->setObjectName("Login");
        Login->setGeometry(QRect(110, 370, 75, 24));
        Login->setFont(font);
        show_password = new QPushButton(frame);
        show_password->setObjectName("show_password");
        show_password->setGeometry(QRect(270, 140, 30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/hide-password.svg"), QSize(), QIcon::Normal, QIcon::Off);
        show_password->setIcon(icon);
        confirm_password = new QLineEdit(frame);
        confirm_password->setObjectName("confirm_password");
        confirm_password->setGeometry(QRect(30, 200, 240, 30));
        confirm_password->setFocusPolicy(Qt::StrongFocus);
        confirm_password->setContextMenuPolicy(Qt::DefaultContextMenu);
        confirm_password->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));
        confirm_password->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        confirm_password->setFrame(false);
        confirm_password->setEchoMode(QLineEdit::Password);
        confirm_password->setClearButtonEnabled(true);
        show_confirm_password = new QPushButton(frame);
        show_confirm_password->setObjectName("show_confirm_password");
        show_confirm_password->setGeometry(QRect(270, 200, 30, 30));
        show_confirm_password->setIcon(icon);
        warning_username = new QLabel(frame);
        warning_username->setObjectName("warning_username");
        warning_username->setGeometry(QRect(30, 110, 240, 20));
        warning_password = new QLabel(frame);
        warning_password->setObjectName("warning_password");
        warning_password->setGeometry(QRect(30, 170, 240, 20));
        warning_confirm_password = new QLabel(frame);
        warning_confirm_password->setObjectName("warning_confirm_password");
        warning_confirm_password->setGeometry(QRect(30, 230, 240, 20));
        ingame = new QLineEdit(frame);
        ingame->setObjectName("ingame");
        ingame->setGeometry(QRect(30, 260, 240, 30));
        ingame->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));
        pushButton = new QPushButton(registerform);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 10, 60, 60));
        pushButton->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border-radius: 30px;\n"
"background: red;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/user-regular.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(30, 30));
        frame_2 = new QFrame(registerform);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(-51, -21, 411, 511));
        frame_2->setStyleSheet(QString::fromUtf8("background-image: url(:/bg-01.jpg);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        Back_btn = new QPushButton(frame_2);
        Back_btn->setObjectName("Back_btn");
        Back_btn->setGeometry(QRect(40, 30, 75, 24));
        Back_btn->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: none;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/arrow-left-solid.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Back_btn->setIcon(icon2);
        Back_btn->setIconSize(QSize(30, 30));
        frame_2->raise();
        frame->raise();
        pushButton->raise();

        retranslateUi(registerform);

        QMetaObject::connectSlotsByName(registerform);
    } // setupUi

    void retranslateUi(QWidget *registerform)
    {
        registerform->setWindowTitle(QCoreApplication::translate("registerform", "Register", nullptr));
        label->setText(QCoreApplication::translate("registerform", "REGISTER HERE", nullptr));
        register_btn->setText(QCoreApplication::translate("registerform", "REGISTER", nullptr));
        username->setInputMask(QString());
        username->setText(QString());
        password->setText(QString());
        password->setPlaceholderText(QCoreApplication::translate("registerform", "Password", nullptr));
        label_2->setText(QCoreApplication::translate("registerform", "Have an account already?", nullptr));
        Login->setText(QCoreApplication::translate("registerform", "SIGN IN", nullptr));
        show_password->setText(QString());
        confirm_password->setText(QString());
        confirm_password->setPlaceholderText(QCoreApplication::translate("registerform", "Confirm password", nullptr));
        show_confirm_password->setText(QString());
        warning_username->setText(QString());
        warning_password->setText(QString());
        warning_confirm_password->setText(QString());
        ingame->setPlaceholderText(QCoreApplication::translate("registerform", "Ingame", nullptr));
        pushButton->setText(QString());
        Back_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class registerform: public Ui_registerform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_FORM_H
