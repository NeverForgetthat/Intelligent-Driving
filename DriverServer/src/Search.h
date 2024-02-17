#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <QDateTime>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();
    static std::vector<QString>datacool;               //保存用户数据容器

private:
    Ui::Search *ui;
};

#endif // SEARCH_H
