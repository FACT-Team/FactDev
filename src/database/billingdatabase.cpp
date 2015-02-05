#include "database/billingdatabase.h"

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
    Billing* billing;
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
             "SELECT DISTINCT b.idBilling,title,number,isBilling,date "
             "FROM Billing b, BillingProject bp "
             "WHERE idProject = :idproject "
             "AND b.idBilling = bp.idBilling ORDER BY date DESC");

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

void BillingDatabase::updateBilling(const Billing& pBilling)
{
    Log::instance(ERROR) << "TODO implement ContributoryDatabase::updateBilling. Parameter: " << QString::number(pBilling.getId());
}

void BillingDatabase::removeBilling(const int pId)
{
    Log::instance(ERROR) << "TODO implement ContributoryDatabase::removeBilling. Parameter: " << QString::number(pId);
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

int BillingDatabase::getMaxQuoteNuber()
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

