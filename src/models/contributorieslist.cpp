#include "contributorieslist.h"
#include "database/billingdatabase.h"
#include "database/ratedatabase.h"

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
        if(_insert) {
            RateDatabase::instance()->addRateProject(
                        it.key()->first->getId(),
                        _idBilling,
                        getRate(it.key()->first).getHourlyRate());
        } else {
            RateDatabase::instance()->updateRateProject(
                        it.key()->first->getId(),
                        _idBilling,
                        getRate(it.key()->first).getHourlyRate());
        }
        for(Contributory c : it.value()) {
            // Fill trinary legs… :)
            bool insertBillingProject = c.getId() == 0;
            c.commit();
            if(insertBillingProject) {
                BillingDatabase::instance()->addBillingProject(
                            c.getProject()->getId(), _idBilling, c.getId());
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
        key = new QPair<Project*, Models::Rate>(
                    contributory.getProject(),
                    Models::Rate(
                        _idBilling, contributory.getProject()->getId()));
        insert(key, QList<Contributory>());
    }

    (*this)[key].push_back(contributory);
}

void ContributoriesList::addProject(Project *p, Models::Rate rate)
{
    insert(new QPair<Project*, Models::Rate>(p, rate),
           QList<Models::Contributory>());
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

QList<Contributory>* ContributoriesList::getAllContributories()
{
    QList<Contributory>* ret = new QList<Contributory>;
    for(Project* p : getProjects()) {
        ret->append(getContributories(p));
    }
    return ret;
}

QList<Project*> ContributoriesList::getProjects()
{
    QList<Project*> projects;

    for(QPair<Project*, Models::Rate>* pair : keys()) {
        projects.append(pair->first);
    }
    return projects;
}

Models::Rate ContributoriesList::getRate(Models::Project* project)
{
    for(QPair<Project*, Models::Rate>* pair : keys()) {
        if(pair->first->getId() == project->getId()) {
            return pair->second;
        }
    }
    return Models::Rate();
}

QVariantList ContributoriesList::getDataMap()
{
    QVariantList contributories;
    QVariantHash project;
    QVariantList ret;
    QVariantHash buff;
    int i = 1;
    int j = 1;
    for(QPair<Project*,Models::Rate>* key : keys()) {
        project["nameproject"] = key->first->getName();
        project["descriptionproject"] = key->first->getDescription();
        project["indexproject"] = i++;
        for(Contributory c : getContributories(key->first)) {
            buff = c.getDataMap();
            buff["price"] = key->second.getDailyRate()
                            * buff["nbHours"].toDouble();
            buff["indexcontributory"] = j++;
            contributories << buff;
            buff.clear();
        }
        j = 1;
        project["contributories"] = contributories;
        contributories.clear();
        ret << project;
        project.clear();
    }

    return ret;
}

int ContributoriesList::getNbProjects()
{
    return count();
}

double ContributoriesList::getSumRate()
{
    double ret = 0.0;

    for(QPair<Project*,Models::Rate>* key : keys()) {
        for(Contributory c : getContributories(key->first)) {
            ret += c.getNbHours() * key->second.getDailyRate();
        }
    }

    return ret;
}

double ContributoriesList::getSumQuantity()
{
    double ret = 0.0;
    for(Contributory c : *getAllContributories()) {
        ret += c.getNbHours();
    }

    return ret;
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

void ContributoriesList::setAllIdContributories(int idContributory)
{
    for(QPair<Project*, Models::Rate>* pair : keys()) {
        for (Contributory &c : (*this)[pair])
            c.setId(idContributory);
    }
}

bool ContributoriesList::isInsert() const
{
    return _insert;
}

void ContributoriesList::setInsert(bool insert)
{
    _insert = insert;
}

}
