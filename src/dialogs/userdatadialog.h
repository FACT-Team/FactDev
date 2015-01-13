#ifndef USERDATADIALOG_H
#define USERDATADIALOG_H

#include <QWidget>

namespace Ui {
class userdatadialog;
}

class userdatadialog : public QWidget
{
    Q_OBJECT

public:
    explicit userdatadialog(QWidget *parent = 0);
    ~userdatadialog();

private:
    Ui::userdatadialog *ui;
};

#endif // USERDATADIALOG_H
