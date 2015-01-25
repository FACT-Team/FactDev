#ifndef ADDQUOTEDIALOG_H
#define ADDQUOTEDIALOG_H

#include <QDialog>
#include "models/billing.h"

namespace Ui {
class AddQuoteDialog;
}

/**
 * @author Cédric Rohaut
 * @brief The AddQuoteDialog class Window to add or modify a Quote
 */
class AddQuoteDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief AddQuoteDialog Construct a windows AddQuoteDialog
     * @param parent QWidget of the current windows
     */
    explicit AddQuoteDialog(int idCustomer = 0, int id = 0, QWidget *parent = 0);
    ~AddQuoteDialog();

    /**
     * @brief Fill line edits with the data of the quote
     */
    void fillFields();

    /**
     * @brief accept Valid data inputed by user and add these data in Database
     */
    void accept();

    /**
     * @brief reject Cancel the operation and close the windows
     */
    void reject();
public slots:
    void updateBtn(void);
private:
    Billing *_quote; //!< The quote
    Ui::AddQuoteDialog *ui;
};

#endif // ADDQUOTEDIALOG_H
