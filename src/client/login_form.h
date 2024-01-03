#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QTimer>
#include "register_form.h"
#include "forgot_password.h"
#include "TcpClient.h"


namespace Ui {
class loginform;
}

class loginform : public QWidget
{
    Q_OBJECT

public:
    explicit loginform(QWidget *parent = nullptr);
    ~loginform();

    void setTcpClient(TcpClient *client);
    TcpClient* getTcpClient();

signals:
    void backButtonClicked();

private slots:
    void on_forgot_clicked();

    void on_Register_clicked();

    void on_Back_btn_clicked();

    void on_show_password_clicked();

    void on_login_btn_clicked();

    void handleServerResponse(const QByteArray& responseData);


private:
    Ui::loginform *ui;
    registerform *res_form;
    forgot_password *forgot_form;

    QLineEdit *username_input;
    QLineEdit *password_input;

    QLabel *warning_username;
    QLabel *warning_password;

    QPushButton *show_pass_btn;

    TcpClient *tcpClient;

};

#endif // LOGIN_FORM_H
