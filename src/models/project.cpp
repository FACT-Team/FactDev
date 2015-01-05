#include "project.h"

Project::Project()
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
double Project::geDailyRate() const
{
    return _dailyRate;
}

void Project::setDailyRate(double dailyRate)
{
    _dailyRate = dailyRate;
}
int Project::getIdCustomer() const
{
    return _idCustomer;
}

void Project::setIdCustomer(int idCustomer)
{
    _idCustomer = idCustomer;
}




