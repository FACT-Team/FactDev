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
    qDebug() << "test" << pId;
    q.prepare("SELECT * FROM Billing WHERE idBilling = :pId");
    q.bindValue(":pId", pId);

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'ajouter le/la devis/facture",
            "BddBilling::getBilling",
            lastError(q),
            1.2);
    }

    if(q.first()) {
        billing = new Billing();
        billing->setId(value(q, "idBilling").toInt());
        billing->setTitle(value(q, "title").toString());
    } else {
        billing = NULL;
    }

    return billing;
}


int BillingDatabase::addBilling(const Billing& pBilling) {
    QSqlQuery q;
    q.prepare(
        "INSERT INTO Billing "
        "(title, number, isBilling, date)"
        " VALUES "
        "(:title, :number, :isBilling, :date)"
    );

    q.bindValue(":title", pBilling.getTitle());
    q.bindValue(":number", pBilling.getNumber());
    q.bindValue(":isBilling", pBilling.isBilling());
    q.bindValue(":date", pBilling.getDate());

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'ajouter le Customer",
            "BddCustomer::addCustomer",
            lastError(q),
            1.3);
    }

    return q.lastInsertId().toInt();
}

void BillingDatabase::addBillingProject(const int idProject, const int idBilling, const int idContributory) {
    QSqlQuery q;
    q.prepare(
        "INSERT INTO BillingProject "
        "(idProject, idBilling, idContributory) VALUES "
        "(:idProject, :idBilling, :idContributory)"
    );
    q.bindValue(":idProject", idProject);
    q.bindValue(":idBilling", idBilling);
    q.bindValue(":idContributory", idContributory);
    if(!q.exec()) {
        throw new DbException(
            "Impossible d'ajouter le Customer",
            "BddCustomer::addCustomer",
            lastError(q),
            1.3);
    }

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

