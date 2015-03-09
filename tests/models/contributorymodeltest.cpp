#include "contributorymodeltest.h"

#include "database/contributorydatabase.h"
ContributoryModelTest::ContributoryModelTest()
{
}

void ContributoryModelTest::setup()
{
    c1.setDescription("Une descriptoin");
    c1.setNbHours(42);
    c1.setProject(new Project(23));
    c1.setToRemoved(false);

    c2.setDescription("Une descriptoin");
    c2.setNbHours(42);
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
    c1.setNbHours(1337);
    QVERIFY(c1 != c2);
}

void ContributoryModelTest::commitUpdate()
{
    setup();
    c1.setId(3);
    c1.setDescription("New description");
    c1.commit();
    c2 = *(Databases::ContributoryDatabase::instance()->getContributory(3));
    qDebug() << (c1.getProject() == c2.getProject());

    QVERIFY(c1 == c2);
}

void ContributoryModelTest::commitInsert()
{
    setup();
    c1.setId(0);
    c1.commit();
    c2 = *(Databases::ContributoryDatabase::instance()->getContributory(c1.getId()));
    QVERIFY(c1 == c2);
}

void ContributoryModelTest::hydrat()
{
    setup();
    Contributory c(1);
    QVERIFY(c == c1);
}

void ContributoryModelTest::commitRemove()
{
    setup();
    c1.setToRemoved(true);
    c1.setId(23);
    c1.commit();
    Contributory* c = Databases::ContributoryDatabase::instance()->getContributory(23);
    QVERIFY(c == 0);
}
