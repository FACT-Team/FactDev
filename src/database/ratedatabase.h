#ifndef RATEDATABASE_H
#define RATEDATABASE_H
#include "exceptions/dbexception.h"
#include "database.h"

#include "models/rate.h"
using namespace Exceptions;

namespace Databases {

class RateDatabase : public Database
{
public:
    /**
     * @brief RateDatabase::getInstance Return an instance of RateDatabase
     * @return Instance of RateDatabase
     */
    static RateDatabase*  instance();

    /**
     * @brief RateDatabase::addRateProject Add a new rate <i>hourlyRate</i> to
     * the Project identified by <i>idProject</i> of the Billing with
     * <i>idBilling</i> as identify
     * @param idProject Project identify
     * @param idBilling Billing identify
     * @param hourlyRate New hourly rate
     */
    void addRateProject(int idProject, int idBilling, double hourlyRate);

    /**
     * @brief RateDatabase::getRate Return the rate of the Project identified
     * by <i>idProject</i> of the Billing with <i>idBilling</i> as identify
     * @param idBilling Billing identify
     * @param idProject Project identify
     * @return Rate of the Project of a Billing
     */
    double getRate(const int idBilling, const int idProject) const;

    /**
     * @brief RateDatabase::updateRateProject Update the current rate by the new
     *  <i>hourlyRate</i> of the Project identified by <i>idProject</i> of the
     * Billing with <i>idBilling</i> as identify
     * @param idProject Project identify
     * @param idBilling Billing identify
     * @param hourlyRate New hourly rate
     */
    void updateRateProject(int idProject, int idBilling, double hourlyRate);

private:
    static RateDatabase* _instance; //!< Singleton instance of RateDatabase
    /**
     * @brief RateDatabase: is a singleton
     */
    RateDatabase();

};

}
#endif // RATEDATABASE_H
