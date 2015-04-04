#include "contributoriesdatabasetest.h"
#include "database/contributorydatabase.h"

ContributoriesDatabaseTest::ContributoriesDatabaseTest()
{
    c1 = new Models::Contributory();
    c1->setId(200);
    c1->setDescription("Préparer le repas");
    c1->setQuantity(20.0);
    c1->setToRemoved(false);
}

void ContributoriesDatabaseTest::getContributoriesByBilling()
{
    try {
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
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ContributoriesDatabaseTest::insert()
{
    try {
        _lastInsert = Databases::ContributoryDatabase::instance()->addContributory(*c1);
        Contributory* c2 = Databases::ContributoryDatabase::instance()->getContributory(_lastInsert);
        QVERIFY(*c1 == *c2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ContributoriesDatabaseTest::remove()
{
    try {
        Databases::ContributoryDatabase::instance()->removeContributory(_lastInsert);
        Contributory *b2 = Databases::ContributoryDatabase::instance()->getContributory(_lastInsert);
        QVERIFY(b2 == 0);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ContributoriesDatabaseTest::update()
{
    try {
        _lastInsert = Databases::ContributoryDatabase::instance()->addContributory(*c1);
        c1->setId(_lastInsert);
        c1->setDescription("Préparer la raclette");
        c1->setQuantity(15.0);
        c1->setToRemoved(false);
        Databases::ContributoryDatabase::instance()->updateContributory(*c1);
        Contributory *c2 = Databases::ContributoryDatabase::instance()->getContributory(_lastInsert);

        QVERIFY(*c1 == *c2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ContributoriesDatabaseTest::selectContributoryNotFound()
{
    try {
        QVERIFY(Databases::ContributoryDatabase::instance()->getContributory(321654) == NULL);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ContributoriesDatabaseTest::selectContributoryFound()
{
    try {
        Contributory *c2 = Databases::ContributoryDatabase::instance()->getContributory(1);
        c1->setId(1);
        c1->setDescription("Une descriptoin");
        c1->setQuantity(42.0);
        c1->setUnit(Unit(HOUR));
        c1->setToRemoved(false);

        QVERIFY(*c1 == *c2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

