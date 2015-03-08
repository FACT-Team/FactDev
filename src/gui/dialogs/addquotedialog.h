#ifndef ADDQUOTEDIALOG_H
#define ADDQUOTEDIALOG_H

#include <QDialog>
#include "models/billing.h"

#include "gui/widgets/contributorieswidget.h"

using namespace Models;

namespace Ui {
class AddQuoteDialog;
}
namespace Gui {
namespace Dialogs {

/**
 * @author @Oxynos
 * @brief The AddQuoteDialog class Window to add or modify a Quote
 */
class AddQuoteDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief AddQuoteDialog::AddQuoteDialog Construct a windows AddQuoteDialog
     * @param parent QWidget of the current windows
     */
    explicit AddQuoteDialog(bool isBilling, int idCustomer = 0, int id = 0,
                            QWidget *parent = 0);
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

public slots:
    void updateBtn(void);
private:
    Billing *_quote;        //!< The quote or billing
    Ui::AddQuoteDialog *ui; //!< User interface of <b>AddQuoteDialog</b>
};
}
}
#endif // ADDQUOTEDIALOG_H
