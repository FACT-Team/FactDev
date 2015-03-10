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
    contributory->setLongDescription(value(q, "clongdescription").toString());

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

    q.prepare("SELECT idContributory, description as cdescription, longdescription as clongdescription, nbhours "
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

Models::ContributoriesList ContributoryDatabase::getContributoriesByBilling(const int billingId)
{
    QSqlQuery q;
    Models::ContributoriesList contributories;

    q.prepare(
                "SELECT DISTINCT Project.idProject as idProject,"
                " Project.name as name, Project.description as pdescription, "
                " Project.dailyRate as dailyRate, Project.idCustomer, "
                " Contributory.idContributory, Contributory.description as cdescription, "
                "Contributory.longdescription as clongdescription, "
                " Billing.idBilling, nbHours "
                " FROM BillingProject, Project, Billing, Contributory "
                " WHERE BillingProject.idBilling = :idBilling "
                " AND Project.idProject = BillingProject.idProject "
                " AND Billing.idBilling = BillingProject.idBilling "
                " AND Contributory.idContributory = BillingProject.idContributory "
                "ORDER BY Project.idProject ");
    q.bindValue(":idBilling", billingId);
    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'obtenir la prestation",
                    "BddContributory::getContributoriesByBilling",
                    lastError(q),
                    1.8);
    }
    contributories.setIdBilling(billingId);

    while(q.next()) {
        contributories.addContributory(*getContributory(q));
    }

    return contributories;
}


int ContributoryDatabase::addContributory(const Models::Contributory& pContributory) {
    QSqlQuery q;
    q.prepare(
                "INSERT INTO Contributory "
                "(description, longdescription, nbHours)"
                " VALUES "
                "(:description, :longdescription, :nbHours)"
                );

    q.bindValue(":description", pContributory.getDescription());
    q.bindValue(":nbHours", pContributory.getNbHours());
    q.bindValue(":longdescription", pContributory.getLongDescription());
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
              "description=:description, longdescription=:longdescription,"
              "nbHours=:nbHours "
              "WHERE idContributory=:idContributory"
              );

    q.bindValue(":description", pContributory.getDescription());
    q.bindValue(":longdescription", pContributory.getLongDescription());
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

Models::ContributoriesList ContributoryDatabase::getContributoriesByBillingAndProject(const int billingId, const int projectId)
{
    QSqlQuery q;
    Models::ContributoriesList contributories;

    q.prepare(
                "SELECT DISTINCT Project.idProject as idProject,"
                " Project.name as name, Project.description as pdescription, "
                " Project.dailyRate as dailyRate, Project.idCustomer, "
                " Contributory.idContributory, Contributory.description as cdescription, Contributory.longdescription as clongdescription, "
                " Billing.idBilling, nbHours "
                " FROM BillingProject, Project, Billing, Contributory "
                " WHERE BillingProject.idBilling = :idBilling "
                " AND Project.idProject = BillingProject.idProject "
                " AND Billing.idBilling = BillingProject.idBilling "
                " AND Contributory.idContributory = BillingProject.idContributory "
                " AND Project.idProject = :idProject "
                "ORDER BY Project.idProject ");
    q.bindValue(":idBilling", billingId);
    q.bindValue(":idProject", projectId);
    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'obtenir la prestation",
                    "BddContributory::getContributoriesByBillingAndProject",
                    lastError(q),
                    1.8);
    }
    contributories.setIdBilling(billingId);

    while(q.next()) {
        contributories.addContributory(*getContributory(q));
    }

    return contributories;
}
}
