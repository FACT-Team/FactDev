#ifndef BILLINGDATABASE_H
#define BILLINGDATABASE_H

#include "models/billing.h"
#include "database.h"
#include "utils/log.h"
#include "utils/string.h"
#include "gui/widgets/widgetsmodels/billingstablemodel.h"

using namespace Exceptions;
using namespace Utils;
using namespace Gui::Widgets;

namespace Databases {
/**
 * @author @Oxynos
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
    static BillingDatabase* instance();

    /**
     * @brief BillingDatabase::getBilling get informations about the billing
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
    WdgModels::BillingsTableModel *getBillingsTable(const int idProject);

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
    void addBillingProject(
            const int idProject, const int idBilling, const int idContributory);

    /**
     * @brief BillingDatabase::isBillingPaid Return TRUE if the id <i>pId</i>
     * correspond to a Billing and not quote (isBilling = 1) and if this billing
     *  is paid (isPaid = 1) else return FALSE.
     * @param pId Billing id
     * @return TRUE if billing is paid
     */
    bool isBillingPaid(const int pId);

    /**
     * @brief BillingDatabase::removeBillingProject remove a link between a
     * project, a billing and a contributory in the table BillingProject
     * @param idProject Project id
     * @param idBilling Billing id
     * @param idContributory Contributory id
     */
    void removeBillingProject(
            const int idProject, const int idBilling, const int idContributory);

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

    /**
     * @brief BillingDatabase::getMaxBillingNumberOfCustomer Get the last number
     * of a <b>Customer</b>'s Billing
     * @param idCustomer Customer id
     * @return the last number of the <b>Customer</b>'s Billing
     */
    int getMaxBillingNumberOfCustomer(const int idCustomer);

    /**
     * @brief BillingDatabase::getMaxQuoteNumberOfCustomer Get the last number
     * of a <b>Customer</b>'s quote
     * @param idCustomer Customer id
     * @return the last number of the <b>Customer</b>'s quote
     */
    int getMaxQuoteNumberOfCustomer(const int idCustomer);

    /**
     * @brief BillingDatabase::getBilling Add the element of the <i>q</i>
     * request and return their
     * @param q SQL request
     * @return a billing formed according to QSharedPointer
     */
    QSharedPointer<Models::Billing> getBilling(QSqlQuery &q);

    /**
     * @brief BillingDatabase::getAllBillingsOfProject Return a map with the
     * project id as key linked to the billing
     * @return Map with projects and Billing
     */
    QMap<Project *, Billing *> getAllBillingsOfProject();

    /**
     * @brief Get the bills between <i>begin</i> and <i>end</i> dates
     * @param begin
     * @param end
     * @return the list of <b>Bills</b>
     */
    QList<Billing> getBillsBetweenDates(QDate begin, QDate end);

    /**
     * @brief Get the bills
     * @param projectId Get the specified project bills
     * @return The list of bills
     */
    QList<Billing> getBills(const int projectId = 0);

    /**
     * @brief Get the bills paid
     * @param projectId Get the specified project bills paid
     * @return The list of bills paid
     */
    QList<Billing> getBillsPaid(const int projectId = 0);

    /**
     * @brief Get the number of bills
     * @param customerId If customerId isn't specified or if it's not valid,
     * get all bills else get the specified customer bills
     * @return Number of bills in the database for all or for a customer
     */
    int getNbBills(const int customerId = 0);

    /**
     * @brief Get the number of bills paid
     * @param customerId If customerId isn't specified if it's not valid,
     * get all bills paid else get the specified customer bills paid
     * @return Number of bills paid in the database for all or for a customer
     */
    int getNbBillsPaid(const int customerId = 0);

    /**
     * @brief Get the number of quotes
     * @param customerId If customerId isn't specified or if it's not valid,
     * get all quotes else get the specified customer quotes
     * @return Number of quotes in the database for all or for a customer
     */
    int getNbQuotes(const int customerId = 0);

    /**
     * @brief Get the number of documents
     * @param customerId If customerId isn't specified or if if it's not valid,
     * get all documents else get the specified customer documents
     * @return Number of quotes in the database for all or for a customer
     */
    int getNbDocs(const int customerId  = 0);

private:
    static BillingDatabase* _instance;//!< Singleton instance of BillingDatabase

    /**
     * @brief <b>BillingDatabase</b> is a singleton
     */
    BillingDatabase();
};
}
#endif // BILLINGDATABASE_H
