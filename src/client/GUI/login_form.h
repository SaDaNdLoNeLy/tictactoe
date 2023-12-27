#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include "register_form.h"
#include "forgot_password.h"


namespace Ui {
class loginform;
}

class loginform : public QWidget
{
    Q_OBJECT

public:
    explicit loginform(QWidget *parent = nullptr);
    ~loginform();

signals:
    void backButtonClicked();

private slots:
    void on_forgot_clicked();

    void on_Register_clicked();

    void on_Back_btn_clicked();

    void on_show_password_clicked();

    void on_login_btn_clicked();

private:
    Ui::loginform *ui;
    registerform *res_form;
    forgot_password *forgot_form;
    QLineEdit *password;
    QPushButton *show_pass_btn;

};

#endif // LOGIN_FORM_H
