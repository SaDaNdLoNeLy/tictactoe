#include "login_form.h"
#include "ui_login_form.h"
#include "forgot_password.h"
#include "register_form.h"
#include "mainwindow.h"
#include <QLineEdit>
#include <QLabel>
#include <QIcon>
#include "menu_login.h"

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
}

loginform::~loginform()
{
    delete ui;
}

void loginform::setTcpClient(TcpClient *client){
    tcpClient = client;
    connect(tcpClient, &TcpClient::dataReady, this, &loginform::handleServerResponse);
}

TcpClient* loginform::getTcpClient(){
    return tcpClient;
}

void loginform::on_forgot_clicked()
{
    forgot_form->show();
}


void loginform::on_Register_clicked()
{
    res_form->setTcpClient(tcpClient);
    res_form->show();
    this->hide();
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
}

void loginform::handleServerResponse(const QByteArray& responseData){
    // qDebug() << responseData << "\n";
    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
    // qDebug() << jsonResponse << "\n";
    if(jsonResponse["type"] == static_cast<int>(RespondType::LOGIN)){
        if(jsonResponse["message"] == "login success"){
            warning_username->setText("");
            QJsonObject data;
            tcpClient->sendRequestToServer(RequestType::UPDATEDATA, data);

            QString username = jsonResponse["user"]["username"].toString();
            QString status = jsonResponse["user"]["status"].toString();
            int wins = jsonResponse["user"]["wins"].toInt();
            int loses = jsonResponse["user"]["loses"].toInt();
            bool isFree = jsonResponse["user"]["isFree"].toBool();
            double winRate = jsonResponse["user"]["winRate"].toDouble();
            int elo = jsonResponse["user"]["elo"].toInt();
            tcpClient->setUser(username, status, wins, loses, isFree, winRate, elo);

            mainmenulogin *menu_login = new mainmenulogin();
            menu_login->setClient(tcpClient);
            menu_login->show();
            this->hide();
        }else if(jsonResponse["message"] == "already login"){
            warning_username->setText("This account has been signed in another device");
        }else if(jsonResponse["message"] == "login fail"){
            warning_username->setText("Wrong username or password. Try again!");
        }else if(jsonResponse["message"] == "not existed"){
            warning_username->setText("This account is not existed");
        }
    }else if(jsonResponse["type"] == static_cast<int>(RespondType::UPDATEDATA)){
        qDebug() << "Response from update request: " << jsonResponse << "\n";
    }
}
