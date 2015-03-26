#ifndef CONTRIBUTORIESLIST_H
#define CONTRIBUTORIESLIST_H

#include <QMap>
#include "models/project.h"
#include "models/contributory.h"
#include "models/rate.h"
#include "models/user.h"
namespace Models {
/**
 * @author Antoine de Roquemaurel
 * @brief The ContributoriesList class List of contributories
 */
class ContributoriesList
        : private QMap<QPair<Project*,Models::Rate>*,QList<Contributory> >
{
public:
    /**
     * @brief ContributoriesList::ContributoriesList Construct a
     * ContributoriesList
     */
    ContributoriesList();
    ~ContributoriesList();

    /**
     * @brief ContributoriesList::commit Update or insert data into the database
     */
    virtual void commit();

    /**
     * @brief ContributoriesList::addContributory Add a new <i>contributory</i>
     * @param contributory Contributory to add
     */
    void addContributory(Models::Contributory& contributory);

    /**
     * @brief ContributoriesList::addProject Add a Project <i>p</i> and it
     * <i>rate</i>
     * @param p Project to add
     * @param rate Rate of the project
     */
    void addProject(Project* p, Models::Rate rate);

    /**
     * @brief ContributoriesList::getContributories Return a list of
     * Contributories for the Project <i>p</i>
     * @param p Project
     * @return List of Contributories for a project
     */
    QList<Contributory> &getContributories(Project* p);

    /**
     * @brief ContributoriesList::getIdBilling Return the Billing ID
     * @return Billing id
     */
    int getIdBilling() const;

    /**
     * @brief ContributoriesList::setIdBilling Change the Billing id by the new
     * <i>idBilling</i>
     * @param idBilling Billind id
     */
    void setIdBilling(int idBilling);

    /**
     * @brief ContributoriesList::setAllIdContributories Change all
     * Contributory id with the same id
     * @param idContributory the new Contributory id
     */
    void setAllIdContributories(int idContributory);

    /**
     * @brief ContributoriesList::isInsert Return TRUE if an element is
     * inserting else FALSE
     * @return boolean
     */
    bool isInsert() const;

    /**
     * @brief ContributoriesList::setInsert Change the state of insertion
     * @param insert Boolean
     */
    void setInsert(bool insert);

    /**
     * @brief ContributoriesList::getNbProjects Return the number of projects
     * @return Count number of project
     */
    int getNbProjects();

    /**
     * @brief ContributoriesList::getSumRate Return the sum of the
     * contributories rates
     * @return Sum of contributories rates
     */
    double getSumRate();

    /**
     * @brief ContributoriesList::getSumQuantity Return the sum of quantity
     * (number of hours) of the Contributories
     * @return sum of quantity
     */
    double getSumQuantity();

    /**
     * @brief ContributoriesList::getCustomer Return the Customers linked to
     * theses contributories
     * @return Customer
     */
    QSharedPointer<Customer> getCustomer();

    /**
     * @brief ContributoriesList::getProjects List of Projects
     * @return List of Projects
     */
    QList<Project *> getProjects();

    /**
     * @brief ContributoriesList::getAllContributories List of all
     * contributories (all contributories from all projects)
     * @return List of all contributories
     */
    QList<Contributory> *getAllContributories();

    /**
     * @brief ContributoriesList::getRate
     * @param project
     * @return
     */
    Models::Rate getRate(Models::Project *project);

    /**
     * @brief ContributoriesList::getDataMap Return a list of Billing and it
     * value linked which indicates if it is inserting or not
     * @return List of billing and value linked
     */
    QVariantList getDataMap();

private:
    int _idBilling; //!< Billing ID
    bool _insert;   //!< an element is inserted
};
}
#endif // CONTRIBUTORIESLIST_H
