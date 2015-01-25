#ifndef BILLINGDATABASE_H
#define BILLINGDATABASE_H

#include "models/billing.h"
#include "database.h"

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
    Billing *getBilling(const int pId);

    /**
     * @brief BillingDatabase::addBilling Add the billing <i>pBilling</i> to
     * the database
     * @return billing id
     */
    int addBilling(const Billing&);

    /**
     * @brief BillingDatabase::updateCustomer Update informations about the
     * billing <i>pCustomer</i>
     */
    void updateBilling(const Billing&);

    /**
     * @brief BillingDatabase::removeCustomer Remove the billing with the id
     * <i>pId</i>
     * @param pId billing id
     */
    void removeBilling(const int pId);

    void addBillingProject(const int idProject, const int idBilling, const int idContributory);
private:
    static BillingDatabase* _instance;  //!< Singleton instance of BillingDatabase

    /**
     * @brief <b>BillingDatabase</b> is a singleton
     */
    BillingDatabase() throw(DbException*) ;

};

#endif // BILLINGDATABASE_H
