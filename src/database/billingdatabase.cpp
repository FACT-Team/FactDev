#include "database/billingdatabase.h"
#include "log.h"
#include "utils.h"

BillingDatabase::BillingDatabase() throw(DbException*)  : Database() {
    _instances << this;
}

// SINGLETON
BillingDatabase* BillingDatabase::_instance = 0;

BillingDatabase* BillingDatabase::instance()throw(DbException*)
{
    if (!_instance) {
        _instance = new BillingDatabase();
    }

    return _instance;
}

Billing* BillingDatabase::getBilling(const int pId) {
    QSqlQuery q;
    Billing* billing;

    /*q.prepare("SELECT * FROM Customer WHERE idCustomer = :pId");
    q.bindValue(":pId", pId);

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'ajouter le Customer",
            "BddCustomer::getCustomer",
            lastError(q),
            1.2);
    }

    if(q.first()) {
        customer = new Customer();
        customer->setId(value(q, "idCustomer").toInt());
    } else {
        customer = NULL;
    }*/

    return billing;
}


int BillingDatabase::addBilling(const Billing& pBilling) {
    QSqlQuery q;

    /*q.prepare(
        "INSERT INTO Customer "
        "(firstnameReferent, lastnameReferent, company, address, "
        "postalCode, city, country, email, mobilePhone, phone, fax)"
        " VALUES "
        "(:firstnameReferent, :lastnameReferent, :company, :address, "
        ":postalCode, :city, :country, :email, :mobilePhone, :phone, :fax)"
    );

    q.bindValue(":firstnameReferent", pCustomer.getFirstnameReferent());

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'ajouter le Customer",
            "BddCustomer::addCustomer",
            lastError(q),
            1.3);
    }

    return q.lastInsertId().toInt();*/
    return 0;
}

void BillingDatabase::updateBilling(const Billing& pBilling) {

    QSqlQuery q;
    /*q.prepare(
        "UPDATE Customer SET "
        "firstnameReferent=:firstname, lastnameReferent=:lastname,"
        "company=:company, address=:address, postalCode=:postalCode, city=:city,"
        "country=:country, email=:email, mobilePhone=:mobilePhone, phone=:phone,"
        "fax=:fax "
        "WHERE idCustomer=:idCustomer");

    q.bindValue(":idCustomer", pCustomer.getId());

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'éditer les informations du Customer",
            "BddCustomer::updateCustomer",
            lastError(q),
            1.4);
    }*/

}

void BillingDatabase::removeBilling(const int pId)
{
    QSqlQuery q;
    /*q.prepare(
        "DELETE FROM Customer "
        "WHERE idCustomer=:pId"
        );

    q.bindValue(":pId", pId);

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'éditer les informations du Customer",
            "BddCustomer::removeCustomer",
            lastError(q),
            1.5);
    }*/

}

