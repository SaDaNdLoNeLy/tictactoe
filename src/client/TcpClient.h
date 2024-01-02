#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QtNetwork/QTcpSocket>

enum class RequestType
{
    LOGIN,
    LOGOUT,
    REGISTER,
    UPDATEDATA,
    CREATEROOM,
    JOINROOM,
    ROOMLIST,
    READY,
    UNREADY,
    STARTGAME,
    // Add more request types as needed
};

enum class RespondType
{
    LOGIN,
    LOGOUT,
    REGISTER,
    UPDATEDATA,
    CREATEROOM,
    JOINROOM,
    ROOMLIST,
    READY,
    UNREADY,
    STARTGAME,
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

struct room{
    QString roomName;
    user playerX;
    user playerO;
    bool isFull;
    bool isPlayerXTurn;
    int turn = -2;
    bool player1_ready;
    bool player2_ready;
    room() : isPlayerXTurn(true), player1_ready(false), player2_ready(false){}
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
    void setUserfromUser(user newUpdate);

    std::vector<user> getOnlineUser();
    void setOnlineUser(std::vector<user> onlineUser);

    std::vector<room> getRoomList();
    void setRoomList(std::vector<room> roomList);

    QString getRoomName();
    void setRoomName(QString room_name);

    room getRoomIn4();
    void setRoomIn4(room roomIn4);

    user findUserByUsername(const QString &username);
    room findRoomByRoomName(const QString &room_name);

signals:
    void connected();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState socketState);
    void errorOccurred(QAbstractSocket::SocketError socketError);
    void dataReady(QByteArray);
    void roomIn4Changed(const room& newRoomInfo);

private slots:
    void onReadyRead();

private:
    QTcpSocket _socket;
    QString _ip;
    QString room_name;
    int _port;
    user clientUser;
    room roomIn4;
    std::vector<user> onlineUser;
    std::vector<room> roomList;
};

#endif // TCPCLIENT_H



