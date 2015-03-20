#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QString>
#include <QStandardItem>

#include "models/imodel.h"
#include "models/people.h"

namespace Models {
/**
 * @author Antoine de Roquemaurel
 * @author Florent Berbie
 * @brief The Customer class Customer
 */
class Customer : public People, public IModel
{
public:
    /**
     * @brief Customer::Customer Construct a Customer
     */
    Customer();
    /**
     * @brief Customer::Customer Constuct a Customer who is specidied by
     *  <i>id</i>
     * @param id Customer identify
     */
    Customer(int id);

    /**
     * @brief Customer::commit Update customer data on the database
     */
    void commit();

    /**
     * @brief Customer::hydrat Insert into database informations related to the
     *  Customer who is specified by <i>id</i>
     * @param id Customer identify
     */
    void hydrat(int id);

    /**
     * @brief Customer::remove Remove the current customer
     */
    void remove();

    /**
     * @brief getDataMap Get all data of model with a HashMap key/value
     * @return Model's data
     */
    QVariantHash getDataMap();

    /**
     * @brief Customer::getPath Return the path of the workspace for the current
     *  Customer
     * @return workspace path
     */
    QString getPath() const;

    /**
     * @brief Customer::getNameFolder Return the name of the current Customer's
     * folder in the workspace
     * @return name of the Customer's folder
     */
    QString getNameFolder() const;

    /**
     * @brief Customer::getTurnover Return the turnover of the customer
     * money that customer pay, revenue sales
     * @return turnover
     */
    double getTurnover() const;
private:
    double  _turnover;          //!< Turnover/revenue of the customer
};
}
#endif // CUSTOMER_H
