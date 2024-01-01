#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login_form.h"
#include "TcpClient.h"
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    TcpClient& getTcpClient();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_playoffline_clicked();


private:
    Ui::MainWindow *ui;
    // loginform *login;
    TcpClient client;
};
#endif // MAINWINDOW_H
