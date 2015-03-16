#ifndef COMPUTETURNOVERDIALOG_H
#define COMPUTETURNOVERDIALOG_H

#include "database/projectdatabase.h"
#include <QDialog>

namespace Ui {
class ComputeTurnoverDialog;
}

namespace Gui {
namespace Dialogs {
/**
 * @author Manantsoa Razanajatovo
 * @brief The ComputeTurnoverDialog class window
 * to compute a turnover with a period
 */
class ComputeTurnoverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComputeTurnoverDialog(QWidget *parent = 0);
    ~ComputeTurnoverDialog();

private:
    Ui::ComputeTurnoverDialog *ui;
};
}
}

#endif // COMPUTETURNOVERDIALOG_H
