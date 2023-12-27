// #ifndef TCPCLIENT_H
// #define TCPCLIENT_H
// #define SERVER_ADDRESS "127.0.0.1"
// #define SERVER_PORT    9000

// #include <QJsonArray>
// #include <QtNetwork/QTcpSocket>
// #include <iostream>
// #include "nlohmann/json.hpp"

// using json = nlohmann::json;


// enum class RequestType
// {
//     Login,
//     Logout,
//     MatchMaking,
//     Challenge,
//     Move,
//     GetOnlinePlayersList,
//     SomeOtherRequest,
//     // Add more request types as needed
// };

// enum class RespondType
// {
//     Login,
//     Logout,
//     MatchMaking,
//     Move, // Working ... needs implementing
//     Challenge,
//     GameResult, // Working ... needs implementing
//     OnlinePlayersList,
// };


// class TcpClient
// {
// public:
//     TcpClient();
//     bool connect();
//     // bool disconnect();
//     bool sendMsg(const std::string& message);
//     bool sendRequest(RequestType type, const json& requestData);
//     bool receive(std::string& receivedData);

// private:
//     QTcpSocket socket;
//     std::string serverAddress;
//     unsigned short serverPort;

// };

// #endif // TCPCLIENT_H
