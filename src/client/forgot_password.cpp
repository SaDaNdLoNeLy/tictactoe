#include "forgot_password.h"
#include "ui_forgot_password.h"

forgot_password::forgot_password(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::forgot_password)
{
    ui->setupUi(this);
}

forgot_password::~forgot_password()
{
    delete ui;
}
