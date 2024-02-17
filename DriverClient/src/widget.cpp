#include "widget.h"
#include "ui_widget.h"

std::vector<QString> DataCool;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //图形界面初始化部分

    //控件加载车图像
    QPixmap image("F:\\QtProject\\DriverClient\\Car.jpg");
    ui->CarViewLabel->setPixmap(image);
    ui->CarViewLabel->setScaledContents(true);                  //自适应调整图像大小

    //初始化网络状态图片
    //初始化网络状态图片
    QPixmap link("F:\\QtProject\\DriverServer\\连接.png");
    QPixmap unlink("F:\\QtProject\\DriverServer\\未连接.png");
    ui->NetStatelabel->setPixmap(unlink);
    ui->NetStatelabel->setScaledContents(true);                //自适应调整图像大小

    //放置速度指示盘
    dashboardWidget = new CircularDashboardWidget(this);
    dashboardWidget->setFixedSize(150, 150);                    // 设置固定大小
    dashboardWidget->move(840, 160);                            // 设置位置

    //传感器下拉框初始化
    ui->SensorcomboBox->addItem("OilGauge");
    ui->SensorcomboBox->addItem("SpeedGauge");
    ui->SensorcomboBox->addItem("DtcGauge");
    ui->SensorcomboBox->addItem("WlpGauge");
    ui->SensorcomboBox->addItem("NumMonitor");
    ui->SensorcomboBox->setCurrentIndex(-1);

    //校检位下拉框初始化
    ui->CheckcomboBox->addItem("No");
    ui->CheckcomboBox->addItem("Odd");
    ui->CheckcomboBox->addItem("Even");
    ui->CheckcomboBox->setCurrentIndex(0);                      //默认为无校检

    //波特率下拉框初始化
    ui->PortcomboBox->addItem("3200");
    ui->PortcomboBox->addItem("6400");
    ui->PortcomboBox->addItem("9600");
    ui->PortcomboBox->addItem("19200");
    ui->PortcomboBox->setCurrentIndex(2);                       //默认波特率9600

    //用户名文字框初始化
    ui->UserNameEdit->setText("MyCar1");

    //IP文字框初始化
    ui->IPEdit->setText("127.0.0.1");

    //端口号文字框初始化
    ui->NetPortEdit->setText("8000");

    //初始化油量条
    ui->OilBar->setRange(0, 100); // 设置进度条的范围
    ui->OilBar->setValue(100); // 设置进度条的初始值

    //内容成员初始化部分

    //初始化传感器
    //这里已经将8个传感器的类型给定义好了
    for(int i=0; i<=7; i++)
    {
        sensor[i] = new SensorItem;
        if(i<3)
        {

            this->sensor[i]->qtypeid = i;
        }
        else if(i>=3 && i<=6)
        {
            this->sensor[i]->qtypeid = 3;
        }
        else
            this->sensor[i]->qtypeid = 4;
    };

    //初始化串口操作工具
    manager = new SerialControl;

    //初始化工具库
    tool = new Convert;

    //初始化定时器
    DataRefreshTimer = new QTimer(this);
    DataRefreshTimer->setInterval(1000);                        //每秒刷新一次各类数据

    DataHandleTimer = new QTimer(this);
    DataHandleTimer->setInterval(3000);                         //每3秒处理一次各类数据

    NetWriteTimer = new QTimer(this);
    NetWriteTimer->setInterval(5000);                           //每5秒向服务器发送一次各类数据

    NetReadTimer = new QTimer(this);
    NetReadTimer->setInterval(1000);                            //每秒读取一次服务器数据
    //初始化线程对象
    for(int i=0; i<=7; i++)
    {
        this->work[i] = new QThread;
    }

    //初始化工作对象
    for(int i=0; i<=7; i++)
    {
        this->worker[i] = new SerialControl;
    }

    //将任务对象放入线程中准备工作
    for(int i=0; i<=7; i++)
    {
        worker[i]->moveToThread(work[i]);
    }

    //初始化客户端
    tcpclient = new TcpClient(this);

    //初始化窗口
    search = new Search;

    //信号槽连接部分

    //修改用户名操作
    connect(ui->ChangenNameButton, &QPushButton::clicked, [this]
    {
        this->username = ui->UserNameEdit->text();
        qDebug()<<"你已经成功修改用户名为"<<this->username;
        QMessageBox::information(nullptr, "修改", "你已经修改用户名为" + this->username);
    });
    
    connect(ui->StartButton, &QPushButton::clicked, [this]()
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;
        DataRefreshTimer->start();
        DataHandleTimer->start();
        NetWriteTimer->start(2500);

        work[0]->start();
        work[1]->start();
        work[2]->start();
        work[3]->start();
        work[4]->start();
        work[5]->start();
        work[6]->start();
        work[7]->start();
    });

    auto ptr0 = worker[0];
    auto ptr1 = worker[1];
    auto ptr2 = worker[2];
    auto ptr3 = worker[3];
    auto ptr4 = worker[4];
    auto ptr5 = worker[5];
    auto ptr6 = worker[6];
    auto ptr7 = worker[7];

    //油量计线程
    connect(this->work[0], &QThread::started, [this, ptr0]
    {
        int checkid = ui->CheckcomboBox->currentIndex();
        int portid = ui->PortcomboBox->currentIndex();

        ptr0->sensorserial = new MySerialPort;
        ptr0->carserial = new MySerialPort;
        //每个情况其实是打开两个串口，车的串口和对应传感器的串口
            if (ptr0 && ptr0->carserial) {
                   this->manager->ChooseSerial(ptr0->carserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";                             //发现给空指针解引用会造成非常严重的后果，指程序崩溃
               }
            this->manager->curserial->setcmbPortName("COM1");
            this->manager->CarSerialInit(checkid, portid);

            if (ptr0 && ptr0->sensorserial) {
                   this->manager->ChooseSerial(ptr0->sensorserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";
               }
            this->manager->curserial->setcmbPortName("COM2");
            this->manager->SensorSerialInit(checkid, portid);
            ui->SensorcomboBox->setItemData(0, true);                                //赋真值，禁止再选中
            Qt::HANDLE threadId = QThread::currentThreadId();
            qDebug() << "Current thread address: " << threadId;
    });
    //定时处理数据
    connect(this->DataHandleTimer, &QTimer::timeout, worker[0], [this, ptr0]()
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;
        QString state = "Get";
        QString rsp = this->sensor[0]->process(state);
        qDebug()<<rsp;
        ptr0->ChooseSerial(ptr0->sensorserial);
        ptr0->HandleWrite(rsp);
        ptr0->ChooseSerial(ptr0->carserial);
        ptr0->HandleReadyRead();
        QString data = ptr0->HandleBuffer();
        this->DataCool.push_back(data);
    });
    //更新到textedit
    connect(ptr0, &SerialControl::dataReceived, this, [this](const QString& data) {
        ui->SensorDataEdit->append(data);
    });

    //速度计线程
    connect(this->work[1], &QThread::started, [this, ptr1]
    {
        int checkid = ui->CheckcomboBox->currentIndex();
        int portid = ui->PortcomboBox->currentIndex();

        ptr1->sensorserial = new MySerialPort;
        ptr1->carserial = new MySerialPort;
            if (ptr1 && ptr1->carserial) {
                   this->manager->ChooseSerial(ptr1->carserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";
               }
            this->manager->curserial->setcmbPortName("COM3");
            this->manager->CarSerialInit(checkid, portid);

            if (ptr1 && ptr1->sensorserial) {
                   this->manager->ChooseSerial(ptr1->sensorserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";
               }
            this->manager->curserial->setcmbPortName("COM4");
            this->manager->SensorSerialInit(checkid, portid);
            Qt::HANDLE threadId = QThread::currentThreadId();
            qDebug() << "Current thread address: " << threadId;
    });
    //定时处理数据
    connect(this->DataHandleTimer, &QTimer::timeout, worker[1], [this, ptr1]()
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;
        QString state = "Get";
        QString rsp = this->sensor[1]->process(state);
        qDebug()<<rsp;
        ptr1->ChooseSerial(ptr1->sensorserial);
        ptr1->HandleWrite(rsp);
        ptr1->ChooseSerial(ptr1->carserial);
        ptr1->HandleReadyRead();
        QString data = ptr1->HandleBuffer();
        this->DataCool.push_back(data);
    });
    //更新到textedit
    connect(ptr1, &SerialControl::dataReceived, this, [this](const QString& data) {
        ui->SensorDataEdit->append(data);
    });

    //车距计线程
    connect(this->work[2], &QThread::started, [this, ptr2]
    {
        int checkid = ui->CheckcomboBox->currentIndex();
        int portid = ui->PortcomboBox->currentIndex();

        ptr2->sensorserial = new MySerialPort;
        ptr2->carserial = new MySerialPort;
            if (ptr2 && ptr2->carserial) {
                   this->manager->ChooseSerial(ptr2->carserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";
               }
            this->manager->curserial->setcmbPortName("COM5");
            this->manager->CarSerialInit(checkid, portid);

            if (ptr2 && ptr2->sensorserial) {
                   this->manager->ChooseSerial(ptr2->sensorserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";
               }
            this->manager->curserial->setcmbPortName("COM6");
            this->manager->SensorSerialInit(checkid, portid);
            Qt::HANDLE threadId = QThread::currentThreadId();
            qDebug() << "Current thread address: " << threadId;
    });
    //定时处理数据
    connect(this->DataHandleTimer, &QTimer::timeout, worker[2], [this, ptr2]()
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;
        QString state = "Get";
        QString rsp = this->sensor[2]->process(state);
        qDebug()<<rsp;
        ptr2->ChooseSerial(ptr2->sensorserial);
        ptr2->HandleWrite(rsp);
        ptr2->ChooseSerial(ptr2->carserial);
        ptr2->HandleReadyRead();
        QString data = ptr2->HandleBuffer();
        this->DataCool.push_back(data);
    });
    //更新到textedit
    connect(ptr2, &SerialControl::dataReceived, this, [this](const QString& data) {
        ui->SensorDataEdit->append(data);
    });

    //胎压计1线程
    connect(this->work[3], &QThread::started, [this, ptr3]
    {
        int checkid = ui->CheckcomboBox->currentIndex();
        int portid = ui->PortcomboBox->currentIndex();

        ptr3->sensorserial = new MySerialPort;
        ptr3->carserial = new MySerialPort;
            if (ptr3 && ptr3->carserial) {
                   this->manager->ChooseSerial(ptr3->carserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";
               }
            this->manager->curserial->setcmbPortName("COM7");
            this->manager->CarSerialInit(checkid, portid);

            if (ptr3 && ptr3->sensorserial) {
                   this->manager->ChooseSerial(ptr3->sensorserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";
               }
            this->manager->curserial->setcmbPortName("COM8");
            this->manager->SensorSerialInit(checkid, portid);
            Qt::HANDLE threadId = QThread::currentThreadId();
            qDebug() << "Current thread address: " << threadId;
    });
    //定时处理数据
    connect(this->DataHandleTimer, &QTimer::timeout, worker[3], [this, ptr3]()
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;
        QString state = "Get";
        QString rsp = this->sensor[3]->process(state);
        qDebug()<<rsp;
        ptr3->ChooseSerial(ptr3->sensorserial);
        ptr3->HandleWrite(rsp);
        ptr3->ChooseSerial(ptr3->carserial);
        ptr3->HandleReadyRead();
        QString data = ptr3->HandleBuffer();
        this->DataCool.push_back(data);
    });
    //更新到textedit
    connect(ptr3, &SerialControl::dataReceived, this, [this](const QString& data) {
        ui->SensorDataEdit->append(data);
    });

    //胎压计2线程
    connect(this->work[4], &QThread::started, [this, ptr4]
    {
        int checkid = ui->CheckcomboBox->currentIndex();
        int portid = ui->PortcomboBox->currentIndex();

        ptr4->sensorserial = new MySerialPort;
        ptr4->carserial = new MySerialPort;
            if (ptr4 && ptr4->carserial) {
                   this->manager->ChooseSerial(ptr4->carserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";
               }
            this->manager->curserial->setcmbPortName("COM9");
            this->manager->CarSerialInit(checkid, portid);

            if (ptr4 && ptr4->sensorserial) {
                   this->manager->ChooseSerial(ptr4->sensorserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";
               }
            this->manager->curserial->setcmbPortName("COM10");
            this->manager->SensorSerialInit(checkid, portid);
            Qt::HANDLE threadId = QThread::currentThreadId();
            qDebug() << "Current thread address: " << threadId;
    });
    //定时处理数据
    connect(this->DataHandleTimer, &QTimer::timeout, worker[4], [this, ptr4]()
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;
        QString state = "Get";
        QString rsp = this->sensor[4]->process(state);
        qDebug()<<rsp;
        ptr4->ChooseSerial(ptr4->sensorserial);
        ptr4->HandleWrite(rsp);
        ptr4->ChooseSerial(ptr4->carserial);
        ptr4->HandleReadyRead();
        QString data = ptr4->HandleBuffer();
        this->DataCool.push_back(data);
    });
    //更新到textedit
    connect(ptr5, &SerialControl::dataReceived, this, [this](const QString& data) {
        ui->SensorDataEdit->append(data);
    });

    //胎压计3线程
    connect(this->work[5], &QThread::started, [this, ptr5]
    {
        int checkid = ui->CheckcomboBox->currentIndex();
        int portid = ui->PortcomboBox->currentIndex();

        ptr5->sensorserial = new MySerialPort;
        ptr5->carserial = new MySerialPort;
            if (ptr5 && ptr5->carserial) {
                   this->manager->ChooseSerial(ptr5->carserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";
               }
            this->manager->curserial->setcmbPortName("COM11");
            this->manager->CarSerialInit(checkid, portid);

            if (ptr5 && ptr5->sensorserial) {
                   this->manager->ChooseSerial(ptr5->sensorserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";
               }
            this->manager->curserial->setcmbPortName("COM12");
            this->manager->SensorSerialInit(checkid, portid);
            Qt::HANDLE threadId = QThread::currentThreadId();
            qDebug() << "Current thread address: " << threadId;
    });
    //定时处理数据
    connect(this->DataHandleTimer, &QTimer::timeout, worker[5], [this, ptr5]()
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;
        QString state = "Get";
        QString rsp = this->sensor[5]->process(state);
        qDebug()<<rsp;
        ptr5->ChooseSerial(ptr5->sensorserial);
        ptr5->HandleWrite(rsp);
        ptr5->ChooseSerial(ptr5->carserial);
        ptr5->HandleReadyRead();
        QString data = ptr5->HandleBuffer();
        this->DataCool.push_back(data);
    });
    //更新到textedit
    connect(ptr5, &SerialControl::dataReceived, this, [this](const QString& data) {
        ui->SensorDataEdit->append(data);
    });

    //胎压计4线程
    connect(this->work[6], &QThread::started, [this, ptr6]
    {
        int checkid = ui->CheckcomboBox->currentIndex();
        int portid = ui->PortcomboBox->currentIndex();

        ptr6->sensorserial = new MySerialPort;
        ptr6->carserial = new MySerialPort;
            if (ptr6 && ptr6->carserial) {
                   this->manager->ChooseSerial(ptr6->carserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";
               }
            this->manager->curserial->setcmbPortName("COM13");
            this->manager->CarSerialInit(checkid, portid);

            if (ptr6 && ptr6->sensorserial) {
                   this->manager->ChooseSerial(ptr6->sensorserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";
               }
            this->manager->curserial->setcmbPortName("COM14");
            this->manager->SensorSerialInit(checkid, portid);
            Qt::HANDLE threadId = QThread::currentThreadId();
            qDebug() << "Current thread address: " << threadId;
    });
    //定时处理数据
    connect(this->DataHandleTimer, &QTimer::timeout, worker[6], [this, ptr6]()
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;
        QString state = "Get";
        QString rsp = this->sensor[6]->process(state);
        qDebug()<<rsp;
        ptr6->ChooseSerial(ptr6->sensorserial);
        ptr6->HandleWrite(rsp);
        ptr6->ChooseSerial(ptr6->carserial);
        ptr6->HandleReadyRead();
        QString data = ptr6->HandleBuffer();
        this->DataCool.push_back(data);
    });
    //更新到textedit
    connect(ptr6, &SerialControl::dataReceived, this, [this](const QString& data) {
        ui->SensorDataEdit->append(data);
    });

    //车辆数线程
    connect(this->work[7], &QThread::started, [this, ptr7]
    {
        int checkid = ui->CheckcomboBox->currentIndex();
        int portid = ui->PortcomboBox->currentIndex();

        ptr7->sensorserial = new MySerialPort;
        ptr7->carserial = new MySerialPort;
            if (ptr7 && ptr7->carserial) {
                   this->manager->ChooseSerial(ptr7->carserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";
               }
            this->manager->curserial->setcmbPortName("COM15");
            this->manager->CarSerialInit(checkid, portid);

            if (ptr7 && ptr7->sensorserial) {
                   this->manager->ChooseSerial(ptr7->sensorserial);
               } else {
                   qDebug() << "噢糟糕，你使用了一个空指针";
               }
            this->manager->curserial->setcmbPortName("COM16");
            this->manager->SensorSerialInit(checkid, portid);
            Qt::HANDLE threadId = QThread::currentThreadId();
            qDebug() << "Current thread address: " << threadId;
    });
    //定时处理数据
    connect(this->DataHandleTimer, &QTimer::timeout, worker[7], [this, ptr7]()
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;
        QString state = "Get";
        QString rsp = this->sensor[7]->process(state);
        qDebug()<<rsp;
        ptr7->ChooseSerial(ptr7->sensorserial);
        ptr7->HandleWrite(rsp);
        ptr7->ChooseSerial(ptr7->carserial);
        ptr7->HandleReadyRead();
        QString data = ptr7->HandleBuffer();
        this->DataCool.push_back(data);
    });
    //更新到textedit
    connect(ptr7, &SerialControl::dataReceived, this, [this](const QString& data) {
        ui->SensorDataEdit->append(data);
    });

    //防止已经打开串口的传感器重复打开，打开该传感器选项置空
    connect(ui->SensorcomboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index)
    {
        QVariant data = ui->SensorcomboBox->itemData(index);
        // 检查该项的数据是否为禁止选中的标志
        if (data.isValid() && data.toBool())
        {
            ui->SensorcomboBox->setCurrentIndex(index - 1);
        }
    });
    //读取和置空
    connect(ui->OpenSerialButton, &QPushButton::clicked, [this]()
        {
            int tyid = ui->SensorcomboBox->currentIndex();
            switch (tyid)
            {
            case 0:
                ui->SensorcomboBox->setItemData(0, true);break;
            case 1:
                ui->SensorcomboBox->setItemData(1, true);break;
            case 2:
                ui->SensorcomboBox->setItemData(2, true);break;
            case 3:
                ui->SensorcomboBox->setItemData(3, true);break;
            case 4:
                ui->SensorcomboBox->setItemData(4, true);break;
            default:
                break;
            }
        });

    //每秒钟更新一次传感器数据
    connect(this->DataRefreshTimer, &QTimer::timeout, [this]()
    {
        for (int i=0; i<=7;i++)
        {
            this->sensor[i]->getdata();
        }
    });

    //暂停后暂停定时器，传感器数据更新停止,处理也停止
    connect(ui->PauseButton, &QPushButton::clicked, [this]()
    {
        this->DataRefreshTimer->stop();
        this->DataHandleTimer->stop();
        this->NetWriteTimer->stop();
        QString state = "Pause";
        //更新传感器状态为休眠
        for (int i=0; i<=7; i++)
        {
            this->sensor[i]->qstateid = 2;
        }
    });

    //继续后重新开启定时器，传感器数据的更新与处理启动
    connect(ui->ContinueButton, &QPushButton::clicked, [this]()
    {
        this->DataRefreshTimer->start();
        this->DataHandleTimer->start();
        QString state = "Pause";
        //更新传感器状态为休眠
        for (int i=0; i<=7; i++)
        {
            this->sensor[i]->qstateid = 3;
        }
    });

    //停止后销毁所有工作对象，数据置零
    connect(ui->StopButton, &QPushButton::clicked,[this]()
    {
        this->DataRefreshTimer->stop();
        this->DataHandleTimer->stop();
        ui->OilBar->setValue(0);
        ui->Press1Edit->setText("  MPa");
        ui->Press2Edit->setText("  MPa");
        ui->Press3Edit->setText("  MPa");
        ui->Press4Edit->setText("  MPa");
        ui->CarCountlcd->display(0);
        this->dashboardWidget->setValue(-90);
        ui->SensorDataEdit->clear();
        qDebug()<< "Vector contents: ";
            for (const auto &elem : DataCool) {
                qDebug() << elem << " ";
            }
    });

    connect(ui->StopButton, &QPushButton::clicked, this->worker[0], &SerialControl::deleteLater);
    connect(ui->StopButton, &QPushButton::clicked, this->worker[1], &SerialControl::deleteLater);
    connect(ui->StopButton, &QPushButton::clicked, this->worker[2], &SerialControl::deleteLater);
    connect(ui->StopButton, &QPushButton::clicked, this->worker[3], &SerialControl::deleteLater);
    connect(ui->StopButton, &QPushButton::clicked, this->worker[4], &SerialControl::deleteLater);
    connect(ui->StopButton, &QPushButton::clicked, this->worker[5], &SerialControl::deleteLater);
    connect(ui->StopButton, &QPushButton::clicked, this->worker[6], &SerialControl::deleteLater);
    connect(ui->StopButton, &QPushButton::clicked, this->worker[7], &SerialControl::deleteLater);

    connect(this->worker[0], &SerialControl::destroyed, this->work[0], &QThread::quit);
    connect(this->worker[1], &SerialControl::destroyed, this->work[1], &QThread::quit);
    connect(this->worker[2], &SerialControl::destroyed, this->work[2], &QThread::quit);
    connect(this->worker[3], &SerialControl::destroyed, this->work[3], &QThread::quit);
    connect(this->worker[4], &SerialControl::destroyed, this->work[4], &QThread::quit);
    connect(this->worker[5], &SerialControl::destroyed, this->work[5], &QThread::quit);
    connect(this->worker[6], &SerialControl::destroyed, this->work[6], &QThread::quit);
    connect(this->worker[7], &SerialControl::destroyed, this->work[7], &QThread::quit);

    connect(this->work[0], &QThread::finished, this->work[0], &QThread::deleteLater);
    connect(this->work[1], &QThread::finished, this->work[1], &QThread::deleteLater);
    connect(this->work[2], &QThread::finished, this->work[2], &QThread::deleteLater);
    connect(this->work[3], &QThread::finished, this->work[3], &QThread::deleteLater);
    connect(this->work[4], &QThread::finished, this->work[4], &QThread::deleteLater);
    connect(this->work[5], &QThread::finished, this->work[5], &QThread::deleteLater);
    connect(this->work[6], &QThread::finished, this->work[6], &QThread::deleteLater);
    connect(this->work[7], &QThread::finished, this->work[7], &QThread::deleteLater);

    //油量条数据响应
    connect(this->sensor[0], &SensorItem::ValChanged, [this](float val)
    {
        ui->OilBar->setValue(val);
    });

    //速度盘数据响应
    connect(this->sensor[1], &SensorItem::ValChanged, [this](float val)
    {
        this->dashboardWidget->setValue(int(val)-88);
    });

    //车辆数LCD响应
    connect(this->sensor[7], &SensorItem::ValChanged, [this](float val)
    {
        ui->CarCountlcd->display(int(val));
    });

    //胎压显示框响应
    connect(this->sensor[3], &SensorItem::ValChanged, [this](float val)
    {
        QString str = QString::number(val) + "MPa";
        ui->Press1Edit->setText(str);
    });
    connect(this->sensor[4], &SensorItem::ValChanged, [this](float val)
    {
        QString str = QString::number(val+0.02) + "MPa";
        ui->Press2Edit->setText(str);
    });
    connect(this->sensor[5], &SensorItem::ValChanged, [this](float val)
    {
        QString str = QString::number(val-0.01) + "MPa";
        ui->Press3Edit->setText(str);
    });
    connect(this->sensor[6], &SensorItem::ValChanged, [this](float val)
    {
        QString str = QString::number(val-0.02) + "MPa";
        ui->Press4Edit->setText(str);
    });

    //从datacool保存到文件
    connect(ui->SaveFileButton, &QPushButton::clicked, [this]()
    {
        //删除空项
        DataCool.erase(std::remove_if(DataCool.begin(), DataCool.end(), [](const QString& str)
        {
            return str.isEmpty();
        }), DataCool.end());
        QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("CSV Files (*.csv)"));
        for (const QString &elem : DataCool)
        {
            Convert::puttext(filePath, elem);
        }
        ui->SensorDataEdit->clear();
        DataCool.clear();
    });

    //从文件读取数据到datacool
    connect(ui->ReadFileButton, &QPushButton::clicked, [this]
    {
        QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("CSV Files (*.csv)"));
        if (!filePath.isEmpty()) {
            DataCool = Convert::readCSV(filePath);
            for (const QString &elem : DataCool)
            {
                QString data1 = Convert::Comma2Tab(elem);
                this->DataCool.push_back(elem);
                ui->SensorDataEdit->append(data1);
            }
        }
    });

    //点击查询数据显示查询窗口
    connect(ui->SearchButton, &QPushButton::clicked, [this]
    {
        Search::handleVEC = Convert::cutCommaVec(DataCool);
        for (const QString &str : Search::handleVEC) {
            qDebug() << str;
        }
        this->search->show();
    });

    //点击打开文件显示打开文件窗口并可打开文件
    connect(ui->OpenFileButton, &QPushButton::clicked, [this]
    {
       QString fileName = QFileDialog::getOpenFileName(this, tr("打开文件"), "", tr("CSV (逗号分隔) (*.csv)"));
       //选择的文件即被打开
       if (fileName.isEmpty())
       {
           // 用户取消了打开文件对话框
           qDebug() << "用户取消了打开文件对话框";
       }
       else
       {
           // 使用系统默认的程序打开文件
           QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
       }
    });

    //客户端连接状态
    connect(this->tcpclient, &TcpClient::StateboolChanged, [this, link, unlink]
    {
        if (tcpclient->isConnected())
            {
                ui->NetStatelabel->setPixmap(link);                 //显示第一张图片
                ui->NetStatelabel->setScaledContents(true);         //自适应调整图像大小
            }
            else
            {
                ui->NetStatelabel->setPixmap(unlink);               //显示第二张图片
                ui->NetStatelabel->setScaledContents(true);         //自适应调整图像大小
            }
    });

    //启动服务
    connect(ui->NetStartButton, &QPushButton::clicked,[this]
    {
        QString ip = ui->IPEdit->text();
        uint port = ui->NetPortEdit->text().toInt();
        tcpclient->UserName = ui->UserNameEdit->text();
        tcpclient->connectToServer(ip, port);
    });

    //断开服务
    connect(ui->NetStopButton, &QPushButton::clicked, [this]
    {
        tcpclient->disconnectFromServer();
    });

    //发送汽车数据
    connect(this->NetWriteTimer, &QTimer::timeout, [this]
    {
        QString state = "Get";
        QString rsp = "用户(s)：" + username + "<<" + "\t" + this->sensor[1]->process(state);
        tcpclient->sendMessage(rsp);
        rsp = "用户(s)：" + username + "<<" + "\t" + this->sensor[2]->process(state);
        tcpclient->sendMessage(rsp);
    });

    //发送自定义内容
    connect(ui->Send2CenterButton, &QPushButton::clicked, [this]
    {
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
        QString msg = "用户：" + username + "<<" + "   " +ui->SendMsgEdit->toPlainText() + "\t\t" + currentDateTimeString;
        tcpclient->sendMessage(msg);
    });

    //读取中心消息
    connect(this->tcpclient, &TcpClient::messageReceived, [this](QString message)
    {
        ui->NetMsgEdit->append(message);
    });

    //清空网络消息
    connect(ui->ClearNetButton, &QPushButton::clicked, [=]
    {
        ui->NetMsgEdit->clear();
    });
}

Widget::~Widget()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    QString rsp = QString("%1: %2<<   %3    \t\t%4").arg("用户").arg(this->tcpclient->UserName).arg("已断开").arg(currentDateTimeString);
    this->tcpclient->sendMessage(rsp);
    delete ui;
}
