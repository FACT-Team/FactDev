#include "contributorieslist.h"
#include "database/billingdatabase.h"

using namespace Databases;

namespace Models {

ContributoriesList::ContributoriesList()
{
    _insert = true;
}

ContributoriesList::~ContributoriesList()
{

}

void ContributoriesList::commit()
{
    // Commits contributories and projects
    auto end = cend();
    for (auto it = cbegin(); it != end; ++it) {
        ((Project*)(it.key()))->commit();
        for(Contributory c : it.value()) {
            c.commit();

            // Fill trinary legs… :)
            if(_insert) {
                BillingDatabase::instance()->addBillingProject(((Project*)it.key())->getId(),
                                                                _idBilling,
                                                               c.getId());
            }

        }
    }
}

void ContributoriesList::addContributory(Contributory &contributory)
{
    bool toInsert = true;
    Project* project;
    if(!contains(contributory.getProject())) {
        for(Project* p : keys()) {
            if(p->getId() == contributory.getProject()->getId()) {
                toInsert = false;
                project = p;
                break;
            }
        }
        if(toInsert) {
            insert(contributory.getProject(), QList<Contributory>());
            project = contributory.getProject();
        }
    }
    (*this)[project].push_back(contributory);
}

void ContributoriesList::addProject(Project *p)
{
    insert(p, QList<Models::Contributory>());
}
int ContributoriesList::getIdBilling() const
{
    return _idBilling;
}

void ContributoriesList::setIdBilling(int idBilling)
{
    _idBilling = idBilling;
}
bool ContributoriesList::getInsert() const
{
    return _insert;
}

void ContributoriesList::setInsert(bool insert)
{
    _insert = insert;
}



}
