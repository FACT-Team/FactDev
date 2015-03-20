#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>

#include "database/customerdatabase.h"

#include "models/search.h"

namespace Ui {
class searchWidget;
}

namespace Gui {
namespace Widgets {

/**
 * @brief Class for search in database
 * @author Antoine de Roquemaurel
 */
class searchWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief searchWidget::searchWidget Construct a search widget
     * @param parent The QWidget parent
     */
    explicit searchWidget(QWidget *parent = 0);

    ~searchWidget();

    /**
     * @brief searchWidget::getCurrentCustomerId
     * Return the id of the customer selected in the table
     * @return id of the current customer
     */
    int getCurrentCustomerId();


    /**
     * @brief searchWidget::isCustomerSelected Return TRUE if a customer is
     * selected, else FALSE
     * @return boolean
     */
    bool isCustomerSelected() const;

    /**
     * @brief searchWidget::selectCustomer Select the Customer with it <i>id</i>
     * @param id Customer ID
     */
    void selectCustomer(int id);

    /**
     * @brief searchWidget::getIdCustomer Return the Customer id of the Customer
     *  line selected
     * @return The Customer ID
     */
    int getIdCustomer() const;

    /**
     * @brief searchWidget::setIdCustomer Change the customer id by the new
     * <i>idCustomer</i>
     * @param idCustomer Customer id
     */
    void setIdCustomer(int idCustomer);

public slots:
    /**
     * @brief searchWidget::launch a search
     * @param toSearch The value to search
     */
    void search(QString toSearch);

    /**
     * @brief searchWidget::getCustomerData Return data on the customer selected
     *  in the QTableView and display this data (Firstname, Lastname, Company)
     */
    void getCustomerData();

signals:
    /**
     * @brief searchWidget::selectCustomer Signal that the Customer selected has
     * changed
     */
    void selectCustomer();

private:
    Ui::searchWidget *ui;               //!< User interface

    /**
     * @brief searchWidget::updateTable Update the table according the
     * <i>text</i> inputed
     * @param text Text inputed
     */
    void updateTable(QString text="");

    bool _isCustomerSelected;   //!< if Custumer is selected
    int _idCustomer;            //!< Customer ID
};
}
}
#endif // SEARCHWIDGET_H
