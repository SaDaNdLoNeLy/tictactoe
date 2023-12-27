#ifndef ONLINE_LIST_H
#define ONLINE_LIST_H

#include <QWidget>

namespace Ui {
class OnlinePlayer;
}

class OnlinePlayer : public QWidget
{
    Q_OBJECT

public:
    explicit OnlinePlayer(QWidget *parent = nullptr);
    ~OnlinePlayer();

private:
    Ui::OnlinePlayer *ui;
};

#endif // ONLINE_LIST_H
