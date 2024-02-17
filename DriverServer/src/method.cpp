#include "method.h"

method::method()
{

}

std::vector<QString> method::getSaveVec(const std::vector<QString> &inputVector)
{
    std::vector<QString> resultVector;

    for (size_t i = 0; i < inputVector.size(); i += 4) {
        QString mergedString;

        // 将四个元素合并成一个QString
        for (size_t j = i; j < i + 4 && j < inputVector.size(); ++j)
        {
            mergedString += inputVector[j];
            if (j < i + 3 && j < inputVector.size() - 1)
            {
                mergedString += ",";
            }
        }

        resultVector.push_back(mergedString);
    }

    return resultVector;
}

void method::writeToFile(const std::vector<QString> &inputVector, const QString &filename)
{
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writing:" << filename;
        return;
    }

    QTextStream out(&file);

    for (const auto& str : inputVector)
    {
        out << str << "\n"; // 写入每个QString到文件，每个QString占一行
    }

    file.close();
    qDebug() << "CSV file written successfully:" << filename;
}

void method::readFromCSV(const QString &filename, std::vector<QString> &resultVector)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for reading:" << filename;
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(","); // 以逗号分隔每一行

        for (const QString& field : fields)
        {
            resultVector.push_back(field.trimmed()); // 去除空白字符并将每个字段添加到结果向量中
        }
    }

    file.close();
}



