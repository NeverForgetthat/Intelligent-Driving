#include "Search.h"
#include "ui_Search.h"

std::vector<QString>Search::datacool;

Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);

    //图形界面初始化
    //初始化窗口标题
    setWindowTitle("数据查询");

    //初始化用户名框
    ui->UserNameEdit->setText("MyCar1");

    //传感器下拉框初始化
    ui->SensorcomboBox->addItem("速度");
    ui->SensorcomboBox->addItem("车距");
    ui->SensorcomboBox->setCurrentIndex(-1);

    //查询实现
    connect(ui->SearchButton, &QPushButton::clicked, [this]
    {
        QString username = ui->UserNameEdit->text();
        QString sensortype = ui->SensorcomboBox->currentText();
        QDateTime begintime = ui->BeginTimeEdit->dateTime();
        QDateTime endtime = ui->EndTimeEdit->dateTime();

        ui->CarDatatextEdit->clear();
        if(datacool.size()>=4)
        {
        qDebug()<<datacool[0]<<datacool[1]<<datacool[2]<<datacool[3];
        qDebug()<<QDateTime::fromString(this->datacool[2], "yyyy-MM-dd hh:mm:ss");
        for (int i=0; i<int(this->datacool.size()); i+= 4)
        {
            if (this->datacool[i] == username &&
                this->datacool[i+1] == sensortype &&
                QDateTime::fromString(this->datacool[i+3], "yyyy-MM-dd hh:mm:ss") >= begintime &&
                QDateTime::fromString(this->datacool[i+3], "yyyy-MM-dd hh:mm:ss") <= endtime)
            {
                QString data = QString("%1\t%2\t%3\t%4").arg(this->datacool[i]).arg(this->datacool[i+1]).arg(this->datacool[i+2]).arg(this->datacool[i+3]);
                ui->CarDatatextEdit->append(data);
            }
        }
        }
        else
        {
            QMessageBox::information(nullptr, "警告", "无数据");
        }
        if (ui->CarDatatextEdit->toPlainText().isEmpty())
        {
            QMessageBox::information(nullptr, "提醒", "未找到数据");
        }
    });
}

Search::~Search()
{
    delete ui;
}
