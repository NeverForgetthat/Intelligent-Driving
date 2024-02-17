#ifndef SERIAL_H
#define SERIAL_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <vector>
#include <QDebug>
#include <QMutex>
#include "Method.h"


class MySerialPort: public QObject
{
    Q_OBJECT

public:
        QString cmbPortName;
        QString cmbBaudRate;
        int cmbDataBits;
        int cmbParity;
        int cmbFlowControl;
        int cmbStopBits = false;
        QSerialPort *mySerialPort;

        explicit MySerialPort();
        ~MySerialPort();
        void SensorSerialConnect();
        void CarSerialConnect();
        void SerialDisconnect();
        void setcmbPortName(QString PortName);
        void setcmbBaudRate(QString BaudRate);
        void setcmbDataBits(int DataBits);
        void setcmbParity(int Parity);
        void setcmbFlowControl(int FlowControl);
        void setcmbStopBits(int StopBits);
        QByteArray myreadAll();
        void mywrite(QByteArray SendData);
        bool isSerialPortConnected();

};

class SerialControl: public QObject
{
    Q_OBJECT

public:
    MySerialPort* curserial;                            //创建当前串口对象指针
    QByteArray buffer;                                  //创建一个缓冲区
    MySerialPort* carserial;                            //车串口
    MySerialPort* sensorserial;                         //传感器串口
    QMutex mutex;                                       //创建一个互斥锁

    explicit SerialControl();
    void ChooseSerial(MySerialPort* serial);
    void CarSerialInit(int checkid, int portid);
    void SensorSerialInit(int checkid, int portid);
    void HandleWrite(QString& msg);
    QString HandleBuffer();

signals:
    void dataReceived(const QString& data);             //用于向主线程传递响应字符串
    void stopThread();                                  //停止工作信号

public slots:
    void HandleReadyRead();

};

#endif // SERIAL_H
