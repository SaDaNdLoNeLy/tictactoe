#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QFrame>
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

public slots:
    void itemClicked();
    void randomButtonClicked();

private:
    Ui::Game_Screen *ui;

    QPushButton *itemButtons[9][9];
    QGridLayout *layouts[9];
    QGridLayout *randomLayout;
    QFrame *frames[9];
    QPushButton *randomButton[10];

    QPushButton *createButton(QString&, const QString/*const char**/);


};

#endif // GAME_SCREEN_H
