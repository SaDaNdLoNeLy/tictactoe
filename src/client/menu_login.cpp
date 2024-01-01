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
    qDebug() << roomName << "\n";

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
    std::string roomName = joinRoomInput->text().toStdString();
    std::cout << roomName << std::endl;
    Game_Screen *room = new Game_Screen();
    room->show();
}

void mainmenulogin::setClient(TcpClient *client){
    this->client = client;
    connect(client, &TcpClient::dataReady, this, &mainmenulogin::handleServerResponse);
}

void mainmenulogin::handleServerResponse(const QByteArray& responseData){
    qDebug() << responseData << "\n";
    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
    if(jsonResponse["type"] == static_cast<int>(RespondType::CREATEROOM)){
        if(jsonResponse["message"] == "room created"){
            // user host_user = client->findUserByUsername(jsonResponse["host name"].toString());
            player *playerX = new player();
            playerX->username = jsonResponse["host name"].toString();
            playerX->turn = 1;
            playerX->PIECETYPE = 'X';

            room newRoom = room(jsonResponse["room name"].toString());
            newRoom.addPlayer(*playerX);

            std::vector<room> roomList = client->getRoomList();
            roomList.push_back(newRoom);
            // qDebug() << "Room list size: " << roomList.size() << "\n";
            client->setRoomList(roomList);

            warning_create->setText("");
            qDebug() << "Room list size: " << client->getRoomList().size() << "\n";


        }else if(jsonResponse["message"] == "created fail"){
            warning_create->setText("Room name is existed");
        }else if(jsonResponse["message"] == "update room list"){
            qDebug() << "list room size " << client->getRoomList().size();
        }
    }
}

