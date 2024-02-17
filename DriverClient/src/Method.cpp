#include "Method.h"

QString Convert::getbasedirc()
{
    return QCoreApplication::applicationDirPath();
}

void Convert::getsubstrs(std::vector<QString> &vec, const QString &str, char div)
{
    QStringList parts = str.split(div, Qt::SkipEmptyParts);
    foreach (const QString &part, parts)
    {
        vec.push_back(part.trimmed());
    }
}

QString Convert::gettext(const QString &path)
{
    QFile file(path);
    QString text;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        text = file.readAll();
        file.close();
    }

    return text;
}

void Convert::puttext(const QString &path, const QString &str)
{
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        // 检查文件是否为空
        if (file.size() == 0) {
            // 如果文件为空，则写入文件头
            QByteArray header = "Header1,Header2,Header3\n";
            file.write(header);
        }

        QByteArray byteArray = str.toUtf8();        // 转换为字节数组
        file.write(byteArray);                      // 写入字节数组
        file.write("\n");                           // 添加换行符
        file.close();
    }
}

QString Convert::Tab2Comma(const QString& str) {
    QString output = str;
    output.replace('\t', ','); // 将制表符替换为逗号
    return output;
}

QString Convert::Comma2Tab(const QString &str)
{
    QString output = str;
    output.replace(',', '\t'); // 将制表符替换为逗号
    return output;
}

std::vector<QString> Convert::readCSV(const QString &filePath)
{
    std::vector<QString> data;

        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList fields = line.split(","); // 使用逗号分隔符分割字符串
                QString group;
                for(int i = 0; i < fields.size(); i += 3) {
                    if (i > 0) // 不是第一组，添加换行符
                        group += "\n";
                    group += fields[i];
                    if (i + 1 < fields.size()) // 添加制表符
                        group += "," + fields[i + 1];
                    if (i + 2 < fields.size()) // 添加第三个元素
                        group += "," + fields[i + 2];
                }
                data.push_back(group);
            }
            file.close();
        } else {
            qDebug() << "Failed to open file for reading:" << filePath;
        }
        return data;
}

std::vector<QString> Convert::cutCommaVec(const std::vector<QString> &originalVector)
{
    std::vector<QString> newVector;

        for (const QString& str : originalVector) {
            QStringList parts = str.split(",");
            if (parts.size() == 3) {
                newVector.push_back(parts[0]);
                newVector.push_back(parts[1]);
                newVector.push_back(parts[2]);
            } else {
                qDebug()<<"分隔有误";
            }
        }

        return newVector;
}
