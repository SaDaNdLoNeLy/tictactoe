#ifndef REGISTER_FORM_H
#define REGISTER_FORM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class registerform;
}

class registerform : public QWidget
{
    Q_OBJECT

public:
    explicit registerform(QWidget *parent = nullptr);
    ~registerform();

signals:
    void backButtonClicked();
    void loginButtonClicked();

private slots:

    void on_show_password_clicked();

    void on_register_btn_clicked();

    void on_Login_clicked();

    void on_show_confirm_password_clicked();

    void on_Back_btn_clicked();

private:
    Ui::registerform *ui;
    QPushButton *show_btn;

};

#endif // REGISTER_FORM_H
