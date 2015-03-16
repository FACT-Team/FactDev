#ifndef COMPUTETURNOVERDIALOG_H
#define COMPUTETURNOVERDIALOG_H

#include <QDialog>

namespace Ui {
class ComputeTurnoverDialog;
}

class ComputeTurnoverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComputeTurnoverDialog(QWidget *parent = 0);
    ~ComputeTurnoverDialog();

private:
    Ui::ComputeTurnoverDialog *ui;
};

#endif // COMPUTETURNOVERDIALOG_H
