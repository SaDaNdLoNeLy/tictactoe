#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QtNetwork/QTcpSocket>

enum class RequestType
{
    LOGIN,
    LOGOUT,
    REGISTER,
    // Add more request types as needed
};

enum class RespondType
{
    LOGIN,
    LOGOUT,
    REGISTER,
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

signals:
    void connected();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState socketState);
    void errorOccurred(QAbstractSocket::SocketError socketError);
    void dataReady(QByteArray);

private slots:
    void onReadyRead();

public slots:
    void handleServerResponse(const QByteArray& responseData);

private:
    QTcpSocket _socket;
    QString _ip;
    int _port;

};

#endif // TCPCLIENT_H



