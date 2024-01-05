#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QFrame>
#include <QLabel>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "TcpClient.h"
#include "move.h"

namespace Ui {
class Game_Screen;
}

class Game_Screen : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game_Screen(QWidget *parent = nullptr);
    ~Game_Screen();

    void setUpGrid();
    void setUpRandomFrame();

    void setClient(TcpClient *client);


public slots:
    void itemClicked();
    // void randomButtonClicked();
    void handleServerResponse(const QByteArray& responseData);
    void handleRoomIn4Changed(const room& newRoom);

private slots:
    void on_readyButton_clicked();

    void on_exit_clicked();

    void on_yes_clicked();

    void on_no_clicked();

private:
    Ui::Game_Screen *ui;

    QPushButton *createButton(QString&, const QString/*const char**/);
    QPushButton *randomButton[10];
    QPushButton *itemButtons[9][9];
    QPushButton *readyButton;
    QGridLayout *layouts[9];
    QGridLayout *randomLayout;
    QFrame *frames[9];
    QFrame *surfr;
    QLabel *player1_name;
    QLabel *player2_name;
    QLabel *player1_elo;
    QLabel *player2_elo;
    QLabel *player1_win;
    QLabel *player2_win;
    QLabel *noti;

    room *client_room;
    TcpClient *client;


};

#endif // GAME_SCREEN_H
