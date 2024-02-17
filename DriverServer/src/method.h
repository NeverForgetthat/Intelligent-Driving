#ifndef METHOD_H
#define METHOD_H

#include <vector>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>

class method
{
public:
    method();
    static std::vector<QString> getSaveVec(const std::vector<QString>& inputVector);
    static void writeToFile(const std::vector<QString>& inputVector, const QString& filename);
    static void readFromCSV(const QString& filename, std::vector<QString>& resultVector);
};

#endif // METHOD_H
