#ifndef RATEDATABASE_H
#define RATEDATABASE_H
#include "exceptions/dbexception.h"
#include "database.h"

using namespace Exceptions;

namespace Databases {

class RateDatabase : public Database
{
public:
    /**
     * @brief RateDatabase::getInstance Return an instance of RateDatabase
     * @return Instance of RateDatabase
     */
    static RateDatabase*  instance() throw (DbException*);

    void addRateProject(int idProject, int idBilling, double hourlyRate);
    double getRate(const int idBilling, const int idProject) const;
    void updateRateProject(int idProject, int idBilling, double hourlyRate);
private:
    static RateDatabase* _instance; //!< Singleton instance of RateDatabase
    /**
     * @brief RateDatabase: is a singleton
     */
    RateDatabase() throw (DbException*);

};

}
#endif // RATEDATABASE_H
