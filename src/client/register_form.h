#ifndef REGISTER_FORM_H
#define REGISTER_FORM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include "TcpClient.h"


namespace Ui {
class registerform;
}

class registerform : public QWidget
{
    Q_OBJECT

public:
    explicit registerform(QWidget *parent = nullptr);
    ~registerform();

    void setTcpClient(TcpClient *client);
    TcpClient& getTcpClient();

signals:
    void backButtonClicked();
    void loginButtonClicked();

private slots:

    void on_show_password_clicked();

    void on_register_btn_clicked();

    void on_Login_clicked();

    void on_show_confirm_password_clicked();

    void on_Back_btn_clicked();

    void handleServerResponse(const QByteArray& responseData);

private:
    Ui::registerform *ui;
    QPushButton *show_btn;
    TcpClient *client;
};

#endif // REGISTER_FORM_H
