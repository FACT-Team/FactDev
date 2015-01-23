#include "project.h"
#include "database/projectdatabase.h"
Project::Project()
{
}

Project::Project(int id)
{
    _id = id;
}

void Project::commit() {
    if(_id == 0) {
        _id = ProjectDatabase::instance()->addProject(*this);
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

QDate Project::getBeginDate()
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
Customer* Project::getCustomer() const
{
    return _customer;
}

void Project::setCustomer(Customer* customer)
{
    _customer = customer;
}




