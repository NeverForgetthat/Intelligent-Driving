#include "TcpClient.h"

TcpClient::TcpClient(QObject *parent) : QObject(parent), socket(new QTcpSocket(this))
{
    connect(socket, &QTcpSocket::connected, this, &TcpClient::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &TcpClient::onDisconnected);
    connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, &TcpClient::onError);
    connect(socket, &QTcpSocket::readyRead, this, &TcpClient::onReadyRead);
}

void TcpClient::connectToServer(const QString &host, quint16 port)
{
    socket->connectToHost(host, port);
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    QString rsp = UserName + " -> 已连接";
    this->sendMessage(rsp);
    emit StateboolChanged();
}

void TcpClient::disconnectFromServer()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    QString rsp = QString("%1: %2<<   %3    \t\t%4").arg("用户").arg(UserName).arg("已断开").arg(currentDateTimeString);
    this->sendMessage(rsp);
    socket->disconnectFromHost();
    emit StateboolChanged();
}

void TcpClient::sendMessage(const QString &message)
{
    if (socket->state() == QAbstractSocket::ConnectedState)
    {
        QByteArray data;
        QDataStream out(&data, QIODevice::WriteOnly);
        out << message; // 编码消息为字节流
        socket->write(data);
        socket->flush();
    }
}

bool TcpClient::isConnected() const
{
    return isconnected;
}

void TcpClient::onConnected()
{
    isconnected = true;
    emit connected();
}

void TcpClient::onDisconnected()
{
    isconnected = false;
    emit disconnected();
}

void TcpClient::onError(QAbstractSocket::SocketError socketError)
{
    emit error(socketError);
}

void TcpClient::onReadyRead()
{
    QByteArray data = socket->readAll();
    QDataStream in(&data, QIODevice::ReadOnly); // 创建 QDataStream 对象并关联数据
    QString message;
    in >> message; // 从字节流中读取消息
    emit messageReceived(message);
}

