#ifndef BDDCUSTOMER_H
#define BDDCUSTOMER_H

#include <QPixmap>
#include <QBuffer>
#include "database/database.h"
#include "database/billingdatabase.h"
#include "exceptions/dbexception.h"
#include "models/customer.h"
#include "models/billing.h"
#include "utils/log.h"
#include "utils/string.h"
#include "gui/widgets/widgetsmodels/customerstablemodel.h"

using namespace Exceptions;
using namespace Utils;
using namespace Gui::Widgets;

namespace Databases {
/** 
 * @author Antoine de Roquemaurel
 * @author Manantsoa Razanajatovo
 * @author Florent Berbie
 * @author @Oxynos
 * @brief The <b>CustomerDatabase</b> class Customer table database
 * @see Database
 * @see Customer
 */
class CustomerDatabase : public Database
{

public:
    /**
     * @brief CustomerDatabase::instance Return an instance of
     * <b>CustomerDatabase</b>
     * @see DbException
     * @return Instance of CustomerDatabase
     */
    static CustomerDatabase* instance()throw(DbException*);

    /**
     * @brief CustomerDatabase::getCustomersTable Return an item model of
     * customers for QTableView
     * @param filter Select only customers who are specified by <i>filter</i>
     * @throw DbException
     * @return QStandardItemModel an item model for QTableView
     */
    WdgModels::CustomersTableModel* getCustomersTable(QString filter="")
        throw(DbException*);


    /**
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
    int addCustomer(const Models::Customer &);

    /**
     * @brief CustomerDatabase::updateCustomer Update informations about the
     * customer <i>pCustomer</i>
     */
    void updateCustomer(Customer &);

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

    /**
     * @brief CustomerDatabase::getItemRoot Return the first item
     * for the QStandardItemModel
     * @return QStandardItem an item for QTree (level/depth 0)
     */
    QStandardItem *getItemRoot();

    /**
     * @brief CustomerDatabase::getItemCustomer Return the customer item
     * for the QStandardItemModel
     * @param q1 the row of the sql query for customers
     * @return QStandardItem an item for QTree (level/depth 1)
     */
    QStandardItem *getItemCustomer(QSqlQuery q1);
    /**
     * @brief CustomerDatabase::getItemProject Return the project item
     * for the QStandardItemModel
     * @param q2 the row of the sql query for projects
     * @return QStandardItem an item for QTree (level/depth 2)
     */
    QStandardItem *getItemProject(QSqlQuery q2);

    /**
     * @brief CustomerDatabase::getCustomer Add the element of the <i>q</i>
     * request and return their
     * @param q SQL request
     * @return a customer formed according to QSharedPointer
     */
    QSharedPointer<Models::Customer> getCustomer(QSqlQuery &q);

    /**
     * @brief CustomerDatabase::updateCustomer Update customer data according to
     *  the request <i>q</i>
     * @param q SQL request
     */
    void updateCustomer(QSqlQuery &q, Customer &pCustomer);

    /**
     * @brief CustomerDatabase::getCustomerImage Return a Customer image
     * @param pId Customer id
     * @return Customer image
     */
    QPixmap getCustomerImage(const int pId);

    /**
     * @brief CustomerDatabase::setCustomerImage Change the image of the
     * customer <i>pCustomer</i>
     * @param pCustomer Customer
     */
    void setCustomerImage(const Models::Customer &pCustomer);

private:
    //!< Singleton instance of CustomerDatabase
    static CustomerDatabase* _instance;

    /**
     * @brief <b>CustomerDatabase</b> is a singleton
     */
    CustomerDatabase() throw(DbException*) ;
};
}
#endif // BDDCUSTOMER_H
