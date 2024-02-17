#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <vector>
#include <QDateTime>
#include <QDebug>
#include <QMessageBox>
#include "Method.h"

namespace Ui {
class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();

    static std::vector<QString> handleVEC;

private:
    Ui::Search *ui;
    QString sensortype;
    QDateTime begintime;
    QDateTime endtime;
};

#endif // SEARCH_H
