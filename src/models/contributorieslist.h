#ifndef CONTRIBUTORIESLIST_H
#define CONTRIBUTORIESLIST_H

#include <QMap>
#include "models/project.h"
#include "models/contributory.h"
#include "models/rate.h"

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
     * @brief ContributoriesList::addContributory
     * @param contributory
     */
    void addContributory(Models::Contributory& contributory);

    /**
     * @brief ContributoriesList::addProject
     * @param p
     * @param rate
     */
    void addProject(Project* p, Models::Rate rate);

    /**
     * @brief ContributoriesList::getContributories
     * @param p
     * @return
     */
    QList<Contributory> &getContributories(Project* p);

    /**
     * @brief ContributoriesList::getIdBilling
     * @return
     */
    int getIdBilling() const;

    /**
     * @brief ContributoriesList::setIdBilling
     * @param idBilling
     */
    void setIdBilling(int idBilling);

    /**
     * @brief ContributoriesList::setAllIdContributories Change all
     * Contributory id with the same id
     * @param idContributory the new Contributory id
     */
    void setAllIdContributories(int idContributory);

    /**
     * @brief ContributoriesList::getInsert
     * @return
     */
    bool getInsert() const;

    /**
     * @brief ContributoriesList::setInsert
     * @param insert
     */
    void setInsert(bool insert);

    /**
     * @brief ContributoriesList::getNbProjects
     * @return
     */
    int getNbProjects();

    /**
     * @brief ContributoriesList::getSumRate
     * @return
     */
    double getSumRate();

    /**
     * @brief ContributoriesList::getSumQuantity
     * @return
     */
    double getSumQuantity();

    /**
     * @brief ContributoriesList::getCustomer
     * @return
     */
    QSharedPointer<Customer> getCustomer();

    /**
     * @brief ContributoriesList::getProjects
     * @return
     */
    QList<Project *> getProjects();

    /**
     * @brief ContributoriesList::getAllContributories
     * @return
     */
    QList<Contributory> *getAllContributories();

    /**
     * @brief ContributoriesList::getRate
     * @param project
     * @return
     */
    Models::Rate getRate(Models::Project *project);

    /**
     * @brief ContributoriesList::getDataMap
     * @return
     */
    QVariantList getDataMap();
private:
    int _idBilling;
    bool _insert;
};
}
#endif // CONTRIBUTORIESLIST_H
