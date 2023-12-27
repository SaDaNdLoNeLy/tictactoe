#include "online_list.h"
#include "ui_online_list.h"

OnlinePlayer::OnlinePlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OnlinePlayer)
{
    ui->setupUi(this);
}

OnlinePlayer::~OnlinePlayer()
{
    delete ui;
}
