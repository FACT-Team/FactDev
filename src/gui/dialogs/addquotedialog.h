#ifndef ADDQUOTEDIALOG_H
#define ADDQUOTEDIALOG_H

#include <QDialog>
#include "models/billing.h"
#include "database/billingdatabase.h"

#include "gui/widgets/contributorieswidget.h"

using namespace Models;

namespace Ui {
class AddQuoteDialog;
}
namespace Gui {
namespace Dialogs {

/**
 * @author Cédric Rohaut
 * @brief The AddQuoteDialog class Window to add or modify a Quote
 */
class AddQuoteDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief AddQuoteDialog::AddQuoteDialog Construct a windows AddQuoteDialog
     * @param isBilling displaying of a quote or a Billing
     * @param idCustomer the id of the Customer
     * @param id the id of the quote or the billing of the Customer's Project
     * @param edit if it's an edition or a copy of a quote/Billing
     * @param parent QWidget of the current windows
     */
    explicit AddQuoteDialog(bool isBilling, int idCustomer = 0, int id = 0,
                            bool copy = true, QWidget *parent = 0);
    ~AddQuoteDialog();

    /**
     * @brief AddQuoteDialog::Fill line edits with the data of the quote
     */
    void fillFields();
    /**
     * @brief AddQuoteDialog::getNumber return the number of bill or quote
     * @return int
     */
    int getNumber();
    /**
     * @brief AddQuoteDialog::accept Valid data inputed by user and add these data in Database
     */
    void accept();
    /**
     * @brief AddQuoteDialog::reject Cancel the operation and close the windows
     */
    void reject();
    /**
     * @brief AddQuoteDialog::getCopy return if <b>AddQuoteDialog</b> is a copy of
     * Billing/quote or if it's edition and add of Billing/quote
     * @return if it's a copy or not
     */
    bool getCopy() const;
    /**
     * @brief AddQuoteDialog::setCopy Change the <i>_copy</i> value to define if it's
     * a copy of a Billing/quote or if it's a new Billing or a Billing edition
     * @param copy
     */
    void setCopy(bool copy);

public slots:
    void updateBtn(void);
private:
    Billing *_quote;        //!< The quote or billing
    Ui::AddQuoteDialog *ui; //!< User interface of <b>AddQuoteDialog</b>
    bool _copy; //!< if <b>AddQuoteDialog</b> is opened by a Billing/quote copy or not
};
}
}
#endif // ADDQUOTEDIALOG_H
