#ifndef CIRCULARDASHBOARDWIDGET_H
#define CIRCULARDASHBOARDWIDGET_H

#include <QWidget>
#include <QPainter>
#include <cmath>

namespace Ui {
class CircularDashboardWidget;
}

class CircularDashboardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CircularDashboardWidget(QWidget *parent = nullptr);
    ~CircularDashboardWidget();

    void setValue(int val);                             //设置仪表盘数值

protected:
    void paintEvent(QPaintEvent *event) override;       //绘制

private:
    int value = -90;

    Ui::CircularDashboardWidget *ui;
};

#endif // CIRCULARDASHBOARDWIDGET_H
