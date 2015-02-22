#include "ratedatabase.h"

namespace Databases {

RateDatabase::RateDatabase() throw(DbException*) : Database() {
    _instances << this;
}

// SINGLETON
RateDatabase* RateDatabase::_instance = 0;

RateDatabase *RateDatabase::instance() throw(DbException*)
{
    if (!_instance) {
        _instance = new RateDatabase();
    }

    return _instance;
}

void RateDatabase::addRateProject(int idProject, int idBilling, double hourlyRate)
{
    QSqlQuery q;
    q.prepare(
                "INSERT INTO BillingRate "
                "(idProject, idBilling, hourlyRate) VALUES "
                "(:idProject, :idBilling, :hourlyRate)"
                );
    q.bindValue(":idProject", idProject);
    q.bindValue(":idBilling", idBilling);
    q.bindValue(":hourlyRate", hourlyRate);
    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'ajouter le tarif de cette facture/devis",
                    "RateDatabase::addRateProject",
                    lastError(q),
                    14.1);
    }
}

void RateDatabase::updateRateProject(int idProject, int idBilling, double hourlyRate)
{
    QSqlQuery q;
    q.prepare(
                "UPDATE BillingRate "
                "set hourlyRate=:hourlyRate WHERE idProject=:idProject and idBilling=:idBilling "
                );
    q.bindValue(":idProject", idProject);
    q.bindValue(":idBilling", idBilling);
    q.bindValue(":hourlyRate", hourlyRate);
    if(!q.exec()) {
        throw new DbException(
                    "Impossible de modifier le tarif de cette facture/devis",
                    "RateDatabase::addRateProject",
                    lastError(q),
                    14.1);
    }
}


double RateDatabase::getRate(const int idBilling, const int idProject) const {
    QSqlQuery q;
    q.prepare(
                "SELECT * FROM BillingRate "
                "WHERE idProject = :idProject and idBilling = :idBilling"
                );
    q.bindValue(":idProject", idProject);
    q.bindValue(":idBilling", idBilling);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'obtenir le tarif de cette facture/devis",
                    "RateDatabase::getRate",
                    lastError(q),
                    14.2);

    }
    q.first();

    return value(q, "hourlyRate").toDouble();
}

}
