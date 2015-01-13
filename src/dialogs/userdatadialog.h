#ifndef USERDATADIALOG_H
#define USERDATADIALOG_H

#include <QDialog>

namespace Ui {
class UserDataDialog;
}

class UserDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDataDialog(QWidget *parent = 0);
    ~UserDataDialog();

private:
    Ui::UserDataDialog *ui;
};

#endif // USERDATADIALOG_H
