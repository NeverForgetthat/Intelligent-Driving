#ifndef METHOD_H
#define METHOD_H

#include <QApplication>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <vector>
#include <QDebug>


class Convert
{
public:
    static QString getbasedirc();                                                           //获取绝对路径
    static void getsubstrs(std::vector<QString>&vec, const QString &str, char div);         //将有分隔符字符串分离并存入列表
    static QString gettext(const QString &path);                                            //从文件中读取数据并储存到字符串中
    static void puttext(const QString &path, const QString &str);                           //将字符串写入文件中
    static QString Tab2Comma(const QString& str);                                           //将字符串制表符全部转化为逗号
    static QString Comma2Tab(const QString &str);                                           //将逗号转为制表符
    static std::vector<QString> readCSV(const QString &filePath);                           //从文件中读取数据到向量
    static std::vector<QString> cutCommaVec(const std::vector<QString>& originalVector);    //将逗号向量全部分隔得到新向量
};

#endif // METHOD_H
