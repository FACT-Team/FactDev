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
    // Commits contributories
    for (auto it = cbegin(); it != cend(); ++it) {
        for(Contributory c : it.value()) {
            c.commit();

            // Fill trinary legs… :)
            if(_insert) {
                BillingDatabase::instance()->addBillingProject(c.getProject()->getId(),
                                                                _idBilling,
                                                               c.getId());
            }

        }
    }
}

void ContributoriesList::addContributory(Contributory &contributory)
{
    bool toInsert = true;
    QPair<Project*, Models::Rate>* key;
    for(QPair<Project*, Models::Rate>* p : keys()) {
        if(p->first->getId() == contributory.getProject()->getId()) {
            toInsert = false;
            key = p;
            break;
        }
    }
    if(toInsert) {
        key = new QPair<Project*, Models::Rate>(contributory.getProject(), Models::Rate());
        insert(key, QList<Contributory>());
    }

    (*this)[key].push_back(contributory);
}

void ContributoriesList::addProject(Project *p, Models::Rate rate)
{
    insert(new QPair<Project*, Models::Rate>(p, rate), QList<Models::Contributory>());
}

QList<Contributory>& ContributoriesList::getContributories(Project *p)
{
    QPair<Project*, Models::Rate>* key;
    for(QPair<Project*, Models::Rate>* pair : keys()) {
        if(pair->first == p || pair->first->getId() == p->getId()) {
            key = pair;
            break;
        }
    }

    return (*this)[key];
}

QList<Contributory>* ContributoriesList::getAllContributories() {
    QList<Contributory>* ret = new QList<Contributory>;
    for(Project* p : getProjects()) {
        ret->append(getContributories(p));
    }
    return ret;
}

QList<Project*> ContributoriesList::getProjects() {
    QList<Project*> projects;

    for(QPair<Project*, Models::Rate>* pair : keys()) {
        projects.append(pair->first);
    }
    return projects;
}

int ContributoriesList::getNbProjects() {
    return count();
}

QSharedPointer<Customer> ContributoriesList::getCustomer()
{
    return getProjects().first()->getCustomer();
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
