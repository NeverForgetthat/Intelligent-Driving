#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QTimer>
#include <QThread>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDesktopServices>
#include <QMessageBox>
#include "Circulardashboardwidget.h"
#include "Search.h"
#include "Sensor.h"
#include "Serial.h"
#include "TcpClient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void StateboolChanged();

private:
    Ui::Widget *ui;
    CircularDashboardWidget *dashboardWidget;       //速度盘控件
    QPixmap link;                                   //连接图片
    QPixmap unlink;                                 //未连接图片
    Search* search;                                 //查询窗口
    SensorItem* sensor[8];                          //传感器
    QString username = "MyCar1";                    //用户名
    SerialControl* manager;                         //操作方法
    QThread* work[8];                               //创建8个线程对象
    SerialControl* worker[8];                       //8个传感器，8个线程，8个工作类
    QTimer* DataRefreshTimer;                       //传感器刷新数据定时器
    QTimer* DataHandleTimer;                        //数据处理定时器
    QTimer* NetWriteTimer;                          //向服务器发送数据
    QTimer* NetReadTimer;                           //从服务器读取数据
    Convert* tool;                                  //工具库
    std::vector<QString> DataCool;                  //创建数据库
    TcpClient* tcpclient;                           //tcp客户端
};
#endif // WIDGET_H
