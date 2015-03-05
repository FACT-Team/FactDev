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

private:
    Ui::StartedWindowsDialog *ui;
};

#endif // STARTEDWINDOWSDIALOG_H
