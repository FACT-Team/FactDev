#ifndef BDDPATIENT_H
#define BDDPATIENT_H

#include "database/database.h"
#include "exceptions/dbexception.h"
#include "models/customer.h"

/**
 * @brief The <b>CustomerDatabase</b> class Customer table database
 */
class CustomerDatabase : public Database
{
private:
    static CustomerDatabase* _instance;

    /**
     * @brief <b>CustomerDatabase</b> is a singleton
     */
    CustomerDatabase() throw(DbException*) ;
public:
    /**
     * @brief CustomerDatabase::getInstance Return an instance of
     * <b>CustomerDatabase</b>
     * @return Instance of CustomerDatabase
     */
    static CustomerDatabase* instance()throw(DbException*);

    /**
     * @brief CustomerDatabase::getCustomersTable Return an item model of
     * customers for QTableView
     * @param filter Select only customers who are specified by <i>filter</i>
     * @return QStandardItemModel an item model for QTableView
     */
    QStandardItemModel* getCustomersTable(QString filter="") throw(DbException*);

    /**
     * @brief CustomerDatabase::getCustomersTree Return an item model of
     * customers for QTree
     * @param filter Select only customers who are specified by <i>filter</i>
     * @return QStandardItemModel an item model for QTableView
     */
    QStandardItemModel *getCustomersTree(QString filter="") throw(DbException*);

    /**
     * @brief CustomerDatabase::getCustomer get informations about the customer
     * identified by <i>pId</i>
     * @param pId customer id

     * @return the Customer
     */
    Customer *getCustomer(const int pId);

    /**
     * @brief CustomerDatabase::addCustomer Add the customer <i>pCustomer</i> to
     * the database
     * @return customer id
     */
    int addCustomer(const Customer&);

    /**
     * @brief CustomerDatabase::updateCustomer Update informations about the
     * customer <i>pCustomer</i>
     */
    void updateCustomer(const Customer&);

    /**
     * @brief CustomerDatabase::removeCustomer Remove the customer with the id
     * <i>pId</i>
     * @param pId customer id
     */
    void removeCustomer(const int pId);

    /**
     * @brief CustomerDatabase::getNbCustomers Return the number of customers
     * existing
     * @return number of customers
     */
    int getNbCustomers();

};

#endif // BDDPATIENT_H
