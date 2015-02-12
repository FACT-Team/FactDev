#ifndef BDDCUSTOMER_H
#define BDDCUSTOMER_H

#include "database/database.h"

#include "exceptions/dbexception.h"

#include "models/customer.h"

#include "utils/log.h"
#include "utils/string.h"

using namespace Exceptions;
using namespace Utils;

namespace Databases {
/** 
 * @author Antoine de Roquemaurel
 * @brief The <b>CustomerDatabase</b> class Customer table database
 * @see Database
 * @see Customer
 */
class CustomerDatabase : public Database
{
private:
    static CustomerDatabase* _instance;  //!< Singleton instance of CustomerDatabase

    /**
     * @brief <b>CustomerDatabase</b> is a singleton
     */
    CustomerDatabase() throw(DbException*) ;
public:
    /**
     * @brief CustomerDatabase::getInstance Return an instance of
     * <b>CustomerDatabase</b>
     * @see DbException
     * @return Instance of CustomerDatabase
     */
    static CustomerDatabase* instance()throw(DbException*);

    /**
     * @author Manantsoa Razanajatovo
     * @brief CustomerDatabase::getCustomersTable Return an item model of
     * customers for QTableView
     * @param filter Select only customers who are specified by <i>filter</i>
     * @throw DbException
     * @return QStandardItemModel an item model for QTableView
     */
    QStandardItemModel* getCustomersTable(QString filter="") throw(DbException*);

    /**
     * @author Manantsoa Razanajatovo & Cédric Rohaut (@Oxynos)
     * @brief CustomerDatabase::getTree Return an item model of customers
     * for QTree
     * @param filter Select only customers who are specified by <i>filter</i>
     * @throw DbException
     * @return QStandardItemModel an item model for QTreeView
     */
    QStandardItemModel *getTree(QString filter="") throw(DbException*);

    /**
     * @brief CustomerDatabase::getCustomer get informations about the customer
     * identified by <i>pId</i>
     * @param pId customer id
     * @return the Customer
     */
    QSharedPointer<Models::Customer> getCustomer(const int pId);

    /**
     * @brief CustomerDatabase::addCustomer Add the customer <i>pCustomer</i> to
     * the database
     * @return customer id
     */
    int addCustomer(const Models::Customer&);

    /**
     * @brief CustomerDatabase::updateCustomer Update informations about the
     * customer <i>pCustomer</i>
     */
    void updateCustomer(const Models::Customer&);

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

    QStandardItem *getItemRoot();
    QStandardItem *getItemCustomer(QSqlQuery q1);
    QStandardItem *getItemProject(QSqlQuery q2);
    QStandardItem *getItemBillQuote(QSqlQuery q3);

};
}
#endif // BDDCUSTOMER_H
