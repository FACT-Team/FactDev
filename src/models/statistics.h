#ifndef STATISTICS_H
#define STATISTICS_H

#include <QDate>
#include <QPair>

#include "models/project.h"
#include "models/rate.h"

#include "database/projectdatabase.h"
#include "database/billingdatabase.h"

using namespace Databases;
namespace Models {
class Statistics
{
public:
    Statistics();

    /**
     * @brief getTurnoverBetweenDates Compute the turnover betweend 2 dates
     * @param begin The beginning date
     * @param end The ending date
     * @return A Qpair who contains the number of billing and their costs
     */
    static QPair<int, double> getTurnoverBetweenDates(QDate begin, QDate end);

    /**
     * @brief Get the global turnover
     * @return The global turnover
     */
    static double getGlobalTurnover();
};
}
#endif // STATISTICS_H
