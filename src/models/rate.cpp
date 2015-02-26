#include "rate.h"

namespace Models {
const double Rate::LEGAL_RATE = 9.61;
const int Rate::NB_DAILY_HOURS = 7;

Rate::Rate(double hourly)
{
    setHourlyRate(hourly);
}

Rate::Rate(int idBilling, int idProject)
{
    setHourlyRate(Databases::RateDatabase::instance()->getRate(idBilling, idProject));
}

Rate::Rate()
{
    _hourly = getLegalRate();
}

void Rate::setDailyRate(const double& value)
{
    _hourly = value >= getLegalRate() * getNbDailyHours() ? value / getNbDailyHours() : getLegalRate();
}

void Rate::setHourlyRate(const double& value)
{
    _hourly = value >= getLegalRate() ? value : getLegalRate();
}

double Rate::getDailyRate() const
{
    return _hourly * getNbDailyHours();
}

double Rate::getHourlyRate() const
{
    return _hourly;
}

int Rate::getNbDailyHours() const
{
    return NB_DAILY_HOURS;
}

double Rate::getLegalRate() const
{
    return LEGAL_RATE;
}

}
