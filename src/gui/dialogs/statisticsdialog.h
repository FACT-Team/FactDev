#ifndef STATISTICSDIALOG_H
#define STATISTICSDIALOG_H

#include <QDialog>

namespace Ui {
class StatisticsDialog;
}

namespace Gui {
namespace Dialogs {

/**
 * @brief The StatisticsDialog class window
 * to have global informations or about a customer
 */
class StatisticsDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construct a windows StatisticsDialog
     * @param global if it's the global stats or customer stats
     * @param idCustomer the id of the Customer
     */
    explicit StatisticsDialog(bool global = true, int idCustomer = 0, QWidget *parent = 0);
    ~StatisticsDialog();

    /**
     * @brief Update interface (text)
     * @param nbBills
     * @param nbBillsPaid
     * @param nbQuotes
     * @param nbProjects
     */
    void updateUi(int nbBills, int nbBillsPaid, int nbQuotes, int nbProjects);

    /**
     * @brief Change the title of the windows
     * if it's global stats or customer stats
     */
    void changeMainTitle();

    /**
     * @brief Get the correct terminaison
     * @param nb
     */
    QString singularPlural(int nb);

private:
    Ui::StatisticsDialog *ui;   //!< User Interface
    bool isGlobal;              //!< Global stats or customer stats
    int customerId;             //!< Customer id
};

}
}

#endif // STATISTICSDIALOG_H
