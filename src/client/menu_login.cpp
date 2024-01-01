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
    user["username"] = client->getUser().username;
    client->sendRequestToServer(RequestType::LOGOUT, user);
    client->disconnectFromDevice();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();

    this->close();
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
    // qDebug() << roomName << "\n";

    user clientUser = client->getUser();

    QJsonObject roomInfo;
    roomInfo["room name"] = roomName;
    roomInfo["host user"] = clientUser.username;

    client->sendRequestToServer(RequestType::CREATEROOM, roomInfo);
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
    // std::cout << roomName << std::endl;
    // Game_Screen *room = new Game_Screen();
    // room->show();

    user clientUser = client->getUser();

    QJsonObject roomInfo;
    roomInfo["room name"] = roomName;
    roomInfo["player 2"] = clientUser.username;

    client->sendRequestToServer(RequestType::JOINROOM, roomInfo);

}

void mainmenulogin::setClient(TcpClient *client){
    this->client = client;
    connect(client, &TcpClient::dataReady, this, &mainmenulogin::handleServerResponse);
}

void mainmenulogin::handleServerResponse(const QByteArray& responseData){
    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
    if(jsonResponse["type"] == static_cast<int>(RespondType::CREATEROOM)){
        if(jsonResponse["message"] == "room created"){
            warning_create->setText("");
            room newRoom = room(jsonResponse["room name"].toString());
            player *playerX = new player();
            playerX->username = jsonResponse["host name"].toString();
            playerX->turn = 1;
            playerX->PIECETYPE = 'X';

            std::vector<room> roomList = client->getRoomList();
            for(auto room : roomList){
                if(room.roomName == jsonResponse["room name"].toString()){
                    room.addPlayer(*playerX);
                }
            }
            roomList.push_back(newRoom);
            client->setRoomList(roomList);

            qDebug() << "Room list size: " << client->getRoomList().size() << "\n";
        }else if(jsonResponse["message"] == "created fail"){
            warning_create->setText("Room name is existed");
        }else if(jsonResponse["message"] == "open room screen"){
            Game_Screen *room_screen = new Game_Screen();
            room_screen->setClient(client);
            room_screen->show();
            this->hide();
        }
    }else if(jsonResponse["type"] == static_cast<int>(RespondType::JOINROOM)){
        // qDebug() << jsonResponse << "\n";
        if(jsonResponse["message"] == "joined success"){
            warning_join->setText("");
            Game_Screen *room_screen = new Game_Screen();
            room_screen->setClient(client);
            room_screen->show();
            this->hide();
        }else if(jsonResponse["message"] == "joined failed"){
            warning_join->setText("This room is not existed!!");
        }else if(jsonResponse["message"] == "update room list"){
            QString player2_username = jsonResponse["player 2"].toString();
            QString room_name = jsonResponse["room name"].toString();
            player *playerO = new player();
            playerO->username = player2_username;
            playerO->PIECETYPE = 'O';
            playerO->turn = -1;

            std::vector<room> roomList = client->getRoomList();
            for(auto room : roomList){
                if(room.roomName == room_name){
                    room.addPlayer(*playerO);
                }
            }
            client->setRoomList(roomList);
            qDebug() << "Room list after join: " << client->getRoomList().size() << "\n";

        }
    }
}

