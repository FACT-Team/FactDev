#ifndef RATE_H
#define RATE_H

namespace Models {

class Rate
{
public:
    Rate(double hourly);
    Rate();

    void setDailyRate(const double&);
    void setHourlyRate(const double&);
    double getDailyRate() const;
    double getHourlyRate() const;
    int getNbDailyHours() const;
    double getLegalRate() const;

private:
    double _hourly;
    static const double LEGAL_RATE; //!< The Legal hourly Rate
    static const int NB_DAILY_HOURS; //!< The number of daily hours in a day
};

}
#endif // RATE_H
