#include "contributoriesdatabasetest.h"
#include "database/contributorydatabase.h"
void ContributoriesDatabaseTest::getContributoriesByBilling()
{
    QMap<Models::Project *, QList<Models::Contributory> > contributories =
            Databases::ContributoryDatabase::instance()->getContributoriesByBilling(24);
    QCOMPARE(contributories.count(), 2);

    // we only check id… Remaining are already tested (getProject, getContributory)
    for(auto i = contributories.begin(); i != contributories.end() ; ++i) {
        switch(i.key()->getId()) {
        case 21:
            QCOMPARE(i.value().count(), 3);
            QCOMPARE(i.value().at(0).getId(), 59);
            QCOMPARE(i.value().at(1).getId(), 60);
            QCOMPARE(i.value().at(2).getId(), 61);
            break;
        case 44:
            QCOMPARE(i.value().count(), 1);
            QCOMPARE(i.value().at(0).getId(), 62);
            break;
        default:
            QFAIL("Default case");
        }
    }
}
