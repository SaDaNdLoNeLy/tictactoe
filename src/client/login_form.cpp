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
    QJsonDocument jsonObject = QJsonDocument::fromJson(responseData);
    if(jsonObject["type"] == static_cast<int>(RespondType::LOGIN)){
        if(jsonObject["message"] == "fail"){
            warning_password->setText("Wrong username or password. Try again!");
        }else if(jsonObject["message"] == "already login"){
            warning_password->setText("This account has been logged in another device");
        }else if(jsonObject["message"] == "success"){
            warning_password->setText("");

            QString username = jsonObject["user"]["username"].toString();
            QString status = jsonObject["user"]["status"].toString();
            int wins = jsonObject["user"]["wins"].toInt();
            int loses = jsonObject["user"]["loses"].toInt();
            bool isFree = jsonObject["user"]["isFree"].toBool();
            double winRate = jsonObject["user"]["winRate"].toDouble();
            int elo = jsonObject["user"]["elo"].toInt();
            tcpClient->setUser(username, status, wins, loses, isFree, winRate, elo);

            this->hide();
            mainmenulogin *menu = new mainmenulogin();
            menu->setClient(tcpClient);
            menu->show();
        }else{
            warning_password->setText("This account is not existed");
        }
    }else if(jsonObject["type"] == static_cast<int>(RespondType::ONLINEPLAYER)){
        // qDebug() << jsonObject << "\n";
        std::vector<user> onlineUsers;
        if(jsonObject["message"] == "online users"){
            QJsonArray usersArray = jsonObject["users"].toArray();

            for(auto userValue : usersArray){
                QJsonObject userObject = userValue.toObject();

                user currentUser;
                currentUser.elo = userObject["elo"].toInt();
                currentUser.isFree = userObject["isFree"].toBool();
                currentUser.loses = userObject["loses"].toInt();
                currentUser.status = userObject["status"].toString();
                currentUser.username = userObject["username"].toString();
                currentUser.winRate = userObject["winRate"].toDouble();
                currentUser.wins = userObject["wins"].toInt();

                onlineUsers.push_back(currentUser);
            }
            qDebug() << "size: " << onlineUsers.size() << "\n";
            tcpClient->setOnlineUser(onlineUsers);
        }
    }
}
