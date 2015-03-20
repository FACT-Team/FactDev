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
        billing->setDate(value(q,"date").toDate());
        billing->setIsBilling(value(q,"isBilling").toBool());
        billing->setIsPaid(value(q,"isPaid").toBool());
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
             "isBilling, date, isPaid "
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
                "(title, description, number, isBilling, date, isPaid)"
                " VALUES "
                "(:title, :description, :number, :isBilling, :date, :isPaid)"
                );

    q.bindValue(":title", pBilling.getTitle());
    q.bindValue(":description", pBilling.getDescription());
    q.bindValue(":number", pBilling.getNumber());
    q.bindValue(":isBilling", pBilling.isBilling());
    q.bindValue(":date", pBilling.getDate());
    q.bindValue(":isPaid", pBilling.isPaid());
    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'ajouter le Billing",
                    "BddBilling::addBilling",
                    lastError(q),
                    1.3);
    }
    return q.lastInsertId().toInt();
}

void BillingDatabase::addBillingProject(
        const int idProject, const int idBilling, const int idContributory)
{
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

void BillingDatabase::removeBillingProject(
        const int idProject, const int idBilling, const int idContributory)
{
    QSqlQuery q;
    QString project;

    (idProject == 0) ? project="" :
            project="idProject= "+ QString::number(idProject) +" AND ";

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
             "date=:date, "
             "isPaid=:isPaid "
             "WHERE idBilling=:idBilling"
             );

   q.bindValue(":title", pBilling.getTitle());
   q.bindValue(":description", pBilling.getDescription());
   q.bindValue(":number", pBilling.getNumber());
   //q.bindValue(":isBilling", pBilling.isBilling());
   q.bindValue(":date", pBilling.getDate());
   q.bindValue(":idBilling",pBilling.getId());
   q.bindValue(":isPaid", pBilling.isPaid());

   if(!q.exec()) {
       throw new DbException(
                   "Impossible de mettre à jour le Billing",
                   "BddBilling::updateBilling",
                   lastError(q),
                   1.4);
   }
}
bool BillingDatabase::isBillingPaid(const int pId) {
    QSqlQuery q;

    q.prepare("SELECT count(*) AS nb_b "
              "FROM Billing "
              "WHERE idBilling = :pId "
              "AND isBilling = 1 "
              "AND isPaid = 1 ");

    q.bindValue(":pId",pId);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible de supprimer le Billing ",
                    "BddContributory::removeBilling",
                    lastError(q),
                    1.5);
    }

    q.next();

     return value(q, "nb_b").toInt() == 1;

}

void BillingDatabase::removeBilling(const int pId)
{
    QSqlQuery q;

    if (!isBillingPaid(pId)) {
        q.prepare("DELETE FROM BillingProject "
                  "WHERE idBilling=:pId");

        q.bindValue(":pId",pId);

        if(!q.exec()) {
            throw new DbException(
                        "Impossible de supprimer le Billing ",
                        "BddContributory::removeBilling",
                        lastError(q),
                        1.51);
        }
        q.prepare("DELETE FROM BillingRate "
                  "WHERE idBilling=:pId");

        q.bindValue(":pId",pId);

        if(!q.exec()) {
            throw new DbException(
                        "Impossible de supprimer le Billing ",
                        "BddContributory::removeBilling",
                        lastError(q),
                        1.51);
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
                        1.52);
        }
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

    q.first();
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

int BillingDatabase::getMaxBillingNumberOfCustomer(const int idCustomer)
{
    QSqlQuery q;
    q.prepare("SELECT MAX(number) as max FROM Customer c, Project p, BillingProject bp, Billing b "
              "WHERE "
              "c.idCustomer = p.idCustomer "
              "AND p.idProject = bp.idProject "
              "AND bp.idBilling = b.idBilling "
              "AND isBilling = 1 "
              "AND c.idCustomer = :idCustomer");

    q.bindValue(":idCustomer",idCustomer);

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'obtenir le numéro max du devis",
            "BddContributory::getMaxBillingNumberOfCustomer",
            lastError(q),
            1.6);
    }
    q.first();
    return value(q,"max").toInt();

}

int BillingDatabase::getMaxQuoteNumberOfCustomer(const int idCustomer)
{
    QSqlQuery q;
    q.prepare("SELECT MAX(number) as max FROM Customer c, Project p, BillingProject bp, Billing b "
              "WHERE "
              "c.idCustomer = p.idCustomer "
              "AND p.idProject = bp.idProject "
              "AND bp.idBilling = b.idBilling "
              "AND isBilling = 0 "
              "AND c.idCustomer = :idCustomer ");

    q.bindValue(":idCustomer",idCustomer);

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'obtenir le numéro max du devis",
            "BddContributory::getMaxBillingNumberOfCustomer",
            lastError(q),
            1.6);
    }
    q.first();
    return value(q,"max").toInt();
}

QSharedPointer<Billing> BillingDatabase::getBilling(QSqlQuery &q)
{
    QSharedPointer<Models::Billing> billing =
            QSharedPointer<Models::Billing>(new Models::Billing());
    billing->setId(value(q, "idBilling").toInt());
    billing->setTitle(value(q, "title").toString());
    billing->setDescription(value(q,"description").toString());
    billing->setNumber(value(q,"number").toInt());
    billing->setDate(value(q,"date").toDate());
    billing->setIsBilling(value(q,"isBilling").toBool());
    billing->setIsPaid(value(q,"isPaid").toBool());
    billing->setToRemoved(false);

    return billing;
}

QMap<Project*, Billing*> BillingDatabase::getAllBillingsOfProject()
{
    QMap<Project*, Billing*>  map;
    QSqlQuery q;
    q.prepare("SELECT idProject, idBilling FROM BillingProject");

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'obtenir la liste des Billings",
                    "HierarchicalSystem:getAllBillings",
                    lastError(q),
                    1.2);
    }

    while(q.next()) {
        map.insert(
                    new Project(value(q,"idProject").toInt()),
                    new Billing(value(q, "idBilling").toInt()));
    }
    return map;
}

QList<Billing> BillingDatabase::getBillings(const int projectId)
{
    QList<Billing> bills;
    QSqlQuery q;
    q.prepare(
             "SELECT DISTINCT b.idBilling, title, description, number, "
             "isBilling, date, isPaid "
             "FROM Billing b, BillingProject bp "
             "WHERE idProject = :idproject "
             "AND b.idBilling = bp.idBilling AND b.isBilling = 1 "
             "ORDER BY date DESC");

    q.bindValue(":idproject",projectId);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible de récupérer les Factures",
                    "BddCustomer::getBillings",
                    lastError(q),
                    1.3);
    }

    while(q.next()) {
        bills.append(*getBilling(q));
    }
    return bills;
}

QList<Billing> BillingDatabase::getAllBillingsOnly(const int idProject)
{
    QList<Billing> bills;
    QSqlQuery q;
    q.prepare(
             "SELECT DISTINCT b.idBilling, title, description, number, "
             "isBilling, date, isPaid "
             "FROM Billing b, BillingProject bp "
             "WHERE idProject=:idProject "
             "AND b.idBilling = bp.idBilling "
             "AND isPaid = 1 "
             "AND isBilling = 1 "
             );

    q.bindValue(":idProject",idProject);


    if(!q.exec()) {
        throw new DbException(
                    "Impossible de récupérer les Factures",
                    "BddCustomer::getBillings",
                    lastError(q),
                    1.3);
    }

    while(q.next()) {
        bills.append(*getBilling(q));
    }
    return bills;
}

QList<Billing> BillingDatabase::getBillingsBetweenDates(QDate begin, QDate end)
{
    // select * from billing where date between '2015-01-01' and '2015-03-19' and isBilling=1 ;
    QList<Billing> bills;
    QSqlQuery q;
    q.prepare(
             "SELECT DISTINCT b.idBilling, title, description, number, "
             "isBilling, date, isPaid "
             "FROM Billing b "
             "WHERE "
              " date BETWEEN :begin and :end "
              "AND isPaid = 1 "
              "AND isBilling = 1 "
             );
    q.bindValue(":begin", begin);
    q.bindValue(":end", end);
    if(!q.exec()) {
        throw new DbException(
                    "Impossible de récupérer les Factures",
                    "BddCustomer::getBillings",
                    lastError(q),
                    1.3);
    }

    while(q.next()) {
        bills << *getBilling(q);
    }

    return bills;

}

}
