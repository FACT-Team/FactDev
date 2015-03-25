#include "statistics.h"

#include "database/customerdatabase.h"

using namespace Databases;

Statistics::Statistics()
{
}

QPair<int, double>  Statistics::getTurnoverBetweenDates(QDate begin, QDate end)
{
    double turnover = 0.0;
    QList<Project*> projects = Databases::ProjectDatabase::instance()->getAllProjects();
    QList<Billing> bills;
    QList<Billing> billsBetweenDates = BillingDatabase::instance()->getBillingsBetweenDates(begin, end);

    for (Project *p : projects) {
        bills = BillingDatabase::instance()->getBillsPaid(p->getId());
        for (Billing b  : billsBetweenDates) {
            ContributoriesList cl = ContributoryDatabase::instance()->getContributoriesByBillingAndProject(b.getId(),
                                                                                                           p->getId());
            Rate rate = RateDatabase::instance()->getRate(b.getId(), p->getId());
            turnover += cl.getSumQuantity() * rate.getHourlyRate();
        }
    }

    return QPair<int, double>(billsBetweenDates.count(), turnover);
}

double Statistics::getGlobalTurnover() {
    double ret(0.0);
    QList<Customer> customers = Databases::CustomerDatabase::instance()->getCustomers();
    for (Customer customer : customers) {
        ret += customer.getTurnover();
    }
    return ret;
}
