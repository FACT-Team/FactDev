#ifndef CONTRIBUTORIESLIST_H
#define CONTRIBUTORIESLIST_H

#include <QMap>
#include "models/project.h"
#include "models/contributory.h"


namespace Models {
class ContributoriesList : public QMap<Project*,QList<Contributory> >
{
public:
    ContributoriesList();
    ~ContributoriesList();

    /**
     * @brief commit Update or insert data into the database
     */
    virtual void commit();

    void addContributory(Models::Contributory& contributory);
    void addProject(Project* p);

    int getIdBilling() const;
    void setIdBilling(int getIdBilling);

    bool getInsert() const;
    void setInsert(bool getInsert);

private:
    int _idBilling;
    bool _insert;
};
}
#endif // CONTRIBUTORIESLIST_H
