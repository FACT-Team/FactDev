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
        billing->setDescription(value(q,"description").toString());
        billing->setNumber(value(q,"number").toInt());
        billing->setDate(QDate::fromString(value(q,"date").toString(),"yyyy-MM-dd"));
        billing->setIsBilling(value(q,"isBilling").toBool());
        billing->setToRemoved(false);
    } else {
        billing = NULL;
    }

    return billing;
}

QStandardItemModel *BillingDatabase::getBillingsTable(const int idProject)
throw(DbException*)
{
    QSqlQuery q;
    QStandardItemModel* retour = new QStandardItemModel();

    retour->setColumnCount(5);
    retour->setHorizontalHeaderLabels(
                QStringList()
                << ("Id")
                << ("Titre")
                << ("Numéro")
                << ("Facture/Devis")
                << ("Date")
                );


    q.prepare(
             "SELECT b.idBilling,title,number,isBilling,date "
             "FROM Billing b, BillingProject bp "
             "WHERE idProject = :idproject "
             "AND b.idBilling = bp.idBilling");

    q.bindValue(":idproject",idProject);

    if(!q.exec()) {
        throw new DbException(
            "Impossible de récupérer les Billing",
            "BddCustomer::getBillingsTable",
            lastError(q),
            1.3);
    }

    while(q.next()) {
        QList<QStandardItem*> ligne;

        ligne << new QStandardItem(value(q,"idBilling").toString());
        ligne << new QStandardItem(value(q,"title").toString());
        ligne << new QStandardItem(value(q,"number").toString());
        ligne << new QStandardItem(value(q,"isBilling").toString());
        ligne << new QStandardItem(value(q,"date").toString());

        retour->appendRow(ligne);
    }

    return retour;
}


int BillingDatabase::addBilling(const Billing& pBilling) {
    QSqlQuery q;

    q.prepare(
        "INSERT INTO Billing "
        "(title, description, number, isBilling, date)"
        " VALUES "
        "(:title, :description, :number, :isBilling, :date)"
    );

    q.bindValue(":title", pBilling.getTitle());
    q.bindValue(":description", pBilling.getDescription());
    q.bindValue(":number", pBilling.getNumber());
    q.bindValue(":isBilling", pBilling.isBilling());
    q.bindValue(":date", pBilling.getDate());

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'ajouter le Billing",
            "BddBilling::addBilling",
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

