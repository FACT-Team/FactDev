#ifndef CONTRIBUTORYDATABASE_H
#define CONTRIBUTORYDATABASE_H

#include "database.h"
#include "database/projectdatabase.h"

#include "models/contributory.h"
#include "models/contributorieslist.h"

#include "utils/log.h"
#include "utils/string.h"

using namespace Exceptions;
using namespace Utils;

namespace Databases {

/**
 * @author @Oxynos
 * @brief The <b>ContributoryDatabase</b> class Contributory (or Quote) table
 * database
 * @see Database
 * @see Contributory/Quote
 */
class ContributoryDatabase : public Database
{
public:
    /**
     * @brief ContributoryDatabase::getInstance Return an instance of
     * <b>ContributoryDatabase</b>
     * @see DbException
     * @return Instance of ContributoryDatabase
     */
    static ContributoryDatabase* instance()throw(DbException*);

    /**
     * @brief ContributoryDatabase::getCustomer get informations
     * about the Contributory identified by <i>pId</i>
     * @param idContributory Contributory id
     * @return the Contributory
     */
    Models::Contributory *getContributory(const int idContributory);

    /**
     * @brief ContributoryDatabase::getContributoriesByBilling get informations
     * about the Contributory identified by <i>Billing</i>
     * @param idBilling Contributory id
     * @return the Contributory
     */
    Models::ContributoriesList getContributoriesByBilling(const int billingId);

    /**
     * @brief ContributoryDatabase::addContributory
     * Add the Contributory <i>pContributory</i> to the database
     * @return Contributory id
     */
    int addContributory(const Models::Contributory&);

    /**
     * @brief ContributoryDatabase::updateCustomer Update informations about the
     * Contributory <i>pCustomer</i>
     */
    void updateContributory(const Models::Contributory&);

    /**
     * @brief ContributoryDatabase::removeCustomer Remove the Contributory
     * with the id <i>pId</i>
     * @param pId Contributory id
     */
    void removeContributory(const int pId);

    /**
     * @brief getContributory Obtain a contributory without new query
     * @param q The query to use
     * @return The contributory linked to q
     */
    Models::Contributory *getContributory(QSqlQuery &q);

    /**
     * @brief getContributory Get contributories list  by project and billing
     * @param billingId
     * @param projectId
     * @return The contributories list by project and billing
     */
    Models::ContributoriesList getContributoriesByBillingAndProject(
            const int billingId, const int projectId);


private:
    //!< Singleton instance of ContributoryDatabase
    static ContributoryDatabase* _instance;

    /**
     * @brief <b>ContributoryDatabase</b> is a singleton
     */
    ContributoryDatabase() throw(DbException*) ;

};
}
#endif // CONTRIBUTORYDATABASE_H
