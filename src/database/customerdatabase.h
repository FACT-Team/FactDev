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
    Customer getCustomer(const int pId);
    int addCustomer(const Customer&);
    void updateCustomer(const Customer&);
    void removeCustomer(const int pId);

    int getNbCustomers();
    int getNbWomen();
    int getNbMen();
    int getNbUsageData();
};

#endif // BDDPATIENT_H
