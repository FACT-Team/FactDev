#include "database/contributorydatabase.h"
#include "log.h"
#include "utils.h"

ContributoryDatabase::ContributoryDatabase() throw(DbException*)  : Database() {
    _instances << this;
}

// SINGLETON
ContributoryDatabase* ContributoryDatabase::_instance = 0;

ContributoryDatabase* ContributoryDatabase::instance()throw(DbException*)
{
    if (!_instance) {
        _instance = new ContributoryDatabase();
    }

    return _instance;
}

Contributory* ContributoryDatabase::getContributory(const int idContributory) {
    QSqlQuery q;
    Contributory* contributory;

    q.prepare("SELECT * FROM Contributory WHERE idContributory = :pId");
    q.bindValue(":pId", idContributory);

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'ajouter le/la devis/facture",
            "BddContributory::getContributory",
            lastError(q),
            1.2);
    }

    if(q.first()) {
        contributory = new Contributory();
        contributory->setId(value(q, "idContributory").toInt());
        contributory->setNbHours(value(q, "nbDays").toDouble());
        contributory->setDescription(value(q, "descriptino").toString());
        // contributory->setProject(); TODO join ?
    } else {
        contributory = NULL;
    }

    return contributory;
}

QMap<Project *, QList<Contributory> *> ContributoryDatabase::getContributoriesByBilling(const int idBilling)
{
    QSqlQuery q;
    QMap<Project *, QList<Contributory> *> contributories;
    QMap<int, Project*> projects; // link between id and Project*
    q.prepare("SELECT * FROM ContributoryProject "
              " WHERE idBilling = :idBilling ORDER BY idProject ");
    if(!q.exec()) {
        throw new DbException(
            "Impossible d'obtenir la préstation",
            "BddCustomer::getContributoriesByBilling",
            lastError(q),
            1.8);
    }

    while(q.next()) {
        if(!projects.contains(value(q, "idProject").toInt())) { // It's a new project !
            Project* p = new Project(value(q, "idProject").toInt());
            projects.insert(value(q, "idProject").toInt(), p);
            contributories.insert(p, new QList<Contributory>());
        }
        contributories.value(projects.last())->append(Contributory(value(q, "idContributory").toInt()));
    }

    return contributories;
}


int ContributoryDatabase::addContributory(const Contributory& pContributory) {
    QSqlQuery q;
    q.prepare(
        "INSERT INTO Contributory "
        "(description, nbDays)"
        " VALUES "
        "(:description, :nbDays)"
    );

    q.bindValue(":description", pContributory.getDescription());
    q.bindValue(":nbDays", pContributory.getNbHours());

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'ajouter le Customer",
            "BddCustomer::addCustomer",
            lastError(q),
            1.3);
    }

    return q.lastInsertId().toInt();
}

void ContributoryDatabase::updateContributory(const Contributory& pContributory) {

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

void ContributoryDatabase::removeContributory(const int pId)
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

