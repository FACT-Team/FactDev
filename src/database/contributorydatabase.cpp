#include "database/contributorydatabase.h"
#include "database/projectdatabase.h"

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
Contributory* ContributoryDatabase::getContributory(QSqlQuery& q) {
    Contributory* contributory = new Contributory();
    contributory->setId(value(q, "idContributory").toInt());
    contributory->setNbHours(value(q, "nbDays").toDouble());
    contributory->setDescription(value(q, "description").toString());
    // contributory->setProject(); TODO join ?

    return contributory;
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
        contributory = getContributory(q);
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
    q.prepare(
                "SELECT DISTINCT project.idProject as idProject,"
                " project.name as name, project.description as description, "
                " project.dailyRate as dailyRate, project.idCustomer, contributory.idContributory, billing.idBilling, nbDays "
                " FROM BillingProject, project, billing, contributory "
                " WHERE billingProject.idBilling = :idBilling "
                " AND project.idProject = billingProject.idProject "
                " AND billing.idBilling = billingProject.idBilling "
                " AND contributory.idContributory = billingProject.idContributory "
                "ORDER BY project.idProject ");
    q.bindValue(":idBilling", idBilling);
    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'obtenir la prestation",
                    "BddContributory::getContributoriesByBilling",
                    lastError(q),
                    1.8);
    }

    while(q.next()) {
        if(!projects.contains(value(q, "idProject").toInt())) { // It's a new project !
            Project* p = ProjectDatabase::instance()->getProject(q);
            projects.insert(value(q, "idProject").toInt(), p);
            contributories.insert(p, new QList<Contributory>());
        }
        contributories.value(projects.last())->append(*getContributory(q));
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
                    "BddContributory::addCustomer",
                    lastError(q),
                    1.3);
    }

    return q.lastInsertId().toInt();
}

void ContributoryDatabase::updateContributory(const Contributory& pContributory) {

    QSqlQuery q;


}

void ContributoryDatabase::removeContributory(const int pId)
{
    QSqlQuery q;


}
