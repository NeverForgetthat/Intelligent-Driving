#include "Search.h"
#include "ui_Search.h"

std::vector<QString> Search::handleVEC;

Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);

    //初始化界面标题
    setWindowTitle("数据查询");

    //传感器下拉框初始化
    ui->SensorcomboBox->addItem("OilGauge");
    ui->SensorcomboBox->addItem("SpeedGauge");
    ui->SensorcomboBox->addItem("DtcGauge");
    ui->SensorcomboBox->addItem("WlpGauge");
    ui->SensorcomboBox->addItem("NumMonitor");
    ui->SensorcomboBox->setCurrentIndex(-1);

    //信号槽连接部分
    //通过索引获取传感器类型
    connect(ui->SearchButton, &QPushButton::clicked, [this]
    {
        switch (ui->SensorcomboBox->currentIndex())
        {
        case 0:
            this->sensortype = "油量";
            break;
        case 1:
            this->sensortype = "速度";
            break;
        case 2:
            this->sensortype = "车距";
            break;
        case 3:
            this->sensortype = "胎压";
            break;
        case 4:
            this->sensortype = "车流量";
            break;
        }
        this->begintime = ui->BeginTimeEdit->dateTime();
        this->endtime = ui->EndTimeEdit->dateTime();
    });

    //实现查询
    connect(ui->SearchButton, &QPushButton::clicked, [this]
    {
        ui->DataViewEdit->clear();
        if(handleVEC.size()>=3)
        {
        qDebug()<<handleVEC[0]<<handleVEC[1]<<handleVEC[2]<<handleVEC[3];
        qDebug()<<QDateTime::fromString(this->handleVEC[2], "yyyy-MM-dd hh:mm:ss");
        for (int i=0; i<int(this->handleVEC.size()); i+= 3)
        {
            if (this->handleVEC[i] == this->sensortype &&
                QDateTime::fromString(this->handleVEC[i+2], "yyyy-MM-dd hh:mm:ss") >= this->begintime &&
                QDateTime::fromString(this->handleVEC[i+2], "yyyy-MM-dd hh:mm:ss") <= this->endtime)
            {
                QString data = QString("%1\t%2\t%3").arg(this->handleVEC[i]).arg(this->handleVEC[i+1]).arg(this->handleVEC[i+2]);
                ui->DataViewEdit->append(data);
            }
            else if(this->handleVEC[i] == this->sensortype &&
                    QDateTime::fromString(this->handleVEC[i+2], "yyyy/M/dd h:mm") >= this->begintime &&
                    QDateTime::fromString(this->handleVEC[i+2], "yyyy/M/dd h:mm") <= this->endtime)
                {
                    QString data = QString("%1\t%2\t%3").arg(this->handleVEC[i]).arg(this->handleVEC[i+1]).arg(this->handleVEC[i+2]);
                    ui->DataViewEdit->append(data);
                }
        }
        }
        else
        {
            QMessageBox::information(nullptr, "警告", "无数据");
        }
        if (ui->DataViewEdit->toPlainText().isEmpty())
        {
            QMessageBox::information(nullptr, "提醒", "未找到数据");
        }
    });
}

Search::~Search()
{
    delete ui;
}
