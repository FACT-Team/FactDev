#ifndef BDDPATIENT_H
#define BDDPATIENT_H

#include "database/database.h"
#include "exceptions/dbexception.h"
#include "models/customer.h"

/**
 * @brief The CustomerDatabase class Customer table database
 */
class CustomerDatabase : public Database
{
private:
    static CustomerDatabase* _instance;

    /**
     * @brief CustomerDatabase is a singleton
     */
    CustomerDatabase() throw(DbException*) ;
public:
    /**
     * @brief CustomerDatabase::getInstance Return an instance of
     * CustomerDatabase
     * @return Instance of CustomerDatabase
     */
    static CustomerDatabase* instance()throw(DbException*);

    /**
     * @brief getCustomersTable Return an item model of customers for QTableView
     * @param filter Select only customers who are specified by 'filter'
     * @return QStandardItemModel an item model for QTableView
     */
    QStandardItemModel* getCustomersTable(QString filter="") throw(DbException*);

    /**
     * @brief getCustomersTree Return an item model of customers for QTree
     * @param filter Select only customers who are specified by 'filter'
     * @return QStandardItemModel an item model for QTableView
     */
    QStandardItemModel *getCustomersTree(QString filter="") throw(DbException*);

    /**
     * @brief getCustomer
     * @param pId customer id
     * get informations about the customer identified by 'pId'
     * @return the Customer
     */
    Customer *getCustomer(const int pId);

    /**
     * @brief addCustomer
     * add the customer 'pCustomer' to the database
     * @return customer id
     */
    int addCustomer(const Customer&);

    /**
     * @brief updateCustomer
     * update informations about the customer 'pCustomer'
     */
    void updateCustomer(const Customer&);

    /**
     * @brief removeCustomer
     * @param pId customer id
     * remove the customer with the id 'pId'
     */
    void removeCustomer(const int pId);

    /**
     * @brief getNbCustomers
     * Return the number of customers existing
     * @return number of customers
     */
    int getNbCustomers();

};

#endif // BDDPATIENT_H
