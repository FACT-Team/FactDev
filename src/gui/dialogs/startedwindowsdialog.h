#ifndef STARTEDWINDOWSDIALOG_H
#define STARTEDWINDOWSDIALOG_H

#include <QDialog>

namespace Ui {
class StartedWindowsDialog;
}

class StartedWindowsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartedWindowsDialog(QWidget *parent = 0);
    ~StartedWindowsDialog();

private slots:
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
};

#endif // STARTEDWINDOWSDIALOG_H
