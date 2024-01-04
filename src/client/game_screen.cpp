#include "game_screen.h"
#include "qjsondocument.h"
#include "ui_game_screen.h"
#include <QLabel>
#include <iostream>

Game_Screen::Game_Screen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game_Screen)
{
    ui->setupUi(this);
    QLabel *noti = QMainWindow::findChild<QLabel*>("notification");
    noti->setVisible(false);

    setUpGrid();
    player1_name = QMainWindow::findChild<QLabel*>("name");
    player2_name = QMainWindow::findChild<QLabel*>("name_2");

    player2_elo = QMainWindow::findChild<QLabel*>("elo_2");
    player1_elo = QMainWindow::findChild<QLabel*>("elo");

    player1_win = QMainWindow::findChild<QLabel*>("win");
    player2_win = QMainWindow::findChild<QLabel*>("win_2");

    readyButton = QMainWindow::findChild<QPushButton*>("readyButton");

}

Game_Screen::~Game_Screen()
{
    delete ui;
}

void Game_Screen::setClient(TcpClient *client){
    this->client = client;
    connect(client, &TcpClient::dataReady, this, &Game_Screen::handleServerResponse);
    connect(client, &TcpClient::roomIn4Changed, this, &Game_Screen::handleRoomIn4Changed);
}

void Game_Screen::handleRoomIn4Changed(const room& newRoom){
    player1_name->setText(client->getRoomIn4().playerX.ingame);
    player1_elo->setText("Elo: " + QString::number(client->getRoomIn4().playerX.elo));
    player1_win->setText("Win: " + QString::number(client->getRoomIn4().playerX.wins) + " - " + QString::number(client->getRoomIn4().playerX.winRate) + "%");

    if(client->getRoomIn4().isFull){
        player2_name->setText(client->getRoomIn4().playerO.ingame);
        player2_elo->setText("Elo: " + QString::number(client->getRoomIn4().playerO.elo));
        player2_win->setText("Win: " + QString::number(client->getRoomIn4().playerO.wins) + " - " + QString::number(client->getRoomIn4().playerO.winRate) + "%");
    }

    if(client->getRoomIn4().turn == -2){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                itemButtons[i][j]->setDisabled(true);
            }
        }
    }

    if(client->getRoomIn4().player2_ready){
        if(client->getUser().username == client->getRoomIn4().playerX.username){
            readyButton->setText("START");
        }
    }else{
        if(client->getUser().username == client->getRoomIn4().playerX.username && !client->getRoomIn4().player1_ready){
            readyButton->setText("READY");
        }else if(client->getUser().username == client->getRoomIn4().playerX.username && client->getRoomIn4().player1_ready){
            readyButton->setText("UNREADY");
        }
    }
}

void Game_Screen::handleServerResponse(const QByteArray& responseData){
    QJsonDocument responseJson = QJsonDocument::fromJson(responseData);
    // client->setRoomIn4(client->findRoomByRoomName(client->getRoomName()));
    // qDebug() << "Game screen response: " << responseJson << "\n";
    if(responseJson["type"] == static_cast<int>(ResponseType::READY)){
        std::vector<room> room_list = client->getRoomList();
        QString room_name = responseJson["room name"].toString();
        QString player_ready = responseJson["player username"].toString();

        for(room &value: room_list){
            if(value.roomName == room_name){
                if(value.playerX.username == player_ready){
                    value.player1_ready = true;
                }
                if(value.playerO.username == player_ready){
                    value.player2_ready = true;
                }
            }
        }
        client->setRoomList(room_list);
        room update_room = client->findRoomByRoomName(room_name);

        if(client->getUser().username == update_room.playerX.username || client->getUser().username == update_room.playerO.username){
            client->setRoomIn4(update_room);
        }
    }
}

void Game_Screen::setUpGrid(){
    frames[0] = QMainWindow::findChild<QFrame*>("gridFrame");
    frames[1] = QMainWindow::findChild<QFrame*>("gridFrame_2");
    frames[2] = QMainWindow::findChild<QFrame*>("gridFrame_3");
    frames[3] = QMainWindow::findChild<QFrame*>("gridFrame_4");
    frames[4] = QMainWindow::findChild<QFrame*>("gridFrame_5");
    frames[5] = QMainWindow::findChild<QFrame*>("gridFrame_6");
    frames[6] = QMainWindow::findChild<QFrame*>("gridFrame_7");
    frames[7] = QMainWindow::findChild<QFrame*>("gridFrame_8");
    frames[8] = QMainWindow::findChild<QFrame*>("gridFrame_9");

    layouts[0] = QMainWindow::findChild<QGridLayout*>("gridLayout");
    layouts[0]->parent()->setObjectName(QString::number(0));
    layouts[1] = QMainWindow::findChild<QGridLayout*>("gridLayout_2");
    layouts[1]->parent()->setObjectName(QString::number(1));
    layouts[2] = QMainWindow::findChild<QGridLayout*>("gridLayout_3");
    layouts[2]->parent()->setObjectName(QString::number(2));
    layouts[3] = QMainWindow::findChild<QGridLayout*>("gridLayout_4");
    layouts[3]->parent()->setObjectName(QString::number(3));
    layouts[4] = QMainWindow::findChild<QGridLayout*>("gridLayout_5");
    layouts[4]->parent()->setObjectName(QString::number(4));
    layouts[5] = QMainWindow::findChild<QGridLayout*>("gridLayout_6");
    layouts[5]->parent()->setObjectName(QString::number(5));
    layouts[6] = QMainWindow::findChild<QGridLayout*>("gridLayout_7");
    layouts[6]->parent()->setObjectName(QString::number(6));
    layouts[7] = QMainWindow::findChild<QGridLayout*>("gridLayout_8");
    layouts[7]->parent()->setObjectName(QString::number(7));
    layouts[8] = QMainWindow::findChild<QGridLayout*>("gridLayout_9");
    layouts[8]->parent()->setObjectName(QString::number(8));

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            QString text = "";
            //        itemButtons[i] = new QPushButton();
            //        connect(itemButtons[i],SIGNAL(clicked()),this,SLOT(itemClicked()));
            itemButtons[i][j] = createButton(text,SLOT(itemClicked()));
            itemButtons[i][j]->setObjectName(QString::number(j));
            // Move Move(i / 3, i % 3, j / 3, j % 3);
            // std::cout << itemButtons[i][j]->objectName().toStdString() << std::endl;
        }
    }

    for(int j=0; j<9; j++){
        for(int i=0; i<9; i++){
            int row = i/3;
            int column = i%3;
            if(i / 9 == 0)
                layouts[0]->addWidget(itemButtons[0][i],row,column);
            if(i / (9*2) == 0)
                layouts[1]->addWidget(itemButtons[1][i],row,column);
            if(i / (9*3) == 0)
                layouts[2]->addWidget(itemButtons[2][i],row,column);
            if(i / (9*4) == 0)
                layouts[3]->addWidget(itemButtons[3][i],row,column);
            if(i / (9*5) == 0)
                layouts[4]->addWidget(itemButtons[4][i],row,column);
            if(i / (9*6) == 0)
                layouts[5]->addWidget(itemButtons[5][i],row,column);
            if(i / (9*7) == 0)
                layouts[6]->addWidget(itemButtons[6][i],row,column);
            if(i / (9*8) == 0)
                layouts[7]->addWidget(itemButtons[7][i],row,column);
            if(i / (9*9) == 0)
                layouts[8]->addWidget(itemButtons[8][i],row,column);
        }
    }
}

QPushButton *Game_Screen::createButton(QString &text, const QString member/*const char *member*/){
    //Creates button and sets size policy. Connects button's signal to slot

    QPushButton *button = new QPushButton;
    button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    button->setText(text);
    button->setCheckable(true);
    button->setAutoExclusive(true);

    connect(button, SIGNAL(clicked()),this,member.toStdString().c_str()); //connect button signal to SLOT(itemClicked)
    return button;
}

void Game_Screen::itemClicked() {
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());

    clickedButton->setAutoExclusive(false);
    clickedButton->setChecked(false);
    clickedButton->setAutoExclusive(true);
    // QWidget *parentWidget = clickedButton->parentWidget();
    // QGridLayout *parentLayout = qobject_cast<QGridLayout*>(parentWidget->layout());
    // int nextCellPosition = clickedButton->objectName().toInt();

    if(!client->getRoomIn4().gameStart){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                itemButtons[i][j]->setDisabled(true);
            }
        }
    }

    QJsonObject data;
    data["room name"] = client->getRoomIn4().roomName;
    data["current board"] = clickedButton->parentWidget()->layout()->objectName();
    data["current cell"] = clickedButton->objectName();
    data["player username"] = client->getUser().username;
    // client->sendRequestToServer(RequestType::MOVE, data);

    // for(int i = 0; i < 9; i++){
    //     for(int j = 0; j < 9; j++){
    //         if(i == nextCellPosition){
    //             itemButtons[i][j]->setDisabled(false);
    //         }else{
    //             itemButtons[i][j]->setDisabled(true);
    //         }
    //         itemButtons[layoutIndex][nextCellPosition]->setText("X");
    //     }
    // }
}

void Game_Screen::on_readyButton_clicked()
{
    QJsonObject data;
    data["room_name"] = client->getRoomIn4().roomName;
    data["player_username"] = client->getUser().username;

    if(readyButton->text() == "READY"){
        readyButton->setText("UNREADY");
        client->sendRequestToServer(RequestType::READY, data);
    }else if(readyButton->text() == "UNREADY"){
        readyButton->setText("READY");
        client->sendRequestToServer(RequestType::UNREADY, data);
    }else if(readyButton->text() == "START"){
        client->sendRequestToServer(RequestType::START, data);
    }
}

