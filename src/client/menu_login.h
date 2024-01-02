#ifndef MENU_LOGIN_H
#define MENU_LOGIN_H

#include <QWidget>
#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "TcpClient.h"
#include <QTimer>
#include "game_screen.h"

namespace Ui {
class mainmenulogin;
}

class mainmenulogin : public QWidget
{
    Q_OBJECT

public:
    explicit mainmenulogin(QWidget *parent = nullptr);
    ~mainmenulogin();

    void setClient(TcpClient *client);
    void getClient();

private slots:
    void on_logout_clicked();

    void on_CreateRoom_clicked();

    void on_cancel_clicked();

    void on_create_clicked();

    void on_JoinRoom_clicked();

    void on_cancel_3_clicked();

    void on_join_clicked();

    void handleServerResponse(const QByteArray& responseData);

private:
    Ui::mainmenulogin *ui;
    QFrame *createRoom;
    QFrame *joinRoom;
    QLineEdit *createRoomInput;
    QLineEdit *joinRoomInput;
    QLabel *warning_create;
    QLabel *warning_join;
    QTimer *timer;

    TcpClient *client;

};

#endif // MENU_LOGIN_H
