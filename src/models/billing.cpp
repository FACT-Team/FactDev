#include "billing.h"

#include "database/billingdatabase.h"

using namespace Databases;

namespace Models {
Billing::Billing()
{
    // TODO :
    // add enum for quote or billing, passed in constructor
    // If quote, line behind, else getMaxBillingNumber.
    _number = BillingDatabase::instance()->getMaxQuoteNumber() + 1;
    _toRemoved = false;
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
    Database::Database::instance()->openTransaction();
    bool insert = _id == 0;
    if(insert) {
        _id = BillingDatabase::instance()->addBilling(*this);
    } else if(_toRemoved){
        remove();
    } else {
        BillingDatabase::instance()->updateBilling(*this);
    }
    _contributories.setIdBilling(_id);
    _contributories.setInsert(insert);
    _contributories.commit();
    Database::Database::instance()->closeTransaction();
}

void Billing::hydrat(int id)
{
    _id = id;
    Billing *quote = BillingDatabase::instance()->getBilling(id);
    _title = quote->getTitle();
    _isBilling = quote->isBilling();
    _description = quote->getDescription();
    _number = quote->getNumber();
    _date = quote ->getDate();
    _toRemoved = false;
    _contributories = ContributoryDatabase::instance()->getContributoriesByBilling(_id);
}

void Billing::remove()
{
    BillingDatabase::instance()->removeBilling(_id);
}

QVariantHash Billing::getDataMap()
{
    QVariantHash data;
    QVariantHash billing;
    billing["no"] = _number;
    billing["type"] = _isBilling ? "Facture" : "Devis";
    billing["title"] = _title;
    billing["description"] = _description;
    billing["date"] = _date.toString("dddd d MMMM yyyy");
// TODO daily rate !
    data["user"]  = Models::User(1).getDataMap();
    data["customer"] = _contributories.getCustomer()->getDataMap();
    data["billing"] = billing;//

    QVariantList table;
    QVariantHash project;
    QVariantList contributories;
    for(Project* p : _contributories.getProjects()) {
        project["nameproject"] = p->getName();

        for(Contributory c : _contributories.getContributories(p)) {
            contributories << c.getDataMap();
        }
        project["contributories"] = contributories;
        contributories.clear();
        table << project;
        project.clear();
    }

    data["table"] = table;

    return data;
}

void Billing::generateTex()
{
    Generator g(":/tpl/billingtpl");
    g.generate(getDataMap(), "/tmp/test.tex");
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

void Billing::setContributories(const ContributoriesList &contributories)
{
    _contributories = contributories;
}


ContributoriesList& Billing::getContributories()
{
    return _contributories;
}

void Billing::addContributory(Contributory& c)
{
    _contributories.addContributory(c);
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

}
