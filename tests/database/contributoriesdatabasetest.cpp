#include "contributoriesdatabasetest.h"
#include "database/contributorydatabase.h"
void ContributoriesDatabaseTest::getContributoriesByBilling()
{
    QMap<Project *, QList<Contributory> > contributories = ContributoryDatabase::instance()->getContributoriesByBilling(1);
    QVERIFY(contributories.count() == 7);

    // we only check id… Remaining are already tested (getProject, getContributory)
    for(auto i = contributories.begin(); i != contributories.end() ; ++i) {
        switch(i.key()->getId()) {
        case 22:
            QVERIFY(i.value().count() == 2);
            QVERIFY(i.value().at(0).getId() == 17);
            QVERIFY(i.value().at(1).getId() == 108);
            break;
        case 29:
            QVERIFY(i.value().count() == 2);
            QVERIFY(i.value().at(0).getId() == 220);
            QVERIFY(i.value().at(1).getId() == 239);
            break;
        case 30:
            QVERIFY(i.value().count() == 1);
            QVERIFY(i.value().at(0).getId() == 24);
            break;
        case 32:
            QVERIFY(i.value().count() == 1);
            QVERIFY(i.value().at(0).getId() == 89);
            break;
        case 33:
            QVERIFY(i.value().count() == 1);
            QVERIFY(i.value().at(0).getId() == 50);
            break;
        case 34:
            QVERIFY(i.value().count() == 1);
            QVERIFY(i.value().at(0).getId() == 276);
            break;
        case 40:
            QVERIFY(i.value().count() == 1);
            QVERIFY(i.value().at(0).getId() == 74);
            break;
        default:
            QVERIFY(false);
        }
    }
}
