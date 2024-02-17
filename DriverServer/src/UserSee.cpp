#include "UserSee.h"
#include "ui_UserSee.h"
#include "myTcpServer.h"

UserSee::UserSee(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserSee)
{
    ui->setupUi(this);

    //图形界面初始化
    //初始化窗口标题
    setWindowTitle("查看在线车辆");
}

UserSee::~UserSee()
{
    delete ui;
}

void UserSee::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    ui->UseNameEdit->clear();
    for (int i = 0; i < int(myTcpServer::clients.size()); ++i)
    {
        ui->UseNameEdit->append(myTcpServer::clients[i]); // 将每个元素添加为一行
    }
}
