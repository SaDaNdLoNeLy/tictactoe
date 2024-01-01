#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QFrame>
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
    void randomButtonClicked();
    void handleServerResponse(const QByteArray& responseData);

private:
    Ui::Game_Screen *ui;

    QPushButton *itemButtons[9][9];
    QGridLayout *layouts[9];
    QGridLayout *randomLayout;
    QFrame *frames[9];
    QPushButton *randomButton[10];
    room *client_room;

    QPushButton *createButton(QString&, const QString/*const char**/);

    TcpClient *client;


};

#endif // GAME_SCREEN_H
