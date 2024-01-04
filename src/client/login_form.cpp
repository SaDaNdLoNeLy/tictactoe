#include "login_form.h"
#include "ui_login_form.h"
#include "forgot_password.h"
#include "register_form.h"
#include "mainwindow.h"
#include <QLineEdit>
#include <QLabel>
#include <QIcon>
#include <cmath>
#include <iomanip>
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
    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
    // qDebug() << "login screen: " << jsonResponse << "\n";
    if(jsonResponse["type"] == static_cast<int>(ResponseType::LOGIN)){
        if(jsonResponse["message"] == "login success"){
            QJsonObject data;
            QJsonObject login_user = jsonResponse["user"].toObject();
            user *loginUser = new user();
            loginUser->username = login_user["username"].toString();
            loginUser->ingame = login_user["ingame"].toString();
            loginUser->isFree = login_user["is free"].toBool();
            loginUser->wins = login_user["wins"].toInt();
            loginUser->loses = login_user["loses"].toInt();
            loginUser->elo = login_user["elo"].toInt();
            loginUser->status = login_user["status"].toString();
            loginUser->winRate = login_user["win rate"].toDouble();
            tcpClient->setUserfromUser(*loginUser);
            tcpClient->sendRequestToServer(RequestType::GETONLINEUSER, data);
            // tcpClient->sendRequestToServer(RequestType::GETROOMLIST, data);

            mainmenulogin *menu_login = new mainmenulogin();
            menu_login->setClient(tcpClient);
            menu_login->show();
            this->hide();
        }else if(jsonResponse["message"] == "login fail"){
            warning_username->setText("wrong username or password. Try again!");
        }else if(jsonResponse["message"] == "already login"){
            warning_username->setText("this account has been signed in another device!");
        }
    }else if(jsonResponse["type"] == static_cast<int>(ResponseType::GETONLINEUSER)){
        QJsonArray online_list = jsonResponse["online user"].toArray();
        std::vector<user> online_user;

        for(QJsonValue online_player : online_list){
            QJsonObject userObject = online_player.toObject();
            user *onlineUser = new user();
            onlineUser->username = userObject["username"].toString();
            onlineUser->status = userObject["status"].toString();
            onlineUser->elo = userObject["elo"].toInt();
            onlineUser->ingame = userObject["ingame"].toString();
            onlineUser->isFree = userObject["isFree"].toBool();
            onlineUser->wins = userObject["wins"].toInt();
            onlineUser->loses = userObject["losses"].toInt();
            onlineUser->winRate = userObject["win rate"].toDouble();

            online_user.push_back(*onlineUser);
        }
        tcpClient->setOnlineUser(online_user);
        // qDebug() << tcpClient->getOnlineUser()[0].username << "\n";
        if(jsonResponse["room list size"].toInt() > 0){
            QJsonObject data;
            tcpClient->sendRequestToServer(RequestType::GETROOMLIST, data);
        }
    }else if(jsonResponse["type"] == static_cast<int>(RequestType::UPDATEONLINEUSER)){
        if(jsonResponse["message"] == "add user to online list"){
            QJsonObject userObject = jsonResponse["user"].toObject();
            user *onlineUser = new user();
            onlineUser->username = userObject["username"].toString();
            onlineUser->status = userObject["status"].toString();
            onlineUser->elo = userObject["elo"].toInt();
            onlineUser->ingame = userObject["ingame"].toString();
            onlineUser->isFree = userObject["isFree"].toBool();
            onlineUser->wins = userObject["wins"].toInt();
            onlineUser->loses = userObject["losses"].toInt();
            onlineUser->winRate = userObject["win rate"].toDouble();

            std::vector<user> online_list = tcpClient->getOnlineUser();
            online_list.push_back(*onlineUser);
            tcpClient->setOnlineUser(online_list);
            qDebug() << "update online user size: " << tcpClient->getOnlineUser().size() << "\n";
        }
    }else if(jsonResponse["type"] == static_cast<int>(RequestType::GETROOMLIST)){
        QJsonArray room_list = jsonResponse["room list"].toArray();
        std::vector<room> updated_room_list;

        for(QJsonValue roomValue : room_list){
            QJsonObject room_data = roomValue.toObject();
            room *new_room = new room();
            new_room->roomName = room_data["room name"].toString();
            new_room->player1_ready = room_data["player1_ready"].toBool();
            new_room->player2_ready = room_data["player2_ready"].toBool();
            new_room->isFull = room_data["is full"].toBool();
            new_room->gameStart = room_data["game start"].toBool();
            new_room->turn = room_data["turn"].toInt();
            new_room->isPlayerXTurn = room_data["is player X turn"].toBool();
            new_room->nextBoard = room_data["next board"].toInt();
            new_room->playerX = tcpClient->findUserByUsername(room_data["player X username"].toString());
            if(new_room->isFull){
                new_room->playerO = tcpClient->findUserByUsername(room_data["player O username"].toString());
            }

            updated_room_list.push_back(*new_room);
        }
        tcpClient->setRoomList(updated_room_list);
    }
}
