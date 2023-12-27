#include "login_form.h"
#include "ui_login_form.h"
#include "forgot_password.h"
#include "register_form.h"
#include "mainwindow.h"
#include <QLineEdit>
#include <QLabel>
#include <QIcon>
#include "menu_login.h"
#include <iostream>

loginform::loginform(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::loginform)
{
    ui->setupUi(this);
    forgot_form = new forgot_password();
    res_form = new registerform();
}

loginform::~loginform()
{
    delete ui;
}


void loginform::on_forgot_clicked()
{
    forgot_form->show();
}


void loginform::on_Register_clicked()
{
    res_form->show();
    this->close();
}

void loginform::on_Back_btn_clicked()
{
    this->close();
    MainWindow *main_UI = new MainWindow();
    main_UI->show();
}




void loginform::on_show_password_clicked()
{
    QIcon *hide_pass = new QIcon(":/hide-password.svg");
    QIcon *show_pass = new QIcon(":/show-password.svg");
    show_pass_btn = QWidget::findChild<QPushButton*>("show_password");
    password = QWidget::findChild<QLineEdit*>("password");
    if(show_pass_btn && password){
        if(password->echoMode() == QLineEdit::Password){
            show_pass_btn->setIcon(*show_pass);
            password->setEchoMode(QLineEdit::Normal);
        }else if(password->echoMode() == QLineEdit::Normal){
            show_pass_btn->setIcon(*hide_pass);
            password->setEchoMode(QLineEdit::Password);
        }
    }
}


void loginform::on_login_btn_clicked()
{
    mainmenulogin *main_menu = new mainmenulogin();
    QLineEdit *username_input = QWidget::findChild<QLineEdit*>("username");
    QLineEdit *password_input = QWidget::findChild<QLineEdit*>("password");
    QLabel *warning_username = QWidget::findChild<QLabel*>("warning_username");
    QLabel *warning_password = QWidget::findChild<QLabel*>("warning_password");

    if(username_input->text().toStdString() == ""){
        warning_username->setText("Username cannot be blank !!!");
    }else{
        warning_username->setText("");
    }

    if(password_input->text().toStdString() == ""){
        warning_password ->setText("Password cannot be blank !!!");
    }else{
        warning_password->setText("");
    }

    if(username_input->text().toStdString() != "" && password_input->text().toStdString() != ""){
        main_menu->show();
        this->close();
        // std::cout << username_input->text().toStdString() << std::endl;
        // std::cout << password_input->text().toStdString() << std::endl;
    }
}

