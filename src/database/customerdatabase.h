#ifndef BDDPATIENT_H
#define BDDPATIENT_H
#include "database/database.h"
#include "exceptions/dbexception.h"
#include "models/customer.h"

class CustomerDatabase : public Database
{
private:
    static CustomerDatabase* _instance;
    CustomerDatabase()throw(DbException*) ;
public:
    static CustomerDatabase* getInstance()throw(DbException*);

    QStandardItemModel* getCustomersTable() throw(DbException*);
    QStandardItemModel* getCustomerList(QString pSearch, bool);
    Customer getCustomer(const int pId);
    int addCustomer(const Customer&);
    void updateCustomer(const Customer&);
    int getNbCustomers();
    int getNbWomen();
    int getNbMen();
    int getNbUsageData();
};

#endif // BDDPATIENT_H
