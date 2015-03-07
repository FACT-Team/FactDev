#include "database/contributorydatabase.h"

namespace Databases {
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
Models::Contributory* ContributoryDatabase::getContributory(QSqlQuery& q) {
    Models::Contributory* contributory = new Models::Contributory();
    contributory->setId(value(q, "idContributory").toInt());
    contributory->setNbHours(value(q, "nbHours").toDouble());
    contributory->setDescription(value(q, "cdescription").toString());

    QSqlQuery q2;
    q2.prepare("SELECT p.idProject, name,  p.description as pdescription, "
               " beginDate, endDate, dailyRate, idCustomer "
               "FROM BillingProject bp, Project p "
               "WHERE idContributory= :idContributory "
               "AND bp.idProject = p.idProject");

    q2.bindValue(":idContributory", contributory->getId());

    if(!q2.exec()) {
        throw new DbException(
                    "Impossible de récupérer le projet",
                    "BddContributory::getContributory",
                    lastError(q2),
                    1.2);
    }
    if(q2.first()) {
       contributory->setProject(Databases::ProjectDatabase::instance()->getProject(q2));
    } else {
        contributory->setProject(NULL);
    }

    return contributory;
}


Models::Contributory* ContributoryDatabase::getContributory(const int idContributory) {
    QSqlQuery q;
    Models::Contributory* contributory;

    q.prepare("SELECT idContributory, description as cdescription, nbhours "
              "FROM Contributory WHERE idContributory = :pId");
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

Models::ContributoriesList ContributoryDatabase::getContributoriesByBilling(const int idBilling)
{
    QSqlQuery q;
    Models::ContributoriesList contributories;

    q.prepare(
                "SELECT DISTINCT project.idProject as idProject,"
                " project.name as name, project.description as pdescription, "
                " project.dailyRate as dailyRate, project.idCustomer, "
                " contributory.idContributory, contributory.description as cdescription, "
                " billing.idBilling, nbHours "
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
    contributories.setIdBilling(idBilling);

    while(q.next()) {
        contributories.addContributory(*getContributory(q));
    }

    return contributories;
}


int ContributoryDatabase::addContributory(const Models::Contributory& pContributory) {
    QSqlQuery q;
    q.prepare(
                "INSERT INTO Contributory "
                "(description, nbHours)"
                " VALUES "
                "(:description, :nbHours)"
                );

    q.bindValue(":description", pContributory.getDescription());
    q.bindValue(":nbHours", pContributory.getNbHours());

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'ajouter la Contributory",
                    "BddContributory::addContributory",
                    lastError(q),
                    1.3);
    }

    return q.lastInsertId().toInt();
}

void ContributoryDatabase::updateContributory(const Models::Contributory& pContributory) {
    QSqlQuery q;
    q.prepare("UPDATE Contributory SET "
              "description=:description, "
              "nbHours =:nbHours "
              "WHERE idContributory=:idContributory"
              );

    q.bindValue(":description", pContributory.getDescription());
    q.bindValue(":nbHours", pContributory.getNbHours());
    q.bindValue(":idContributory",pContributory.getId());

    if(!q.exec()) {
        throw new DbException("Impossible de mettra à jour la Contributory",
                              "BddContributory::updateContributory",
                              lastError(q),
                              1.4);
    }
}

void ContributoryDatabase::removeContributory(const int pId)
{
    QSqlQuery q;
    q.prepare("DELETE FROM BillingProject "
              "WHERE idContributory=:pId");

    q.bindValue(":pId",pId);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible de supprimer la Contributory ",
                    "BddContributory::removeContributory",
                    lastError(q),
                    1.5);
    }

    q.clear();

    q.prepare(
                "DELETE FROM Contributory "
                "WHERE idContributory=:pId");

    q.bindValue(":pId",pId);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible de supprimer la Contributory ",
                    "BddContributory::removeContributory",
                    lastError(q),
                    1.5);
    }
}

Models::ContributoriesList ContributoryDatabase::getContributoriesByBillingAndProject(const int idBilling, const int idProject)
{
    QSqlQuery q;
    Models::ContributoriesList contributories;

    q.prepare(
                "SELECT DISTINCT project.idProject as idProject,"
                " project.name as name, project.description as pdescription, "
                " project.dailyRate as dailyRate, project.idCustomer, "
                " contributory.idContributory, contributory.description as cdescription, "
                " billing.idBilling, nbHours "
                " FROM BillingProject, project, billing, contributory "
                " WHERE billingProject.idBilling = :idBilling "
                " AND project.idProject = billingProject.idProject "
                " AND billing.idBilling = billingProject.idBilling "
                " AND contributory.idContributory = billingProject.idContributory "
                " AND project.idProject = :idProject "
                "ORDER BY project.idProject ");
    q.bindValue(":idBilling", idBilling);
    q.bindValue(":idProject", idProject);
    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'obtenir la prestation",
                    "BddContributory::getContributoriesByBillingAndProject",
                    lastError(q),
                    1.8);
    }
    contributories.setIdBilling(idBilling);

    while(q.next()) {
        contributories.addContributory(*getContributory(q));
    }

    return contributories;
}
}
