#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //初始化界面
    //初始化窗口标题
    setWindowTitle("服务器中心");

    //IP文字框初始化
    ui->IPEdit->setText("127.0.0.1");

    //端口号文字框初始化
    ui->PortEdit->setText("8000");

    //初始化网络状态图片
    QPixmap link("F:\\QtProject\\DriverServer\\连接.png");
    QPixmap unlink("F:\\QtProject\\DriverServer\\未连接.png");
    ui->StateViewlabel->setPixmap(unlink);
    ui->StateViewlabel->setScaledContents(true);                //自适应调整图像大小

    //监控计数实现
    videoWidget = new QVideoWidget(this);
    //设置视频文件，并播放程序所在目录下的video.mp4
    videoWidget->setGeometry(593, 54, 495, 278); // 设置大小和位置
    player = new QMediaPlayer;
    player->setVideoOutput(videoWidget);
    player->setMedia(QUrl::fromLocalFile("F:\\QtProject\\DriverServer\\output_video.avi"));
    player->play();

    //对象初始化
    //初始化服务器
    TcpServer = new myTcpServer;

    test = new myTcpServerControl;

    this->myClientWork[0] = new QThread;
    this->myClientWorker[0] = new myTcpServerControl;
    this->myClientWork[1] = new QThread;
    this->myClientWorker[1] = new myTcpServerControl;
    this->myClientWork[2] = new QThread;
    this->myClientWorker[2] = new myTcpServerControl;

    myClientWorker[0]->moveToThread(myClientWork[0]);
    myClientWorker[1]->moveToThread(myClientWork[1]);
    myClientWorker[2]->moveToThread(myClientWork[2]);
    //定义捕获指针用于线程交互
    auto ptr0 = myClientWorker[0];
    auto ptr1 = myClientWorker[1];
    auto ptr2 = myClientWorker[2];

    //窗口
    UserSee *usersee= new UserSee;
    Search *search = new Search;

    //信号槽连接
    //按下数据查询显示数据查询窗口
    connect(ui->SearchButton, &QPushButton::clicked, [=]
    {
        search->show();
    });

    //按下用户查询显示用户查询窗口
    connect(ui->UserSeeButton, &QPushButton::clicked, [=]
    {
        usersee->show();
    });

    //启动服务
    connect(ui->StartButton, &QPushButton::clicked, [this]
    {
        QString ip = ui->IPEdit->text();
        qint16 port = ui->PortEdit->text().toInt();
        if(TcpServer->startServer(ip, port))
        {
            state = true;
        };
        emit StateboolChanged();
    }
    );

    //暂停服务
    connect(ui->PauseButton, &QPushButton::clicked, [this]
    {
       TcpServer->stopServer();
       if(!TcpServer->isServerRunning())
       {
           state = false;
       }
       emit StateboolChanged();
    });

    //图标变换
    connect(this, &Widget::StateboolChanged, [this, link, unlink]
    {
        if (state)
            {
                ui->StateViewlabel->setPixmap(link); // 显示第一张图片
                ui->StateViewlabel->setScaledContents(true); // 自适应调整图像大小
            }
            else
            {
                ui->StateViewlabel->setPixmap(unlink); // 显示第二张图片
                ui->StateViewlabel->setScaledContents(true); // 自适应调整图像大小
            }
    });

    //开启线程
    connect(this->TcpServer, &myTcpServer::newDescriptor,[this](qintptr newDescriptor)
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;
        //判断线程是否在工作
        for (int i=0; i<=2; i++)
        {
            if (!myClientWork[i]->isRunning())
            {
                myClientWork[i]->start();
                switch (i)
                {
                case 0:
                    emit WakeUp0(newDescriptor);
                    break;
                case 1:
                    emit WakeUp1(newDescriptor);
                    break;
                case 2:
                    emit WakeUp2(newDescriptor);
                    break;
                default:
                    break;
                }
                break;
            }
        }
    });

    //唤醒0号线程
    connect(this, &Widget::WakeUp0, myClientWorker[0], [this,ptr0](qintptr newDescriptor)
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;
        ptr0->setSocket(newDescriptor);
        connect(ptr0->socket, &QTcpSocket::disconnected, this->TcpServer, &myTcpServer::handleClientDisconnect);
        connect(ptr0->socket, &QTcpSocket::disconnected, this->TcpServer, [=]
        {
            myTcpServer::is0FirstMessageReceived = false;
        });
        connect(ptr0->socket, &QTcpSocket::disconnected, myClientWork[0], [=]
        {
            myClientWork[0]->quit();
        });
    });
    //0号线程与主线程通信
    connect(ptr0, &myTcpServerControl::messageReceived, this, [this](QString message)
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;

        if (!myTcpServer::is0FirstMessageReceived)
        {
            int index = message.indexOf(' '); // 查找字符的位置
            if (index != -1)
            {
                QString user = message.mid(0, index);
                qDebug() << "Result:" << user; // 输出结果为 "Hello"
                myTcpServer::clients.push_back(user);
            }
            qDebug()<<myTcpServer::clients[0];
            myTcpServer::is0FirstMessageReceived = true;
        }


        ui->MsgViewEdit->append(message);
        qDebug()<<message;
        message.replace("<","");

        QChar charToFind1 = 's'; // 要查找的字符
        int index = message.indexOf(charToFind1); // 查找字符的位置
        if (index != -1)
        {
            ui->CarDataEdit->append(message);

            // 删除冒号及冒号之前的所有字符
            message = message.remove(QRegExp(".*："));       //正则

            // 用制表符作为分隔符将字符串分割成四部分
            QStringList parts = message.split("\t");

            qDebug()<<parts[0]<<parts[1]<<parts[2]<<parts[3];
            // 存入Search::datacool中
            if (parts.size() == 4) {
                Search::datacool.push_back(parts[0]);
                Search::datacool.push_back(parts[1]);
                Search::datacool.push_back(parts[2]);
                Search::datacool.push_back(parts[3]);
            }
            else
            {
                qDebug()<<"分割错误";
            }
        }
    });
    //发送消息到0号客户端
    connect(ui->MsgSendButton, &QPushButton::clicked, ptr0, [this, ptr0]
    {
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
        QString msg = QString("中心") + ">>" + "   " + ui->MsgSendEdit->toPlainText() + "\t\t" + currentDateTimeString;
        ptr0->sendMessage(msg);
    });
    //添加发送消息到主线程框
    connect(ptr0, &myTcpServerControl::messageSend, [this](QString message)
    {
        ui->MsgViewEdit->append(message);
    });

    //唤醒线程1
    connect(this, &Widget::WakeUp1, myClientWorker[1], [this,ptr1](qintptr newDescriptor)
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;
        ptr1->setSocket(newDescriptor);
        connect(ptr1->socket, &QTcpSocket::disconnected, this->TcpServer, &myTcpServer::handleClientDisconnect);
        connect(ptr1->socket, &QTcpSocket::disconnected, this->TcpServer, [=]
        {
            myTcpServer::is1FirstMessageReceived = false;
        });
        connect(ptr1->socket, &QTcpSocket::disconnected, myClientWork[1], [=]
        {
            myClientWork[1]->quit();
        });
    });
    //线程1与主线程通信
    connect(ptr1, &myTcpServerControl::messageReceived, this, [this](QString message)
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;

        if (!myTcpServer::is1FirstMessageReceived)
        {
            int index = message.indexOf(' '); // 查找字符的位置
            if (index != -1)
            {
                QString user = message.mid(0, index);
                qDebug() << "Result:" << user; // 输出结果为 "Hello"
                myTcpServer::clients.push_back(user);
            }
            qDebug()<<myTcpServer::clients[1];
            myTcpServer::is1FirstMessageReceived = true;
        }

        ui->MsgViewEdit->append(message);
        qDebug()<<message;
        message.replace("<","");

        QChar charToFind1 = 's'; // 要查找的字符

        int index = message.indexOf(charToFind1); // 查找字符的位置
        if (index != -1)
        {
            ui->CarDataEdit->append(message);

            // 删除冒号及冒号之前的所有字符
            message = message.remove(QRegExp(".*："));       //正则

            // 用制表符作为分隔符将字符串分割成四部分
            QStringList parts = message.split("\t");

            // 存入Search::datacool中
            if (parts.size() == 4) {
                Search::datacool.push_back(parts[0]);
                Search::datacool.push_back(parts[1]);
                Search::datacool.push_back(parts[2]);
                Search::datacool.push_back(parts[3]);
            }
            else
            {
                qDebug()<<"分割错误";
            }
        }
    });
    //发送消息到线程1客户端
    connect(ui->MsgSendButton, &QPushButton::clicked, ptr1, [this, ptr1]
    {
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
        QString msg = QString("中心") + ">>" + "   " + ui->MsgSendEdit->toPlainText() + "\t\t" + currentDateTimeString;
        ptr1->sendMessage(msg);
    });
    //添加发送消息到主线程
    connect(ptr1, &myTcpServerControl::messageSend, [this](QString message)
    {
        ui->MsgViewEdit->append(message);
    });

    //唤醒线程2
    connect(this, &Widget::WakeUp2, myClientWorker[1], [this,ptr2](qintptr newDescriptor)
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;
        ptr2->setSocket(newDescriptor);
        connect(ptr2->socket, &QTcpSocket::disconnected, this->TcpServer, &myTcpServer::handleClientDisconnect);
        connect(ptr2->socket, &QTcpSocket::disconnected, this->TcpServer, [=]
        {
            myTcpServer::is2FirstMessageReceived = false;
        });
        connect(ptr2->socket, &QTcpSocket::disconnected, myClientWork[2], [=]
        {
            myClientWork[2]->quit();
        });
    });
    //线程2与主线程通信
    connect(ptr2, &myTcpServerControl::messageReceived, this, [this](QString message)
    {
        Qt::HANDLE threadId = QThread::currentThreadId();
        qDebug() << "Current thread address: " << threadId;

        if (!myTcpServer::is2FirstMessageReceived)
        {
            int index = message.indexOf(' '); // 查找字符的位置
            if (index != -1)
            {
                QString user = message.mid(0, index);
                qDebug() << "Result:" << user; // 输出结果为 "Hello"
                myTcpServer::clients.push_back(user);
            }
            qDebug()<<myTcpServer::clients[2];
            myTcpServer::is2FirstMessageReceived = true;
        }

        ui->MsgViewEdit->append(message);
        qDebug()<<message;
        message.replace("<","");

        QChar charToFind1 = 's'; // 要查找的字符

        int index = message.indexOf(charToFind1); // 查找字符的位置
        if (index != -1)
        {
            ui->CarDataEdit->append(message);

            // 删除冒号及冒号之前的所有字符
            message = message.remove(QRegExp(".*："));       //正则

            // 用制表符作为分隔符将字符串分割成四部分
            QStringList parts = message.split("\t");

            // 存入Search::datacool中
            if (parts.size() == 4) {
                Search::datacool.push_back(parts[0]);
                Search::datacool.push_back(parts[1]);
                Search::datacool.push_back(parts[2]);
                Search::datacool.push_back(parts[3]);
            }
            else
            {
                qDebug()<<"分割错误";
            }
        }
    });
    //发送消息到线程2客户端
    connect(ui->MsgSendButton, &QPushButton::clicked, ptr2, [this, ptr2]
    {
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
        QString msg = QString("中心") + ">>" + "   " + ui->MsgSendEdit->toPlainText() + "\t\t" + currentDateTimeString;
        ptr2->sendMessage(msg);
    });
    //添加消息到主线程
    connect(ptr2, &myTcpServerControl::messageSend, [this](QString message)
    {
        ui->MsgViewEdit->append(message);
    });

    //关闭服务
    connect(ui->StopButton, &QPushButton::clicked, this, &QWidget::close);

    //数据保存
    connect(ui->SaveButton, &QPushButton::clicked, [=]
    {
        std::vector<QString>savevec =  method::getSaveVec(Search::datacool);
        QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("CSV Files (*.csv)"));
        method::writeToFile(savevec, filePath);
    });

    //读取数据
    connect(ui->ReadButton, &QPushButton::clicked, [=]
    {
        QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("CSV Files (*.csv)"));
        if (!filePath.isEmpty())
        {
            method::readFromCSV(filePath, Search::datacool);
        }
        qDebug()<<Search::datacool[0]<<Search::datacool[1];
    });
}

Widget::~Widget()
{
    delete ui;
}


