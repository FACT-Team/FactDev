#ifndef STARTEDWINDOWSDIALOG_H
#define STARTEDWINDOWSDIALOG_H

#include <QDialog>
#include "models/user.h"
namespace Ui {
class StartedWindowsDialog;
}

using namespace Models;

namespace Gui {
namespace Dialogs {


class StartedWindowsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartedWindowsDialog(QWidget *parent = 0);
    ~StartedWindowsDialog();

    /**
     * @brief UserDataDialog::fillFields Fill line edits with the data of the
     * user
     */
    void fillFields();

    /**
     * @brief accept Valid data inputed by user and add these data in Database
     */
    void accept();


public slots:
    /**
     * @brief UserDataDialog::checkFields Check all fields of dialog
     * components
     */
    void checkFields();

    /**
     * @brief UserDataDialog::browseWorkspacePath Open a new window to define
     * the workspace path of the user
     */
    void browseWorkspacePath();

    /**
     * @brief StartedWindowsDialog::nextToPage2
     */
    void nextToPage2();

    /**
     * @brief StartedWindowsDialog::nextToPage3
     */
    void nextToPage3();

    /**
     * @brief StartedWindowsDialog::saveSettings
     */
    void saveSettings();

private:
    Ui::StartedWindowsDialog *ui;
    User* _user;
};

}
}
#endif // STARTEDWINDOWSDIALOG_H
