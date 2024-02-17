#include "Serial.h"


MySerialPort::MySerialPort()
{
    mySerialPort = new QSerialPort;
}

MySerialPort::~MySerialPort()
{
    delete mySerialPort;
}

void MySerialPort::SensorSerialConnect()
{
    if(mySerialPort->open(QIODevice::WriteOnly))
        {
            mySerialPort->setBaudRate(cmbBaudRate.toInt());
            mySerialPort->setDataBits(QSerialPort::Data8);
            mySerialPort->setParity(QSerialPort::NoParity);
            mySerialPort->setFlowControl(QSerialPort::NoFlowControl);
            mySerialPort->setStopBits(QSerialPort::OneStop);
            qDebug()<<"串口打开成功";
        }
    else
       {
           qDebug()<<"串口打开失败";
           mySerialPort->close();
       }
}

void MySerialPort::CarSerialConnect()
{
    if(mySerialPort->open(QIODevice::ReadOnly))
        {
            mySerialPort->setBaudRate(cmbBaudRate.toInt());
            mySerialPort->setDataBits(QSerialPort::Data8);
            mySerialPort->setParity(QSerialPort::NoParity);
            mySerialPort->setFlowControl(QSerialPort::NoFlowControl);
            mySerialPort->setStopBits(QSerialPort::OneStop);
            qDebug()<<"串口打开成功";
        }
    else
       {
           qDebug()<<"串口打开失败";
           mySerialPort->close();
       }
}

void MySerialPort::SerialDisconnect()
{
    mySerialPort->close();
}

void MySerialPort::setcmbPortName(QString PortName)
{
    cmbPortName=PortName;
    mySerialPort->setPortName(PortName);
}

void MySerialPort::setcmbBaudRate(QString BaudRate)
{
    cmbBaudRate=BaudRate;
}

void MySerialPort::setcmbDataBits(int DataBits)
{
    cmbDataBits=DataBits;
}

void MySerialPort::setcmbParity(int Parity)
{
    cmbParity=Parity;
}

void MySerialPort::setcmbFlowControl(int FlowControl)
{
    cmbFlowControl=FlowControl;
}

void MySerialPort::setcmbStopBits(int StopBits)
{
    cmbStopBits=StopBits;
}

QByteArray MySerialPort::myreadAll()
{
    QByteArray readComData = mySerialPort->readAll();
    return readComData;
}

void MySerialPort::mywrite(QByteArray SendData)
{
    mySerialPort->write(SendData);
}

bool MySerialPort::isSerialPortConnected()
{
    return mySerialPort->isOpen();
}


SerialControl::SerialControl()
{
    this->curserial = new MySerialPort;
    connect(this->curserial->mySerialPort, &QSerialPort::readyRead, this, &SerialControl::HandleReadyRead);
}

void SerialControl::ChooseSerial(MySerialPort *serial)
{
    this->curserial = serial;
}

void SerialControl::CarSerialInit(int checkid, int portid)
{
    switch (checkid)
    {
    case 0:
        this->curserial->cmbParity = 0;
        break;
    case 1:
        this->curserial->cmbParity = 1;
        break;
    case 2:
        this->curserial->cmbParity = 2;
        break;
    default:
        break;
    }
    switch (portid)
    {
    case 0:
        this->curserial->cmbBaudRate = "3200";
        break;
    case 1:
        this->curserial->cmbBaudRate = "6400";
        break;
    case 2:
        this->curserial->cmbBaudRate = "9600";
        break;
    case 3:
        this->curserial->cmbBaudRate = "19200";
        break;
    default:
        break;
    }
    this->curserial->CarSerialConnect();
    if(curserial->isSerialPortConnected())
    {
        qDebug()<<"串口成功连接";
    }
    else
    {
        qDebug()<<"串口未能成功连接";
    }
}

void SerialControl::SensorSerialInit(int checkid, int portid)
{
    switch (checkid)
    {
    case 0:
        this->curserial->cmbParity = 0;
        break;
    case 1:
        this->curserial->cmbParity = 1;
        break;
    case 2:
        this->curserial->cmbParity = 2;
        break;
    default:
        break;
    }
    switch (portid)
    {
    case 0:
        this->curserial->cmbBaudRate = "3200";
        break;
    case 1:
        this->curserial->cmbBaudRate = "6400";
        break;
    case 2:
        this->curserial->cmbBaudRate = "9600";
        break;
    case 3:
        this->curserial->cmbBaudRate = "19200";
        break;
    default:
        break;
    }
    this->curserial->SensorSerialConnect();
    if(curserial->isSerialPortConnected())
    {
        qDebug()<<"串口成功连接";
    }
    else
    {
        qDebug()<<"串口未能成功连接";
    }
}

void SerialControl::HandleWrite(QString &str)
{
    QMutexLocker locker(&mutex);
    QByteArray msg = str.toUtf8();
    this->curserial->mywrite(msg);
}

QString SerialControl::HandleBuffer()
{
    QMutexLocker locker(&mutex);
    QString data(buffer);
    QString data1 = Convert::Tab2Comma(data);
    buffer.clear();
    return data1;
}

void SerialControl::HandleReadyRead()
{
    QMutexLocker locker(&mutex);
    //读取接收到的数据
    QByteArray data = curserial->myreadAll();
    //将读取到的数据放入缓冲区
    this->buffer.append(data);
    emit dataReceived(QString::fromUtf8(data));
}


