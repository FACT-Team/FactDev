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
     * @brief StartedWindowsDialog::fillFields Fill line edits with the data of the
     * user
     */
    void fillFields();

    /**
     * @brief StartedWindowsDialog::getImage
     * @param path
     * @param width
     * @param height
     * @return
     */
    QPixmap getImage(QString path, int width = 256, int height = 256);

public slots:
    /**
     * @brief StartedWindowsDialog::checkFields Check all fields of dialog
     * components
     */
    void checkFields();

    /**
     * @brief StartedWindowsDialog::backToPage2
     */
    void backToPage2();

    /**
     * @brief StartedWindowsDialog::nextToPage2
     */
    void nextToPage2();

    /**
     * @brief StartedWindowsDialog::nextToPage3
     */
    void nextToPage3();

    /**
     * @brief databaseTypeChanged
     * @param index
     */
    void databaseTypeChanged(const int index);

    /**
     * @brief editDatabaseSettings
     */
    void editDatabaseSettings();

    /**
     * @brief StartedWindowsDialog::accept Valid data inputed by user and add
     * these data in Database
     */
    void accept();


private:
    Ui::StartedWindowsDialog *ui;
    User* _user;                    //!< User of the software
    //QPixmap _img;                   //!< Icon image of the current frame
};

}
}
#endif // STARTEDWINDOWSDIALOG_H
