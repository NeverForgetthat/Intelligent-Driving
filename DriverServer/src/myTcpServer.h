#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QDebug>
#include <vector>
#include <QMutex>

class myTcpServer: public QTcpServer
{
    Q_OBJECT

public:
    static std::vector<QString> clients;

    explicit myTcpServer(QObject *parent = nullptr);
    ~myTcpServer();
    static bool is0FirstMessageReceived;       //判断是否是第一条消息
    static bool is1FirstMessageReceived;       //判断是否是第一条消息
    static bool is2FirstMessageReceived;       //判断是否是第一条消息

    bool startServer(const QString &ipAddress, quint16 port);   //启动服务
    void stopServer();                                          //停止服务
    bool isServerRunning() const;                               //判断服务状态

public slots:
    void handleClientDisconnect();

signals:
    void newDescriptor(qintptr socketDescriptor);
    void dataReceived(const QString &data);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    bool serverRunning = false;
    bool isListening = false;
};

class myTcpServerControl : public QObject
{
    Q_OBJECT
public:
    QTcpSocket *socket;
    QMutex mutex;                                       //创建一个互斥锁

    explicit myTcpServerControl(QObject *parent = nullptr);
    void setSocket(qintptr socketDescriptor);
    void sendMessage(const QString &message);

private slots:
    void onReadyRead();

signals:
    void messageReceived(const QString &message);
    void messageSend(const QString &message);
};
#endif // MYTCPSERVER_H
