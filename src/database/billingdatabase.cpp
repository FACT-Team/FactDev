#include "database/billingdatabase.h"

namespace Databases {

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

Models::Billing* BillingDatabase::getBilling(const int pId) {
    QSqlQuery q;
    Models::Billing* billing;
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
        billing = new Models::Billing();
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

WdgModels::BillingsTableModel* BillingDatabase::getBillingsTable(
        const int idProject) throw(DbException*)
{
    WdgModels::BillingsTableModel* ret = new WdgModels::BillingsTableModel();
    QSqlQuery q;
    q.prepare(
             "SELECT DISTINCT b.idBilling, title, description, number, "
             "isBilling, date "
             "FROM Billing b, BillingProject bp "
             "WHERE idProject = :idproject "
             "AND b.idBilling = bp.idBilling ORDER BY date DESC");

    q.bindValue(":idproject",idProject);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible de récupérer les Factures/Devis",
                    "BddCustomer::getBillingsTable",
                    lastError(q),
                    1.3);
    }

    while(q.next()) {
        ret->append(*getBilling(q));
    }

    return ret;
}


int BillingDatabase::addBilling(const Models::Billing& pBilling) {
    QSqlQuery q;

    q.prepare(  "INSERT INTO Billing "
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
                    "Impossible d'ajouter la liaison dans BillingProject",
                    "BddCustomer::addBillingProject",
                    lastError(q),
                    1.3);
    }

}

void BillingDatabase::removeBillingProject(const int idProject, const int idBilling, const int idContributory)
{
    QSqlQuery q;
    QString project;

    (idProject == 0) ? project="" : project="idProject= "+ QString::number(idProject) +" AND ";

    q.prepare(
                "DELETE FROM BillingProject "
                "WHERE "+project+
                "idBilling=:idBilling "
                "AND idContributory=:idContributory");

    q.bindValue(":idBilling", idBilling);
    q.bindValue(":idContributory",idContributory);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible de supprimer la liaison dans BillingProject ",
                    "BddContributory::removeBillingProject",
                    lastError(q),
                    1.5);
    }
}

void BillingDatabase::updateBilling(const Models::Billing& pBilling)
{
   QSqlQuery q;
   q.prepare("UPDATE Billing SET "
             "title=:title, "
             "description=:description, "
             "number=:number, "
             "date=:date "
             "WHERE idBilling=:idBilling"
             );

   q.bindValue(":title", pBilling.getTitle());
   q.bindValue(":description", pBilling.getDescription());
   q.bindValue(":number", pBilling.getNumber());
   //q.bindValue(":isBilling", pBilling.isBilling());
   q.bindValue(":date", pBilling.getDate());
   q.bindValue(":idBilling",pBilling.getId());

   if(!q.exec()) {
       throw new DbException(
                   "Impossible de mettre à jour le Billing",
                   "BddBilling::updateBilling",
                   lastError(q),
                   1.4);
   }
}

void BillingDatabase::removeBilling(const int pId)
{
    QSqlQuery q;
    q.prepare("DELETE FROM BillingProject "
              "WHERE idBilling=:pId");

    q.bindValue(":pId",pId);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible de supprimer le Billing ",
                    "BddContributory::removeBilling",
                    lastError(q),
                    1.5);
    }

    q.clear();

    q.prepare(
                "DELETE FROM Billing "
                "WHERE idBIlling=:pId");

    q.bindValue(":pId",pId);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible de supprimer le Billing ",
                    "BddContributory::removeBilling",
                    lastError(q),
                    1.5);
    }
}
int BillingDatabase::getMaxBillingNumber()
{
    QSqlQuery q;
    q.prepare("SELECT MAX(number) as max  from Billing where isBilling=1");
    if(!q.exec()) {
        throw new DbException(
            "Impossible d'obtenir le numéro max de la facture",
            "BddContributory::getContributory",
            lastError(q),
            1.5);
    }

    return value(q, "max").toInt();
}

int BillingDatabase::getMaxQuoteNumber()
{
    QSqlQuery q;
    q.prepare("SELECT MAX(number) as max from Billing where isBilling=0");
    if(!q.exec()) {
        throw new DbException(
            "Impossible d'obtenir le numéro max du devis",
            "BddContributory::getContributory",
            lastError(q),
            1.6);
    }
    q.first();
    return value(q, "max").toInt();
}

QSharedPointer<Billing> BillingDatabase::getBilling(QSqlQuery &q)
{
    QSharedPointer<Models::Billing> billing =
            QSharedPointer<Models::Billing>(new Models::Billing());
    billing->setId(value(q, "idBilling").toInt());
    billing->setTitle(value(q, "title").toString());
    billing->setDescription(value(q,"description").toString());
    billing->setNumber(value(q,"number").toInt());
    billing->setDate(QDate::fromString(value(q,"date").toString(),"yyyy-MM-dd"));
    billing->setIsBilling(value(q,"isBilling").toBool());
    billing->setToRemoved(false);

    return billing;
}

QMap<int, Billing> BillingDatabase::getAllBillingsOfProject()
{
    QMap<int, Billing>  map;
    int idProject = 0;
    QSqlQuery q;
    q.prepare("SELECT DISTINCT idProject, idBilling FROM BillingProject");

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'obtenir la liste des Billings",
                    "HierarchicalSystem:getAllBillings",
                    lastError(q),
                    1.2);
    }

    while(q.next()) {
        idProject = value(q, "idProject").toInt();
        map.insert(idProject, Billing(value(q, "idBilling").toInt()));
    }
    return map;
}

}
