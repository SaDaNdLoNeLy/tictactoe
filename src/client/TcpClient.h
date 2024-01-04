#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QtNetwork/QTcpSocket>

enum class RequestType
{
    LOGIN,
    LOGOUT,
    UPDATEONLINEUSER,
    GETONLINEUSER,
    GETROOMLIST,
    UPDATEROOMLIST,
    CREATEROOM,
    JOINROOM,
    READY,
    UNREADY,
    START
    // Add more request types as needed
};

enum class ResponseType
{
    LOGIN,
    LOGOUT,
    UPDATEONLINEUSER,
    GETONLINEUSER,
    GETROOMLIST,
    UPDATEROOMLIST,
    CREATEROOM,
    JOINROOM,
    READY,
    UNREADY,
    START,
};

struct user{
    QString username;
    QString status;
    QString ingame;
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
    bool gameStart;
    bool player1_ready;
    bool player2_ready;
    int turn = -2;
    int nextBoard;
    room() : isFull(false), isPlayerXTurn(true), player1_ready(false), player2_ready(false), gameStart(false), turn(-2), nextBoard(-1){}
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
    void setUser(QString username, QString status, int wins, int loses, bool isFree, double winRate, int elo, QString ingame);
    void setUserfromUser(user &newUpdate);

    std::vector<user> getOnlineUser();
    void setOnlineUser(std::vector<user> &onlineUser);

    std::vector<room> getRoomList();
    void setRoomList(std::vector<room> &roomList);

    QString getRoomName();
    void setRoomName(QString room_name);

    room getRoomIn4();
    void setRoomIn4(room &roomIn4);

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
    void onDisconnected();

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



