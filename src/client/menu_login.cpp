#include "menu_login.h"
#include "ui_menu_login.h"
#include "mainwindow.h"
#include <QPushButton>
#include <iostream>

mainmenulogin::mainmenulogin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainmenulogin)
{
    ui->setupUi(this);
    createRoom = QWidget::findChild<QFrame*>("createRoom");
    joinRoom = QWidget::findChild<QFrame*>("joinRoom");
    createRoomInput = QWidget::findChild<QLineEdit*>("roomNameInput");
    joinRoomInput = QWidget::findChild<QLineEdit*>("joinInput");
    createRoom->close();
    joinRoom->close();

    qDebug() << "Main menu login client: " << &client << "\n";
}

mainmenulogin::~mainmenulogin()
{
    delete ui;
}

void mainmenulogin::on_logout_clicked()
{
    MainWindow *logout_UI = new MainWindow();
    logout_UI->show();
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
    std::string roomName = createRoomInput->text().toStdString();
    std::cout << roomName << std::endl;
    Game_Screen *room = new Game_Screen();
    room->show();
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
}

