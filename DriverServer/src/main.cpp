#include "widget.h"

#include <QApplication>
#include <QTextCursor>

int main(int argc, char *argv[])
{
    qRegisterMetaType<qintptr>("qintptr");
    qRegisterMetaType<QTextCursor>("QTextCursor");
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
