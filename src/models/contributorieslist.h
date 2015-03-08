#ifndef CONTRIBUTORIESLIST_H
#define CONTRIBUTORIESLIST_H

#include <QMap>
#include "models/project.h"
#include "models/contributory.h"
#include "models/rate.h"

namespace Models {
class ContributoriesList : private QMap<QPair<Project*,Models::Rate>*,QList<Contributory> >
{
public:
    ContributoriesList();
    ~ContributoriesList();

    /**
     * @brief commit Update or insert data into the database
     */
    virtual void commit();

    void addContributory(Models::Contributory& contributory);
    void addProject(Project* p, Models::Rate rate);
    QList<Contributory> &getContributories(Project* p);
    int getIdBilling() const;
    void setIdBilling(int getIdBilling);
    /**
     * @brief ContributoriesList::setAllIdContributories Change all
     * Contributory id with the same id
     * @param idContributory the new Contributory id
     */
    void setAllIdContributories(int idContributory);

    bool getInsert() const;
    void setInsert(bool getInsert);

    int getNbProjects();
    double getSumRate();
    double getSumQuantity();

    QSharedPointer<Customer> getCustomer();
    QList<Project *> getProjects();
    QList<Contributory> *getAllContributories();
    Models::Rate getRate(Models::Project *project);

    QVariantList getDataMap();
private:
    int _idBilling;
    bool _insert;
};
}
#endif // CONTRIBUTORIESLIST_H
