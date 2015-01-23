#include "billing.h"

Billing::Billing()
{
}

Billing::Billing(int id)
{
    hydrat(id);
}

void Billing::commit()
{
    // TODO implement me !

    if(_id == 0) {
        // TODO insert
    } else if(_toRemoved) {
        remove();
    } else {
        //  TODO update
    }
}

void Billing::hydrat(int id)
{
    _id = id;
    //Billing *quote = BillingDatabase::instance()->getBilling(id);

}

void Billing::remove()
{
    // TODO implement me !
}
QMap<Project*, QList<Contributory*>*> Billing::getContributories() const
{
    return _contributories;
}

void Billing::addContributories(Project* p, Contributory* c)
{
    _contributories.value(p)->push_back(c);
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





