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

    username = QWidget::findChild<QLineEdit*>("username");
    password = QWidget::findChild<QLineEdit*>("password");
    confirm_password = QWidget::findChild<QLineEdit*>("confirm_password");
    ingame = QWidget::findChild<QLineEdit*>("ingame");
    warning_username = QWidget::findChild<QLabel*>("warning_username");
    warning_password = QWidget::findChild<QLabel*>("warning_password");
    warning_confirm_password = QWidget::findChild<QLabel*>("warning_confirm_password");
}

registerform::~registerform()
{
    delete ui;
}

void registerform::setTcpClient(TcpClient *client){
    this->client = client;
    connect(this->client, &TcpClient::dataReady, this, &registerform::handleServerResponse);
}

TcpClient& registerform::getTcpClient(){
    return *client;
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
    if(username && password && confirm_password && warning_username && warning_password && warning_confirm_password){
        // check username blank
        if(username->text().isEmpty()){
            warning_username->setText("Username cannot be blank!!!");
            return;
        }else{
            warning_username->setText("");
        }

        // check password blank
        if(password->text().isEmpty()){
            warning_password->setText("Password cannot be blank!!!");
            return;
        }else{
            warning_password->setText("");
        }

        // check confirm password blank
        if(confirm_password->text().isEmpty()){
            warning_confirm_password->setText("Confirm password cannot be blank!!!");
            return;
        }else{
            if(password->text() == confirm_password->text()){
                warning_confirm_password->setText("");
            }else{
                warning_confirm_password->setText("Confirm password must be similar to password");
                return;
            }
        }
        QJsonObject newUser;
        newUser["username"] = username->text();
        newUser["password"] = password->text();
        newUser["ingame"] = ingame->text();
        client->sendRequestToServer(RequestType::REGISTER, newUser);
    }
}

void registerform::on_Login_clicked()
{
    loginform *loginUi = new loginform();
    loginUi->setTcpClient(client);
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
    loginform *loginUI = new loginform();
    loginUI->setTcpClient(client);
    loginUI->show();
    this->hide();
}

void registerform::handleServerResponse(const QByteArray& responseData){
    // qDebug() << responseData << "\n";
    QJsonDocument response = QJsonDocument::fromJson(responseData);
    if(response["type"] == static_cast<int>(ResponseType::REGISTER)){
        if(response["message"] == "register successfully"){
            QJsonObject data;
            // client->sendRequestToServer(RequestType::UPDATEDATA, data);
            loginform *loginUI = new loginform();
            loginUI->setTcpClient(client);
            loginUI->show();
            this->hide();
        }else if(response["message"] == "existed username"){
            warning_username->setText("This username has already existed");
        }else if(response["message"] == "existed ingame"){
            warning_username->setText("This ingame has already existed");
        }
    }
}

