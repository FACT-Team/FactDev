#include "billing.h"

#include "database/billingdatabase.h"

Billing::Billing()
{
}

Billing::Billing(int id)
{
    hydrat(id);
}

Billing::~Billing()
{
//    auto end = _contributories.cend();
//    for (auto it = _contributories.cbegin(); it != end; ++it) {
//        it.value().reset;
//    }
}

void Billing::commit()
{
    Database::instance()->openTransaction();
    bool insert = _id == 0;
    if(insert) {
        _id = BillingDatabase::instance()->addBilling(*this);
    } else if(_toRemoved){
        remove();
    } else {
        BillingDatabase::instance()->updateBilling(*this);
    }

    // Commits contributories and projects
    auto end = _contributories.cend();
    for (auto it = _contributories.cbegin(); it != end; ++it) {
        ((Project*)(it.key()))->commit();
        for(Contributory c : it.value()) {
            c.commit();

            // Fill trinary legs… :)
            if(insert) {
                BillingDatabase::instance()->addBillingProject(((Project*)it.key())->getId(),
                                                                _id,
                                                               c.getId());
            }
        }
    }
    Database::instance()->closeTransaction();
}

void Billing::hydrat(int id)
{
    _id = id;
    Billing *quote = BillingDatabase::instance()->getBilling(id);
    _title = quote->getTitle();
    _description = quote->getDescription();
    _number = quote->getNumber();
    _date = quote ->getDate();
    _contributories = ContributoryDatabase::instance()->getContributoriesByBilling(_id);
}

void Billing::remove()
{
    BillingDatabase::instance()->removeBilling(_id);
}

bool Billing::operator ==(const Billing &b)
{
    return (getDate() == b.getDate() &&
            getDescription() == b.getDescription() &&
            getNumber() == b.getNumber() &&
            getTitle() == b.getTitle());
}

bool Billing::operator !=(const Billing &b)
{
    return !(*this == b);
}

QMap<Project*, QList<Contributory>> Billing::getContributories() const
{
    return _contributories;
}

void Billing::setContributories(QMap<Project*, QList<Contributory>> contributories)
{
    _contributories = contributories;
}

void Billing::addContributory(Contributory& c)
{
    if(_contributories.contains(c.getProject())) {
        _contributories.insert(c.getProject(), QList<Contributory>());
    }
    _contributories[c.getProject()].push_back(c);
}

QString Billing::getTitle() const
{
    return _title;
}

void Billing::setTitle(const QString &title)
{
    _title = title;
}

QString Billing::getDescription() const
{
    return _description;
}

void Billing::setDescription(const QString &description)
{
    _description = description;
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

