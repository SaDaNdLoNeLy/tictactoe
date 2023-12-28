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

    username_input = QWidget::findChild<QLineEdit*>("username");
    password_input = QWidget::findChild<QLineEdit*>("password");

    warning_username = QWidget::findChild<QLabel*>("warning_username");
    warning_password = QWidget::findChild<QLabel*>("warning_password");

    qDebug() << "Login From Client " << &tcpClient << "\n";
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
    tcpClient->disconnectFromDevice(); // Ngắt kết nối
    this->close();
    MainWindow *main_UI = new MainWindow();
    main_UI->show();
}




void loginform::on_show_password_clicked()
{
    QIcon *hide_pass = new QIcon(":/hide-password.svg");
    QIcon *show_pass = new QIcon(":/show-password.svg");
    show_pass_btn = QWidget::findChild<QPushButton*>("show_password");
    password_input = QWidget::findChild<QLineEdit*>("password");
    if(show_pass_btn && password_input){
        if(password_input->echoMode() == QLineEdit::Password){
            show_pass_btn->setIcon(*show_pass);
            password_input->setEchoMode(QLineEdit::Normal);
        }else if(password_input->echoMode() == QLineEdit::Normal){
            show_pass_btn->setIcon(*hide_pass);
            password_input->setEchoMode(QLineEdit::Password);
        }
    }
}


void loginform::on_login_btn_clicked()
{
    mainmenulogin *main_menu = new mainmenulogin();
    if(username_input->text().isEmpty()){
        warning_username->setText("Username cannot be blank !!!");
        return;
    }else{
        warning_username->setText("");
    }

    if(password_input->text().isEmpty()){
        warning_password ->setText("Password cannot be blank !!!");
        return;
    }else{
        warning_password->setText("");
    }

    QJsonObject user;
    user["username"] = username_input->text();
    user["password"] = password_input->text();

    tcpClient->sendRequestToServer(RequestType::LOGIN, user);
    connect(tcpClient, &TcpClient::dataReady, this, &loginform::handleServerResponse);
    // qDebug() << tcpClient->getServerResponse();
}

void loginform::setTcpClient(TcpClient *client){
    tcpClient = client;
    // connect(tcpClient, &TcpClient::dataReady, this, &loginform::handleServerResponse);
}

void loginform::handleServerResponse(const QByteArray& responseData){
    // qDebug() << "Received response from server:" << responseData;
    if(responseData == "fail"){
        warning_password->setText("Wrong username or password. Try again!");
    }else if(responseData == "success"){
        this->close();
        mainmenulogin *menu = new mainmenulogin();
        // menu->setClient(tcpClient);
        menu->show();
    }else if(responseData == "block"){
        warning_password->setText("This account has been blocked!");
    }
}

