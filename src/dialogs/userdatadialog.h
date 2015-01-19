#ifndef USERDATADIALOG_H
#define USERDATADIALOG_H

#include <QDialog>
#include "models/user.h"

namespace Ui {
class UserDataDialog;
}

/**
 * @author Florent Berbie
 * @brief The UserDataDialog class Window to fill user data
 */
class UserDataDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief UserDataDialog: Construct a window with user data
     * @param parent
     */
    explicit UserDataDialog(QWidget *parent = 0);
    ~UserDataDialog();

    /**
     * @brief UserDataDialog::fillFields Fill line edits with the data of the
     * user
     */
    void fillFields();

    /**
     * @brief accept Valid data inputed by user and add these data in Database
     */
    void accept();

    /**
     * @brief reject Cancel the operation and close the windows
     */
    void reject();

private:
    /**
     * @brief _user The user of this appication
     */
    User* _user;
    Ui::UserDataDialog *ui;
};

#endif // USERDATADIALOG_H
