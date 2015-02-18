#ifndef BILLINGDATABASE_H
#define BILLINGDATABASE_H

#include "models/billing.h"
#include "database.h"
#include "utils/log.h"
#include "utils/string.h"

using namespace Exceptions;
using namespace Utils;

namespace Databases {
/**
 * @author Cédric Rohaut @Oxynos
 * @brief The <b>BillingDatabase</b> class Billing (or Quote) table database
 * @see Database
 * @see Billing/Quote
 */
class BillingDatabase : public Database
{
public:
    /**
     * @brief BillingDatabase::getInstance Return an instance of
     * <b>BillingDatabase</b>
     * @see DbException
     * @return Instance of BillingDatabase
     */
    static BillingDatabase* instance()throw(DbException*);

    /**
     * @brief BillingDatabase::getCustomer get informations about the billing
     * identified by <i>pId</i>
     * @param pId billing id
     * @return the Billing
     */
    Models::Billing *getBilling(const int pId);

    /**
     * @brief BillingDatabase::getBillingsTable Return an item model of billings
     * for QTableView
     * @param pId the project id of the billings returned
     * @throw DbException
     * @return QStandardItemModel an item model for QTableView
     */
    QStandardItemModel* getBillingsTable(const int idProject) throw(DbException*);

    /**
     * @brief BillingDatabase::addBilling Add the billing <i>pBilling</i> to
     * the database
     * @return billing id
     */
    int addBilling(const Models::Billing&);

    /**
     * @brief BillingDatabase::updateCustomer Update informations about the
     * billing <i>pCustomer</i>
     */
    void updateBilling(const Models::Billing&);

    /**
     * @brief BillingDatabase::removeCustomer Remove the billing with the id
     * <i>pId</i>
     * @param pId billing id
     */
    void removeBilling(const int pId);
    /**
     * @brief BillingDatabase::addBillingProject Link a project, a billing and
     * a contributory in the table BillingProject
     * @param idProject Project id
     * @param idBilling Billing id
     * @param idContributory Contributory id
     */
    void addBillingProject(const int idProject, const int idBilling, const int idContributory);

    /**
     * @brief BillingDatabase::removeBillingProject remove a link between a project,
     * a billing and a contributory in the table BillingProject
     * @param idProject Project id
     * @param idBilling Billing id
     * @param idContributory Contributory id
     */
    void removeBillingProject(const int idProject, const int idBilling, const int idContributory);

    /**
     * @brief getMaxBillingNumber Get the last number of a billing
     * @return  The max number
     */
    int getMaxBillingNumber();

    /**
     * @brief getMaxQuoteNumber Get the last number of a quote
     * @return  The last number
     */
    int getMaxQuoteNumber();

private:
    static BillingDatabase* _instance;  //!< Singleton instance of BillingDatabase

    /**
     * @brief <b>BillingDatabase</b> is a singleton
     */
    BillingDatabase() throw(DbException*) ;
};
}
#endif // BILLINGDATABASE_H
