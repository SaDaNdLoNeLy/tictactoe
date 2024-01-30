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
    username = QWidget::findChild<QLabel*>("username");
    ingame = QWidget::findChild<QLabel*>("ingame");
    wins = QWidget::findChild<QLabel*>("wins");
    loses = QWidget::findChild<QLabel*>("loses");
    winrate = QWidget::findChild<QLabel*>("winrate");
    status = QWidget::findChild<QLabel*>("status");
    profile = QWidget::findChild<QFrame*>("frame");
    profile->setVisible(false);
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
    if(!roomName.isEmpty()){
        warning_create->setText("");
        QJsonObject roomData;
        roomData["room name"] = roomName;
        roomData["player X username"] = client->getUser().username;
        qDebug() << client->getUser().username << "\n";
        qDebug() << roomName;
        client->sendRequestToServer(RequestType::CREATEROOM, roomData);
    }else{
        warning_create->setText("Room name cannot be empty");
    }

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
    if(!roomName.isEmpty()){
        warning_join->setText("");
        QJsonObject roomData;
        roomData["room name"] = roomName;
        roomData["player O username"] = client->getUser().username;
        client->sendRequestToServer(RequestType::JOINROOM, roomData);
    }else{
        warning_join->setText("Room name cannot be empty");
    }

}

void mainmenulogin::setClient(TcpClient *client){
    this->client = client;
    connect(client, &TcpClient::dataReady, this, &mainmenulogin::handleServerResponse);
}

void mainmenulogin::handleServerResponse(const QByteArray& responseData){
    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
    if(jsonResponse["type"] == static_cast<int>(ResponseType::CREATEROOM)){
        if(jsonResponse["message"] == "create success"){
            qDebug() << "test game screen: " << "\n";
            Game_Screen *room_screen = new Game_Screen();
            room_screen->setClient(client);
            room_screen->show();
            this->hide();

            QJsonObject room_data = jsonResponse["data"].toObject();
            // create new room
            room *new_room = new room();
            new_room->roomName = room_data["name"].toString();
            new_room->playerX = client->findUserByUsername(room_data["player X username"].toString());
            client->setRoomIn4(*new_room);

            // add new room to room list
            std::vector<room> room_list = client->getRoomList();
            room_list.push_back(*new_room);
            client->setRoomList(room_list);
        }else if(jsonResponse["message"] == "create fail"){
            warning_create->setText("This room is existed");
        }
    }else if(jsonResponse["type"] == static_cast<int>(ResponseType::UPDATEROOMLIST)){
        if(jsonResponse["message"] == "add room to room list"){
            QJsonObject room_data = jsonResponse["data"].toObject();

            room *new_room = new room();
            new_room->roomName = room_data["name"].toString();
            new_room->playerX = client->findUserByUsername(room_data["player X username"].toString());

            std::vector<room> room_list = client->getRoomList();
            room_list.push_back(*new_room);
            client->setRoomList(room_list);
        }else if(jsonResponse["message"] == "add player to room"){
            QString room_name = jsonResponse["room name"].toString();
            QString player_O_username = jsonResponse["player O username"].toString();
            std::vector<room> room_list = client->getRoomList();

            for(room &room_value : room_list){
                if(room_value.roomName == room_name){
                    room_value.playerO = client->findUserByUsername(player_O_username);
                    room_value.isFull = true;
                    if(client->getUser().username == room_value.playerX.username){
                        client->setRoomIn4(room_value);
                    }
                }
            }

            client->setRoomList(room_list);
        }
    }else if(jsonResponse["type"] == static_cast<int>(ResponseType::JOINROOM)){
        if(jsonResponse["message"] == "full"){
            warning_join->setText("This room is full!");
        }else if(jsonResponse["message"] == "join success"){
            Game_Screen *room_screen = new Game_Screen();
            room_screen->setClient(client);
            room_screen->show();
            this->hide();

            QString room_name = jsonResponse["room name"].toString();
            std::vector<room> room_list = client->getRoomList();
            for(room &room_value: room_list){
                if(room_value.roomName == room_name){
                    room_value.playerO = client->findUserByUsername(client->getUser().username);
                    room_value.isFull = true;
                    client->setRoomIn4(room_value);
                }
            }
            client->setRoomList(room_list);
        }
    }

}


void mainmenulogin::on_EditProfile_clicked()
{
    profile->setVisible(true);
    username->setText(client->getUser().username);
    winrate->setText(QString::number(client->getUser().winRate));
    wins->setText(QString::number(client->getUser().wins));
    loses->setText(QString::number(client->getUser().loses));
    status->setText(QString::number(client->getUser().elo));
    ingame->setText(client->getUser().ingame);
}


void mainmenulogin::on_pushButton_clicked()
{
    profile->setVisible(false);
}

