#include "project.h"

#include "database/projectdatabase.h"
using namespace Databases;

namespace Models {
const double Project::LEGAL_RATE = 9.61;
const int Project::NB_DAILY_HOURS = 7;

Project::Project()
{
    _id = 0;
    _toRemoved = false;
}

Project::Project(QString name)
{
    _id = 0;
    _toRemoved = false;
    _name = name;
}

Project::Project(int id)
{
    _id = id;
    _toRemoved = false;
    hydrat(id);
}

Project::~Project()
{
    _customer.reset();
}

void Project::commit() {
    if(_id == 0) {
        _id = ProjectDatabase::instance()->addProject(*this);
    } else if(_toRemoved) {
        remove();
    } else {
        ProjectDatabase::instance()->updateProject(*this);
    }
}

void Project::hydrat(int id)
{
    Project* p = ProjectDatabase::instance()->getProject(id);
    _id = id;
    _name = p->getName();
    _description = p->getDescription();
    _beginDate = p->getBeginDate();
    _endDate = p->getEndDate();
    _dailyRate = p->getDailyRate();
    _customer = p->getCustomer();
}

void Project::remove()
{
    ProjectDatabase::instance()->removeProject(_id);
}

QVariantHash Project::getDataMap()
{

}

QString Project::getName() const
{
    return _name;
}

void Project::setName(const QString &name)
{
    _name = name;
}
QString Project::getDescription() const
{
    return _description;
}

void Project::setDescription(const QString &description)
{
    _description = description;
}

QDate Project::getBeginDate() const
{
    return _beginDate;
}

void Project::setBeginDate(QDate beginDate)
{
    _beginDate = beginDate;
}

QDate Project::getEndDate()
{
    return _endDate;
}

void Project::setEndDate(QDate endDate)
{
    _endDate = endDate;
}

double Project::getDailyRate() const
{
    return _dailyRate;
}

void Project::setDailyRate(double dailyRate)
{
    _dailyRate = dailyRate;
}
QSharedPointer<Customer> Project::getCustomer() const
{
    return _customer;
}

void Project::setCustomer(QSharedPointer<Customer> customer)
{
    _customer = customer;
}

}
