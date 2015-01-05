#ifndef BDDPATIENT_H
#define BDDPATIENT_H
#include "database/database.h"
#include "exceptions/dbexception.h"
#include "models/client.h"

class ClientDatabase : public Bdd
{
private:
    static ClientDatabase* _instance;
    ClientDatabase()throw(DbException*) ;
public:
    static ClientDatabase* getInstance()throw(DbException*);

    QStandardItemModel* getClientsTable() throw(DbException*);
    QStandardItemModel* getClientList(QString pSearch, bool);
    Client getClient(const int pId);
    int addClient(const Patient&);
    void updateClient(const Patient&);
    int getNbClients();
    int getNbWomen();
    int getNbMen();
    int getNbUsageData();
};

#endif // BDDPATIENT_H
