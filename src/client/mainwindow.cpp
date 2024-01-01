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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    loginform *login = new loginform();
    client.connectToDevice("192.168.1.6", 3000);
    login->setTcpClient(&client); // Truyền đối tượng TcpClient vào loginform
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

TcpClient& MainWindow::getTcpClient(){
    return client;
}
