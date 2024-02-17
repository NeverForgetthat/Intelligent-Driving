// tcpclient.h
#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QDataStream>
#include <QDateTime>

class TcpClient : public QObject
{
    Q_OBJECT
public:
    QString UserName;

    explicit TcpClient(QObject *parent = nullptr);

    void connectToServer(const QString &host, quint16 port);
    void disconnectFromServer();
    void sendMessage(const QString &message);
    bool isConnected() const;

signals:
    void connected();
    void disconnected();
    void error(QAbstractSocket::SocketError socketError);
    void messageReceived(const QString &message);
    void StateboolChanged();

private slots:
    void onConnected();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);
    void onReadyRead();

private:
    QTcpSocket *socket;
    bool isconnected;
};

#endif // TCPCLIENT_H

