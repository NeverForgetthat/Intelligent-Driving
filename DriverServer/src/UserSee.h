#ifndef USERSEE_H
#define USERSEE_H

#include <QWidget>

namespace Ui {
class UserSee;
}

class UserSee : public QWidget
{
    Q_OBJECT

public:
    explicit UserSee(QWidget *parent = nullptr);
    ~UserSee();

protected:
    void showEvent(QShowEvent *event) override;

private:
    Ui::UserSee *ui;
};

#endif // USERSEE_H
