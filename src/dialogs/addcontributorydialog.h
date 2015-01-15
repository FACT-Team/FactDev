#ifndef ADDCONTRIBUTORYDIALOG_H
#define ADDCONTRIBUTORYDIALOG_H

#include <QDialog>

namespace Ui {
class AddContributoryDialog;
}

class AddContributoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddContributoryDialog(QWidget *parent = 0);
    ~AddContributoryDialog();

private:
    Ui::AddContributoryDialog *ui;
};

#endif // ADDCONTRIBUTORYDIALOG_H
