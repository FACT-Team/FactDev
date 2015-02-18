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

}
