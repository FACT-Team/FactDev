#include "billing.h"

#include "database/billingdatabase.h"

using namespace Databases;

namespace Models {
Billing::Billing()
{
    _number = BillingDatabase::instance()->getMaxQuoteNumber() + 1;
    _isPaid = false;
    _toRemoved = false;
}

Billing::Billing(int id)
{
    hydrat(id);
}

Billing::~Billing()
{
}

void Billing::commit()
{
    Database::Database::instance()->openTransaction();
    bool insert = _id == 0;

    if(insert) {
        _id = BillingDatabase::instance()->addBilling(*this);
    } else if(_toRemoved) {
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
    _isPaid = quote->isPaid();
    _toRemoved = false;
    _contributories =
            ContributoryDatabase::instance()->getContributoriesByBilling(_id);
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
    data["user"]  = Models::User(1).getDataMap();
    data["customer"] = _contributories.getCustomer()->getDataMap();
    data["billing"] = billing;

    QVariantList table;
    QVariantHash project;
    for(Project* p : _contributories.getProjects()) {
        project["nameproject"] = p->getName();
        project["contributories"] = _contributories.getDataMap();

        table << project;
        project.clear();
    }
    data["totalRate"] = Utils::Double::round(getPrice(), 2);

    if(Utils::Double::round(getSumQuantity(), 2) < 1) {
        data["totalQuantity"] = Utils::Double::round(getSumQuantity(), 2) * User(1).getNbHoursPerDay();
        data["totalUnit"] = Unit(HOUR).toString(data["totalQuantity"].toDouble() < 1);
    } else {
        data["totalQuantity"] = Utils::Double::round(getSumQuantity(), 2);
        data["totalUnit"] = Unit(DAY).toString(data["totalQuantity"].toDouble() < 1);
    }


    data["table"] = _contributories.getDataMap();

    return data;
}

double Billing::getPrice(bool paied)
{
    return _contributories.getPrice(paied);
}

void Billing::generateTex()
{
    Generator::TexGenerator g(":/tpl/billingtpl");

    g.generate(getDataMap(), getPath()+".tex");
}

void Billing::generatePdf()
{
    generateTex();
    Generator::PdfGenerator g(User(1).getPdflatexPath());
    g.generate(getFolder(), getFilename());
}

QString Billing::getFolder() {
    QString fact;

    if (isBilling()) {
        fact = "Factures";
    } else {
        fact ="Devis";
    }

    return _contributories.getCustomer()->getPath() + "/" + fact;
}
QString Billing::getPath() {
    return getFolder()+"/"+getFilename();
}

QString Billing::getFilename()
{

    return QString::number(getNumber());
}

bool Billing::operator ==(const Billing &b)
{
    bool ret = (getDate() == b.getDate()
                && getDescription() == b.getDescription()
                && getNumber() == b.getNumber()
                && getTitle() == b.getTitle()
                );
    return ret;
}

bool Billing::operator !=(const Billing &b)
{
    return !(*this == b);
}

void Billing::setContributories(const ContributoriesList &contributories)
{
    _contributories = contributories;
}


bool Billing::operator <(const Billing &b) const
{
    return getDate() < b.getDate();
}

QStandardItem *Billing::getItem()
{
    QStandardItem *itemBillQuote =
            new QStandardItem(_date.toString("MM-yyyy")+ " " + _title);

    itemBillQuote->setIcon(QIcon(":icons/"+QString(_isBilling == 0 ? "quote" : "bill")));

    return itemBillQuote;

}
bool Billing::isPaid() const
{
    return _isPaid;
}

void Billing::setIsPaid(bool isPaid)
{
    _isPaid = isPaid;
}


ContributoriesList& Billing::getContributories()
{
    return _contributories;
}

void Billing::addContributory(Contributory& c)
{
    _contributories.addContributory(c);
}

double Billing::getSumQuantity()
{
    return _contributories.getSumQuantity();
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
