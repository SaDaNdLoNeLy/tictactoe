#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QtNetwork/QTcpSocket>

enum class RequestType
{
    LOGIN,
    LOGOUT,
    REGISTER,
    ONLINEPLAYER,
    // Add more request types as needed
};

enum class RespondType
{
    LOGIN,
    LOGOUT,
    REGISTER,
    ONLINEPLAYER,
};

struct user{
    QString username;
    QString status;
    int wins;
    int loses;
    int elo;
    bool isFree;
    double winRate;
};

class TcpClient : public QObject
{
    Q_OBJECT
public:
    TcpClient();
    void connectToDevice(QString ip_address, int port);
    void disconnectFromDevice();
    void sendRequestToServer(RequestType type, QJsonObject data);
    QByteArray getServerResponse();

    QTcpSocket& getSocket();

    user getUser();
    void setUser(QString username, QString status, int wins, int loses, bool isFree, double winRate, int elo);

    std::vector<user> getOnlineUser();
    void setOnlineUser(std::vector<user> onlineUser);

signals:
    void connected();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState socketState);
    void errorOccurred(QAbstractSocket::SocketError socketError);
    void dataReady(QByteArray);

private slots:
    void onReadyRead();

private:
    QTcpSocket _socket;
    QString _ip;
    int _port;
    user clientUser;
    std::vector<user> onlineUser;
};

#endif // TCPCLIENT_H



