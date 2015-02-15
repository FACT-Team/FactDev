#include "contributoriesdatabasetest.h"
#include "database/contributorydatabase.h"
ContributoriesDatabaseTest::ContributoriesDatabaseTest()
{
    c1 = new Models::Contributory();
    c1->setId(200);
    c1->setDescription("Préparer le repas");
    c1->setNbHours(20.0);
    c1->setToRemoved(false);
}

void ContributoriesDatabaseTest::getContributoriesByBilling()
{
    Models::ContributoriesList contributories = Databases::ContributoryDatabase::instance()->getContributoriesByBilling(24);
    QCOMPARE(contributories.getNbProjects(), 2);

    // we only check id… Remaining are already tested (getProject, getContributory)
    for(Project* p : contributories.getProjects()) {
        QList<Contributory> list = contributories.getContributories(p);

            switch(p->getId()) {
            case 21:
                QCOMPARE(list.count(), 3);
                QCOMPARE(list.at(0).getId(), 59);
                QCOMPARE(list.at(1).getId(), 60);
                QCOMPARE(list.at(2).getId(), 61);
                break;
            case 44:
                QCOMPARE(list.count(), 1);
                QCOMPARE(list.at(0).getId(), 62);
                break;
            default:
                QFAIL("Default case");
        }

    }
}

void ContributoriesDatabaseTest::insert()
{
    _lastInsert = Databases::ContributoryDatabase::instance()->addContributory(*c1);
    Contributory* c2 = Databases::ContributoryDatabase::instance()->getContributory(_lastInsert);
    QVERIFY(*c1 == *c2);
}

void ContributoriesDatabaseTest::remove()
{
    Databases::ContributoryDatabase::instance()->removeContributory(_lastInsert);
    Contributory *b2 = Databases::ContributoryDatabase::instance()->getContributory(_lastInsert);
    QVERIFY(b2 == 0);
}

void ContributoriesDatabaseTest::update()
{
    _lastInsert = Databases::ContributoryDatabase::instance()->addContributory(*c1);
    c1->setId(_lastInsert);
    c1->setDescription("Préparer la raclette");
    c1->setNbHours(15.0);
    c1->setToRemoved(false);
    Databases::ContributoryDatabase::instance()->updateContributory(*c1);
    Contributory *c2 = Databases::ContributoryDatabase::instance()->getContributory(_lastInsert);
    QVERIFY(*c1 == *c2);
}

void ContributoriesDatabaseTest::selectContributoryNotFound()
{
    QVERIFY(Databases::ContributoryDatabase::instance()->getContributory(321654) == NULL);
}

void ContributoriesDatabaseTest::selectContributoryFound()
{
    Contributory *c2 = Databases::ContributoryDatabase::instance()->getContributory(1);
    c1->setId(1);
    c1->setDescription("Une descriptoin");
    c1->setNbHours(42.0);
    c1->setToRemoved(false);

    QVERIFY(*c1 == *c2);
}

