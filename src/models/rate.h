#ifndef RATE_H
#define RATE_H

#include "database/ratedatabase.h"

namespace Models {

/**
 * @author Antoine de Roquemaurel
 * @brief The Rate class Rate of a prestation
 */
class Rate
{
public:

    /**
     * @brief Rate::Rate Construct a Rate
     */
    Rate();

    /**
     * @brief Rate::Rate Construct a Rate with an hourly rate
     * @param hourly Hourly rate
     */
    Rate(double hourly);

    /**
     * @brief Rate::Rate Construct a Rate for the Billing with <i>idBilling</i>
     * as identify and from the project identified by <i>idProject</i>
     * @param idBilling Billing identify
     * @param idProject Project identify
     */
    Rate(int idBilling, int idProject);

    /**
     * @brief Rate::setDailyRate Modify the daily rate with the new value
     */
    void setDailyRate(const double&);

    /**
     * @brief Rate::setHourlyRate Modify the hourly rate with the new value
     */
    void setHourlyRate(const double&);

    /**
     * @brief Rate::getDailyRate Return the daily rate
     * @return
     */
    double getDailyRate() const;

    /**
     * @brief Rate::getHourlyRate Return the hourly rate
     * @return
     */
    double getHourlyRate() const;

    /**
     * @brief Rate::getNbDailyHours Return the number of daily hours
     * @return
     */
    int getNbDailyHours() const;

    /**
     * @brief Rate::getLegalRate Return the legal rate
     * @return
     */
    double getLegalRate() const;

private:
    double _hourly;                     //!< Hourly rate
    static const double LEGAL_RATE;     //!< The Legal hourly Rate
    static const int NB_DAILY_HOURS;    //!< The number of daily hours in a day
};

}
#endif // RATE_H
