#include "Circulardashboardwidget.h"
#include "ui_Circulardashboardwidget.h"

CircularDashboardWidget::CircularDashboardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CircularDashboardWidget)
{
    ui->setupUi(this);
}

CircularDashboardWidget::~CircularDashboardWidget()
{
    delete ui;
}

void CircularDashboardWidget:: setValue(int val)
{
    value = val;
    update();
}

void CircularDashboardWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.save();  // 保存画笔状态

    painter.setRenderHint(QPainter::Antialiasing);

    int side = qMin(width(), height());
    int radius = side / 2;
    int centerX = width() / 2;
    int centerY = height() / 2;

    // Draw background circle
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::darkGray);
    painter.drawEllipse(centerX - radius, centerY - radius, side, side);

    // Draw speed scale
    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);
    for (int i = 0; i <= 260; i += 20) {
        painter.save();
        painter.translate(centerX, centerY);
        painter.rotate(-i);
        painter.drawLine(radius - 10, 0, radius, 0);
        painter.drawText(radius - 30, 0, 20, 20, Qt::AlignCenter, QString::number(i));
        painter.restore();
    }

    // Draw pointer
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.translate(centerX, centerY);
    painter.rotate(-value);
    painter.drawPolygon(QPolygon({QPoint(-5, 0), QPoint(5, 0), QPoint(0, -radius)}));

    painter.restore();  // 恢复画笔状态
}






