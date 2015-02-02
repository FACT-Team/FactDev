#ifndef CONTRIBUTORYDATABASE_H
#define CONTRIBUTORYDATABASE_H

#include "models/contributory.h"
#include "database.h"

/**
 * @author Cédric Rohaut @Oxynos
 * @brief The <b>ContributoryDatabase</b> class Contributory (or Quote) table database
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
     * @brief ContributoryDatabase::getCustomer get informations about the Contributory
     * identified by <i>pId</i>
     * @param idContributory Contributory id
     * @return the Contributory
     */
    Contributory *getContributory(const int idContributory);

    QMap<Project*,QList<Contributory>*> getContributoriesByBilling(const int idBilling);

    /**
     * @brief ContributoryDatabase::addContributory Add the Contributory <i>pContributory</i> to
     * the database
     * @return Contributory id
     */
    int addContributory(const Contributory&);

    /**
     * @brief ContributoryDatabase::updateCustomer Update informations about the
     * Contributory <i>pCustomer</i>
     */
    void updateContributory(const Contributory&);

    /**
     * @brief ContributoryDatabase::removeCustomer Remove the Contributory with the id
     * <i>pId</i>
     * @param pId Contributory id
     */
    void removeContributory(const int pId);

    Contributory *getContributory(QSqlQuery &q);
private:
    static ContributoryDatabase* _instance;  //!< Singleton instance of ContributoryDatabase

    /**
     * @brief <b>ContributoryDatabase</b> is a singleton
     */
    ContributoryDatabase() throw(DbException*) ;

};

#endif // CONTRIBUTORYDATABASE_H
