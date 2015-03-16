#ifndef COMPUTETURNOVERDIALOG_H
#define COMPUTETURNOVERDIALOG_H

#include "database/billingdatabase.h"
#include "database/contributorydatabase.h"
#include "database/ratedatabase.h"
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

public slots:
    /**
     * @brief ComputeTurnoverDialog::computeTurnover compute
     * the turnover between chosen dates in the window
     */
    void computeTurnover();

    /**
     * @brief ComputeTurnoverDialog::endDateControl controls if
     * the <i>end</i> date field is valid
     * @param end
     */
    void endDateControl(QDate end);

    /**
     * @brief ComputeTurnoverDialog::beginDateControl controls
     * if the <i>begin</i> date field is valid
     * @param begin
     */
    void beginDateControl(QDate begin);

private:
    Ui::ComputeTurnoverDialog *ui;
};
}
}

#endif // COMPUTETURNOVERDIALOG_H
