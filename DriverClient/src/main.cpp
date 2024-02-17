#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    //更改界面标题
    w.setWindowTitle("智能驾驶舱");

    w.show();
    return a.exec();
}
