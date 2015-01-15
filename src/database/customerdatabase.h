#ifndef BDDPATIENT_H
#define BDDPATIENT_H
#include "database/database.h"
#include "exceptions/dbexception.h"
#include "models/customer.h"

class CustomerDatabase : public Database
{
private:
    static CustomerDatabase* _instance;
    CustomerDatabase() throw(DbException*) ;
public:
    static CustomerDatabase* instance()throw(DbException*);

    QStandardItemModel* getCustomersTable(QString filter="") throw(DbException*);
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
