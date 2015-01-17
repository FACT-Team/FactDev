#ifndef USERDATADIALOG_H
#define USERDATADIALOG_H

#include <QDialog>
#include "models/user.h"

namespace Ui {
class UserDataDialog;
}

class UserDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDataDialog(QWidget *parent = 0);
    ~UserDataDialog();

    void fillFields();
    void accept();
    void reject();
private:
    User* _user;
    Ui::UserDataDialog *ui;
};

#endif // USERDATADIALOG_H
