#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMediaPlayer>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QThread>
#include <QDateTime>
#include <QFileDialog>
#include "UserSee.h"
#include "Search.h"
#include "myTcpServer.h"
#include "method.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QMediaPlayer *player;               //视频播放器
    QVideoWidget* videoWidget;          //视频播放窗口
    QPixmap link;                       //连接图片
    QPixmap unlink;                     //未连接图片
    myTcpServer* TcpServer;             //服务器指针
    QString IP;                         //ip
    QString port;                       //端口
    bool state = false;                 //判断服务是否开启标志0关1开
    myTcpServerControl* test;           //用于主线程中的测试控制类
    myTcpServerControl* myClientWorker[3];      //三个工人
    QThread* myClientWork[3];                   //三个工位
signals:
    void StateboolChanged();                    //服务器状态改变
    void WakeUp0(qintptr newDescriptor);        //闹钟1
    void WakeUp1(qintptr newDescriptor);        //闹钟2
    void WakeUp2(qintptr newDescriptor);        //闹钟3

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
