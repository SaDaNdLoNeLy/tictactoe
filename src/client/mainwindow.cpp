#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./login_form.h"
#include "game_screen.h"
#include "TcpClient.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // login = new loginform();

    qDebug() << "Main window client: " << &client << "\n";
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    loginform *login = new loginform();
    login->setTcpClient(&client);
    client.connectToDevice("127.0.0.1", 3000);
    login->show();
    this->close();
}


void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}


void MainWindow::on_playoffline_clicked()
{
    Game_Screen *game_test = new Game_Screen();
    game_test->show();
}

