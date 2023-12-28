#include "TcpClient.h"
#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>

TcpClient::TcpClient() {
    connect(&_socket, &QTcpSocket::connected, this, &TcpClient::connected);
    connect(&_socket, &QTcpSocket::disconnected, this, &TcpClient::disconnected);
    connect(&_socket, &QTcpSocket::errorOccurred, this, &TcpClient::errorOccurred);
    connect(&_socket, &QTcpSocket::stateChanged, this, &TcpClient::stateChanged);
    connect(&_socket, &QTcpSocket::readyRead, this, &TcpClient::onReadyRead);
}

void TcpClient::connectToDevice(QString ip_address, int port){
    _ip = ip_address;
    _port = port;
    _socket.connectToHost(_ip, _port);
    std::cout << "connected to device" << std::endl;
}

void TcpClient::disconnectFromDevice(){
    _socket.disconnectFromHost();
}


QTcpSocket& TcpClient::getSocket(){
    return _socket;
}

void TcpClient::onReadyRead(){
    auto data = _socket.readAll();
    emit dataReady(data);
}

QByteArray TcpClient::getServerResponse(){
    if (_socket.bytesAvailable() > 0) {
        return _socket.readAll();
    }
    return QByteArray();
}

void TcpClient::sendRequestToServer(RequestType type, QJsonObject data){
    QJsonObject request;
    request["type"] = static_cast<int>(type);
    request["data"] = data;

    QJsonDocument doc(request);
    QByteArray jsonData = doc.toJson();

    _socket.write(jsonData);
}
