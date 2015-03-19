#include "statistics.h"

Statistics::Statistics()
{
}

QPair<int, double>  Statistics::getTurnoverBetweenDates(QDate begin, QDate end)
{
    int nbBillings = 0;
    double turnover = 0.0;
    QList<Project*> projects = Databases::ProjectDatabase::instance()->getAllProjects();
    QList<Billing> bills;

    for (Project *p : projects) {
        bills = BillingDatabase::instance()->getAllBillingsOnly(p->getId());
        for (Billing b  : BillingDatabase::instance()->getBillingsBetweenDates(bills, begin, end)) {
            ContributoriesList cl = ContributoryDatabase::instance()->getContributoriesByBillingAndProject(b.getId(),
                                                                                                           p->getId());
            Rate rate = RateDatabase::instance()->getRate(b.getId(), p->getId());
            turnover += cl.getSumQuantity() * rate.getHourlyRate();
            ++nbBillings;
        }
    }

    return QPair<int, double>(nbBillings, turnover);
}
