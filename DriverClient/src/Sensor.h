#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include <QString>
#include <QComboBox>
#include <QDateTime>
#include <random>
#include <chrono>
#include "Serial.h"
#include "Method.h"

//传感器基类
class SensorBase: public QObject
{
    Q_OBJECT

public:
    static std::vector<QString>itemtypes;           //类型向量
    static std::vector<QString>itemstates;          //状态向量
    enum ItemType
    {
        OilGauge, SpeedGauge, DtcGauge, WlpGauge, NumMonitor
    };                                              //油量计，速度计，车距检测，胎压传感器，车数统计
    enum ItemState
    {
        Stop, Run, Pause, Continue, Get, Status
    };                                              //停止，运行，暂停，继续，获取数据，状态

    SensorBase();
    virtual QString process(QString& pstr)=0;       //状态处理
};

//传感器对象类，继承于基类
class SensorItem: public SensorBase
{
    Q_OBJECT

public:

    int qtypeid;            //类型
    int qstateid;           //状态
    float val;              //模拟数据的数值
    QString qrsp;			//最近响应

    SensorItem();                                       //构造函数初始化枚举索引
    static QString getitemtype(int n);                  //根据传感器类型的枚举值获取类型名称
    static QString getitemstate(int sta);               //根据传感器状态的枚举值获取状态名称
    QString getitemstate();                             //获取当前传感器对象状态的字符串
    QString getitemtype();                              //获取当前传感器对象的类型名称
    float getdata();                                    //获取模拟的传感器数据
    int str2stateid(const QString& pstr);               //字符串转枚举值
    virtual QString process(QString& pstr);             //处理传感器状态的函数，返回响应字符串
    static float range(float x, float y);               //生成随机数

signals:
    void ValChanged(const float newval);
};


#endif // SENSOR_H
