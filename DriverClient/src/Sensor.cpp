#include "Sensor.h"

std::vector<QString>SensorBase::itemtypes = {"OilGauge", "SpeedGauge", "DtcGauge", "WlpGauge", "NumMonitor"};
std::vector<QString>SensorBase::itemstates = {"Stop", "Run", "Pause", "Continue", "Get", "Status"};

//传感器基类
SensorBase::SensorBase()
{

}

//传感器对象类
SensorItem::SensorItem()
{
    qtypeid = 0;
    qstateid = 0;
}

QString SensorItem::getitemtype(int id)
{
    QString typ = QString("其他类型");
    if (id >= 0 && id < int(itemtypes.size()))
    {
        typ = itemtypes[id];
    }
    return typ;
}

QString SensorItem:: getitemstate(int id)
{
    QString sta = QString("其他状态");
    if (id >= 0 && id < int(itemstates.size()))
    {
        sta = itemstates[id];
    }
    return sta;
}

QString SensorItem::getitemstate()
{
    return getitemstate(qstateid);
}

QString SensorItem::getitemtype()
{
    return getitemtype(qtypeid);
}

int SensorItem::str2stateid(const QString& qstr)
{
    int id = -1;
    for (int i = 0; i < int(itemstates.size()); i++)
    {
        if (itemstates[i] == qstr)
        {
            return i;
        }
    }
    return id;
}

float SensorItem::range(float v0, float v1)
{
    qsrand(QDateTime::currentMSecsSinceEpoch());  // 使用QT随机数生成器
    if (v0 > v1)
    {
        qSwap(v0, v1);  // 使用QT交换函数，确保v0 <= v1
    }
    int cv;
    float dv = v1 - v0;
    float AC = 0.01;
    int n = dv / AC + 1;
    if (n > 0)
    {
        cv = qrand() % n;
        v0 += cv * AC;
    }
    return v0;
}

float SensorItem::getdata()
{
    qsrand(QTime::currentTime().msec());        //初始化随机数种子
    int ratio = qrand() % 101;
    switch (qtypeid)
    {
        case OilGauge:
        if (ratio >= 0 && ratio < 40)
            {
                val = range(35, 65);
            }
            else if (ratio >= 40 && ratio < 55)
            {
                val = range(15, 35);
            }
            else if (ratio >= 55 && ratio < 70)
            {
                val = range(65, 85);
            }
            else if (ratio >= 70 && ratio < 85)
            {
                val = range(85, 100);
            }
            else if (ratio >= 85 && ratio < 95)
            {
                val = range(0, 15);
            }
            else
            {
                val = range(0, 15);
            }
            break;
        case SpeedGauge:
            if (ratio >= 0 && ratio < 40)
                {
                    val = range(0, 60);
                }
                else if (ratio >= 40 && ratio < 60)
                {
                    val = range(60, 80);
                }
                else if (ratio >= 60 && ratio <= 80)
                {
                    val = range(80, 100);
                }
                else if (ratio >= 80 && ratio <= 95)
                {
                    val = range(100, 150);
                }
                else if (ratio >= 95)
                {
                    val = range(150, 250);
                }
                break;
        case DtcGauge:
            if (ratio >= 20 && ratio < 80)
            {
                val = range(25, 50);
            }
            else if (ratio >= 80 && ratio < 95)
            {
                val = range(5, 25);
            }
            else if (ratio >= 5 && ratio < 20)
            {
                val = range(50, 200);
            }
            else if (ratio >= 0 && ratio < 5)
            {
                val = range(200, 500);
            }
            else if (ratio >= 95 && ratio < 100)
            {
                val = range(0, 5);
            }
            break;
        case WlpGauge:
            if (ratio >= 20 && ratio < 80)
            {
                val = range(0.2, 0.3);
            }
            else if (ratio >= 80 && ratio < 95)
            {
                val = range(0.15, 0.2);
            }
            else if (ratio >= 5 && ratio < 20)
            {
                val = range(0.3, 0.35);
            }
                break;
        case NumMonitor:
            val = range(5, 150);
            val = (int)val;
            break;
    }
    emit ValChanged(val);
    return val;
}

QString SensorItem::process(QString& qstr)
{
    QString state = getitemstate();
    bool succ = false;
    int qid = str2stateid(qstr);

    switch (qid)
    {
        case Stop:
            if (qstateid == Run || qstateid == Pause)
            {
                qstateid = Stop;
                succ = true;
            }
            break;
        case Run:
            if (qstateid == Stop)
            {
                qstateid = Run;
                succ = true;
            }
            break;
        case Pause:
            if (qstateid == Run)
            {
                qstateid = Pause;
                succ = true;
            }
            break;
        case Continue:
            if (qstateid == Pause)
            {
                qstateid = Run;
                succ = true;
            }
            break;
        case Get:
            if (qstateid == Run)
            {
                val = getdata();
                succ = true;
            }
            break;
        case Status:
            succ = true;
            break;
        default:
            break;
    }
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    QString rsp;
    switch (qtypeid)
    {
    case 0:
        rsp = QString("%1\t%2%3\t%4").arg("油量").arg(val*0.6).arg("升").arg(currentDateTimeString);
        break;
    case 1:
        rsp = QString("%1\t%2%3\t%4").arg("速度").arg(val).arg("km/h").arg(currentDateTimeString);
        break;
    case 2:
        rsp = QString("%1\t%2%3\t%4").arg("车距").arg(val).arg("m").arg(currentDateTimeString);
        break;
    case 3:
        rsp = QString("%1\t%2%3\t%4").arg("胎压").arg(val).arg("MPa").arg(currentDateTimeString);
        break;
    case 4:
        rsp = QString("%1\t%2%3\t%4").arg("车流量").arg(val).arg("辆").arg(currentDateTimeString);
        break;
    }
    qrsp = QString("%1 %2 -> %3").arg(getitemstate(qid)).arg(state).arg(getitemstate());
    if (succ)
    {
        qrsp += " 成功";
    }
    else
    {
        qrsp += " 无效";
    }

    return rsp;
}
