#include "contributorylisttest.h"


ContributoryListTest::ContributoryListTest()
{
}

void ContributoryListTest::addProject()
{
    try {
        ContributoriesList contributories = ContributoriesList();
        contributories.addProject(new Project(1),Rate(12));
        QVERIFY(contributories.getAllContributories()->count() == 0);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ContributoryListTest::getPriceTest() {
    Contributory c1;
    ContributoriesList contributories;
    Project* p1 = new Project();
    p1->setName("p1");
    p1->setId(1);
    Project* p2 = new Project();
    p2->setName("p2");
    p2->setId(2);
    Project* p3 = new Project();
    p3->setName("p3");
    p2->setId(3);
    contributories.addProject(p1, Rate(12));
    c1.setQuantity(12);
    c1.setUnit(Unit(HOUR));
    c1.setProject(p1);

    Contributory c2;
    c2.setQuantity(2);
    c2.setUnit(Unit(DAY));
    c2.setProject(p1);

    Contributory c3;
    c3.setQuantity(10);
    c3.setUnit(Unit(DAY));
    c3.setProject(p1);

    Contributory c4;
    c4.setQuantity(1);
    c4.setUnit(Unit(HOUR));
    c4.setProject(p1);

    contributories.addContributory(c1);
    contributories.addContributory(c2);
    contributories.addContributory(c3);
    contributories.addContributory(c4);

    QCOMPARE(contributories.getPrice(), 1164.);

    ContributoriesList contributories2;
    contributories2.addProject(p1, Rate(120));
    contributories2.addProject(p2, Rate(28));
    contributories2.addProject(p3, Rate(12));

    c1.setProject(p1);
    c2.setProject(p2);
    c3.setProject(p3);
    c4.setProject(p1);

    contributories2.addContributory(c1); // 1440€
    contributories2.addContributory(c2); // 392€
    contributories2.addContributory(c3); // 840€
    contributories2.addContributory(c4); // 120€

    QCOMPARE(contributories2.getPrice(), 2792.);
}

