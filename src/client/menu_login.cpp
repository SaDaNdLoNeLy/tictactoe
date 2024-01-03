#include "menu_login.h"
#include "ui_menu_login.h"
#include "mainwindow.h"
#include <QPushButton>
#include <iostream>
#include <QLineEdit>

mainmenulogin::mainmenulogin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainmenulogin)
{
    ui->setupUi(this);
    createRoom = QWidget::findChild<QFrame*>("createRoom");
    joinRoom = QWidget::findChild<QFrame*>("joinRoom");
    createRoomInput = QWidget::findChild<QLineEdit*>("roomNameInput");
    joinRoomInput = QWidget::findChild<QLineEdit*>("joinInput");

    warning_create = QWidget::findChild<QLabel*>("warning_create");
    warning_join = QWidget::findChild<QLabel*>("warning_join");
    createRoom->close();
    joinRoom->close();
    // connect(client, &TcpClient::dataReady, this, &mainmenulogin::handleServerResponse);
}

mainmenulogin::~mainmenulogin()
{
    delete ui;
}

void mainmenulogin::on_logout_clicked()
{
    QJsonObject user;
    QJsonObject data;
    user["username"] = client->getUser().username;
    client->sendRequestToServer(RequestType::LOGOUT, user);

    // client->sendRequestToServer(RequestType::UPDATEDATA, data);
    client->disconnectFromDevice();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
    this->hide();
}


void mainmenulogin::on_CreateRoom_clicked()
{
    createRoom->show();
}


void mainmenulogin::on_cancel_clicked()
{
    createRoom->close();
}


void mainmenulogin::on_create_clicked()
{
    QString roomName = createRoomInput->text();
    QJsonObject roomData;
    roomData["room name"] = roomName;
    roomData["player X username"] = client->getUser().username;
    client->sendRequestToServer(RequestType::CREATEROOM, roomData);
}


void mainmenulogin::on_JoinRoom_clicked()
{
    joinRoom->show();
}


void mainmenulogin::on_cancel_3_clicked()
{
    joinRoom->close();
}


void mainmenulogin::on_join_clicked()
{
    QString roomName = joinRoomInput->text();
    QJsonObject roomData;
    roomData["room name"] = roomName;
    roomData["player O username"] = client->getUser().username;
    client->sendRequestToServer(RequestType::JOINROOM, roomData);
}

void mainmenulogin::setClient(TcpClient *client){
    this->client = client;
    connect(client, &TcpClient::dataReady, this, &mainmenulogin::handleServerResponse);
}

void mainmenulogin::handleServerResponse(const QByteArray& responseData){
    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
    qDebug() << "Response from menu login: " << jsonResponse << "\n";
    if(jsonResponse["type"] == static_cast<int>(ResponseType::CREATEROOM)){
        if(jsonResponse["message"] == "create success"){
            warning_create->setText("");
            client->setRoomName(jsonResponse["room infor"]["room name"].toString());
            room newRoom;
            newRoom.roomName = jsonResponse["room infor"]["room name"].toString();
            newRoom.playerX = client->findUserByUsername(jsonResponse["room infor"]["player X username"].toString());
            std::vector<room> roomList = client->getRoomList();
            roomList.push_back(newRoom);
            client->setRoomList(roomList);
            qDebug() << "room list: " << client->getRoomList().size();

            Game_Screen *room_screen = new Game_Screen();
            room_screen->setClient(client);
            room_screen->show();
            this->hide();
        }else if(jsonResponse["type"] == "create fail"){
            warning_create->setText("This room name is existed");
        }
    }else if(jsonResponse["type"] == static_cast<int>(ResponseType::JOINROOM)){
        if(jsonResponse["message"] == "join success"){
            warning_join->setText("");
            client->setRoomName(jsonResponse["room name"].toString());
            Game_Screen *room_screen = new Game_Screen();
            room_screen->setClient(client);
            room_screen->show();
            this->hide();
        }else if(jsonResponse["message"] == "full"){
            warning_join->setText("This room is full");
        }else if(jsonResponse["message"] == "join fail"){
            warning_join->setText("This room is now existed");
        }
    }else if(jsonResponse["type"] == static_cast<int>(ResponseType::UPDATEROOMLIST)){
        if(jsonResponse["message"] == "add to room list"){
            room newRoom;
            newRoom.roomName = jsonResponse["room infor"]["room name"].toString();
            newRoom.playerX = client->findUserByUsername(jsonResponse["room infor"]["player X username"].toString());

            std::vector<room> roomList;
            roomList.push_back(newRoom);
            client->setRoomList(roomList);
            client->setRoomIn4(client->findRoomByRoomName(client->getRoomName()));
            qDebug() << "size room list: " << client->getRoomIn4().roomName << "\n";
        }
    }
}

