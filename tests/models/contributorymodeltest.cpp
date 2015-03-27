#include "contributorymodeltest.h"

#include "database/contributorydatabase.h"
ContributoryModelTest::ContributoryModelTest()
{
}

void ContributoryModelTest::setup()
{
    c1.setDescription("Une descriptoin");
    c1.setQuantity(42);
    c1.setProject(new Project(23));
    c1.setToRemoved(false);

    c2.setDescription("Une descriptoin");
    c2.setQuantity(42);
    c2.setProject(new Project(23));
    c2.setToRemoved(false);
}

void ContributoryModelTest::equals1()
{
    setup();
    QVERIFY(c1 == c2);
}

void ContributoryModelTest::equals2()
{
    setup();
    c1.setDescription("Berk");
    QVERIFY(!(c1 == c2));
}

void ContributoryModelTest::notEquals()
{
    setup();
    c1.setQuantity(1337);
    QVERIFY(c1 != c2);
}

void ContributoryModelTest::commitUpdate()
{
    setup();
    c1.setId(3);
    c1.setDescription("New description");
    try {
        c1.commit();
        c2 = *(Databases::ContributoryDatabase::instance()->getContributory(3));

        QVERIFY(c1 == c2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ContributoryModelTest::commitInsert()
{
    setup();
    c1.setId(0);
    try {
        c1.commit();
        c2 = *(Databases::ContributoryDatabase::instance()->getContributory(c1.getId()));
        QVERIFY(c1 == c2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ContributoryModelTest::hydrat()
{
    setup();
    try {
        Contributory c(1);
        QVERIFY(c == c1);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ContributoryModelTest::commitRemove()
{
    setup();
    c1.setToRemoved(true);
    c1.setId(23);
    try {
        c1.commit();
        Contributory* c = Databases::ContributoryDatabase::instance()->getContributory(23);
        QVERIFY(c == 0);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ContributoryModelTest::getRateTest() {
    Contributory c;
    Project p;

    c.setQuantity(5);
    c.setUnit(Unit(HOUR));
    c.setHourlyRate(15);
    QCOMPARE(c.getRate(), 75.);
    c.setUnit(Unit(DAY));
    QCOMPARE(c.getRate(), 525.);
    c.setProject(&p);
    c.setHourlyRate(0.0);
    p.setDailyRate(250);
    QCOMPARE(c.getRate(), 1250.);

    c.setUnit(Unit(HOUR));
    QCOMPARE(Utils::Double::round(c.getRate(), 2), 178.57);

}
