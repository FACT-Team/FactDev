#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>

namespace Ui {
class userdialog;
}

class userdialog : public QDialog
{
    Q_OBJECT

public:
    explicit userdialog(QWidget *parent = 0);
    ~userdialog();

private:
    Ui::userdialog *ui;
};

#endif // USERDIALOG_H
