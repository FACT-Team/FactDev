#include "billing.h"

Billing::Billing()
{
}
QMap<Project, QList<Contributory> > Billing::getContributories() const
{
    return _contributories;
}

void Billing::setContributories(const QMap<Project, QList<Contributory> > &contributories)
{
    _contributories = contributories;
}

QMap<Project, QList<Contributory> > Billing::getContributories() const
{
    return getContributories;
}

void Billing::setContributories(const QMap<Project, QList<Contributory> > &value)
{
    getContributories = value;
}
QString Billing::getTitle() const
{
    return _title;
}

void Billing::setTitle(const QString &title)
{
    _title = title;
}
int Billing::getNumber() const
{
    return _number;
}

void Billing::setNumber(int number)
{
    _number = number;
}
bool Billing::isBilling() const
{
    return _isBilling;
}

void Billing::setIsBilling(bool isBilling)
{
    _isBilling = isBilling;
}
QDate Billing::getDate() const
{
    return _date;
}

void Billing::setDate(const QDate &date)
{
    _date = date;
}





