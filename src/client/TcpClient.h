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
    std::vector<user> players;
    int turn;
    bool isFull;

    room(QString name) : roomName(name), isFull(false){}

    bool hasSpace() const{
        return players.size() < 2;
    }

    bool addPlayer(const user& newUser){
        if(hasSpace()){
            players.push_back(newUser);
            if(players.size() == 2){
                isFull = true;
            }
            return true;
        }
        return false;
    }
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

    user findUserByUsername(const QString &username);

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
    std::vector<room> roomList;
};

#endif // TCPCLIENT_H



