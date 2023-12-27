#include "register_form.h"
#include "ui_register_form.h"
#include <QLineEdit>
#include <QIcon>
#include <QLabel>
#include "login_form.h"
#include <iostream>

registerform::registerform(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::registerform)
{
    ui->setupUi(this);
}

registerform::~registerform()
{
    delete ui;
}

void registerform::on_show_password_clicked()
{
    QIcon *hide_pass = new QIcon(":/hide-password.svg");
    QIcon *show_pass = new QIcon(":/show-password.svg");
    show_btn = QWidget::findChild<QPushButton*>("show_password");
    QLineEdit *pass_input = QWidget::findChild<QLineEdit*>("password");
    if(show_btn && pass_input){
        if(pass_input->echoMode() == QLineEdit::Password){
            show_btn->setIcon(*show_pass);
            pass_input->setEchoMode(QLineEdit::Normal);
        }else if(pass_input->echoMode() == QLineEdit::Normal){
            show_btn->setIcon(*hide_pass);
            pass_input->setEchoMode(QLineEdit::Password);
        }
    }
}


void registerform::on_register_btn_clicked()
{
    QLineEdit *username = QWidget::findChild<QLineEdit*>("username");
    QLineEdit *password = QWidget::findChild<QLineEdit*>("password");
    QLineEdit *confirm_password = QWidget::findChild<QLineEdit*>("confirm_password");
    QLabel *warning_username = QWidget::findChild<QLabel*>("warning_username");
    QLabel *warning_password = QWidget::findChild<QLabel*>("warning_password");
    QLabel *warning_confirm_password = QWidget::findChild<QLabel*>("warning_confirm_password");
    bool valid_username = false;
    bool valid_password = false;
    bool valid_confirm_password = false;


    if(username && password && confirm_password && warning_username && warning_password && warning_confirm_password){
        // check username blank
        if(username->text().toStdString() == ""){
            warning_username->setText("Username cannot be blank!!!");
            valid_username = false;
        }else{
            warning_username->setText("");
            valid_username = true;
        }

        // check password blank
        if(password->text().toStdString() == ""){
            warning_password->setText("Password cannot be blank!!!");
            valid_password = false;
        }else{
            warning_password->setText("");
            valid_password = true;
        }

        // check confirm password blank
        if(confirm_password->text().toStdString() == ""){
            warning_confirm_password->setText("Confirm password cannot be blank!!!");
            valid_confirm_password = false;
        }else{
            if(password->text().toStdString() == confirm_password->text().toStdString()){
                warning_confirm_password->setText("");
                valid_confirm_password = true;
            }else{
                warning_confirm_password->setText("Confirm password must be similar to password");
                valid_confirm_password = false;
            }
        }

        if(valid_username && valid_password && valid_confirm_password){
            std::cout << "Login successfully" << std::endl;
        }
    }
}


void registerform::on_Login_clicked()
{
    loginform *loginUi = new loginform();
    loginUi->show();
    this->close();
}


void registerform::on_show_confirm_password_clicked()
{
    QIcon *hide_pass = new QIcon(":/hide-password.svg");
    QIcon *show_pass = new QIcon(":/show-password.svg");
    show_btn = QWidget::findChild<QPushButton*>("show_confirm_password");
    QLineEdit *pass_input = QWidget::findChild<QLineEdit*>("confirm_password");
    if(show_btn && pass_input){
        if(pass_input->echoMode() == QLineEdit::Password){
            show_btn->setIcon(*show_pass);
            pass_input->setEchoMode(QLineEdit::Normal);
        }else if(pass_input->echoMode() == QLineEdit::Normal){
            show_btn->setIcon(*hide_pass);
            pass_input->setEchoMode(QLineEdit::Password);
        }
    }
}


void registerform::on_Back_btn_clicked()
{
    this->close();
    loginform *loginUI = new loginform();
    loginUI->show();
}

