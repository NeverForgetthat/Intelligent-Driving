#include "myTcpServer.h"

std::vector<QString> myTcpServer::clients;
bool myTcpServer::is0FirstMessageReceived = false;
bool myTcpServer::is1FirstMessageReceived = false;
bool myTcpServer::is2FirstMessageReceived = false;

myTcpServer::myTcpServer(QObject *parent) : QTcpServer(parent)
{
}

myTcpServer::~myTcpServer()
{
    stopServer();
}

bool myTcpServer::startServer(const QString &Address, quint16 port)
{
    QHostAddress address(Address);
    if (!isListening) {
        if (listen(address, port)) {
            qDebug() << "Server started listening on" << address.toString() << "port" << port;
            isListening = true;
            return true;
        } else {
            qDebug() << "Failed to start server listening on" << address.toString() << "port" << port;
            return false;
        }
    } else {
        qDebug() << "Server is already listening.";
        return true; // 返回 true 表示服务器已经处于监听状态
    }
}

void myTcpServer::stopServer()
{
    if (isListening) {
        close();
        qDebug() << "Server stopped.";
        isListening = false;
    } else {
        qDebug() << "Server is not currently listening.";
    }
}
bool myTcpServer::isServerRunning() const
{
    return serverRunning;
}

void myTcpServer::handleClientDisconnect()
{
    if (!clients.empty()) { // 确保向量非空
        clients.pop_back();
    }
}

void myTcpServer::incomingConnection(qintptr socketDescriptor)
{
    emit newDescriptor(socketDescriptor);
}


myTcpServerControl::myTcpServerControl(QObject *parent) : QObject(parent), socket(nullptr)
{
}

void myTcpServerControl::setSocket(qintptr socketDescriptor)
{
    QMutexLocker locker(&mutex);
    if (socket) {
        socket->disconnectFromHost();
        socket->deleteLater();
    }

    this->socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &myTcpServerControl::onReadyRead);
}


void myTcpServerControl::sendMessage(const QString &message)
{
    QMutexLocker locker(&mutex);
    if (socket)
    {
        QByteArray data;
        QDataStream out(&data, QIODevice::WriteOnly);
        out << message;
        qDebug()<<message;
        socket->write(data);
        socket->flush();
        emit messageSend(message);
    }
    else
    {
        qDebug() << "Socket未设置，无法发送信息";
    }
}

void myTcpServerControl::onReadyRead()
{
    QMutexLocker locker(&mutex);
    if (socket && socket->bytesAvailable() > 0) // 检查是否有可用数据
    {
        qDebug() << "可用数据大小:" << socket->bytesAvailable();

        QDataStream in(socket);
        QString message;
        in >> message;
        qDebug() << "读取到的消息:" << message;

        emit messageReceived(message);
    }
    else
    {
        qDebug() << "无数据";
    }
}



