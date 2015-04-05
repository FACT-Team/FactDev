#include "contributorylisttest.h"


ContributoryListTest::ContributoryListTest()
{
}

void ContributoryListTest::setup()
{
    p1 = new Project();
    p1->setName("p1");
    p1->setId(1);
    p2 = new Project();
    p2->setName("p2");
    p2->setId(2);
    p3 = new Project();
    p3->setName("p3");
    p2->setId(3);

    c1.setQuantity(12);
    c1.setUnit(Unit(HOUR));
    c1.setProject(p1);

    c2.setQuantity(2);
    c2.setUnit(Unit(DAY));
    c2.setProject(p1);

    c3.setQuantity(10);
    Unit u;
    u.setType(DAY);
    c3.setUnit(u);
    c3.setProject(p1);

    c4.setQuantity(1);
    c4.setUnit(Unit(HOUR));
    c4.setProject(p1);

    c5.setQuantity(12.5);
    c5.setUnit(Unit(HOUR));
    c5.setProject(p1);

    c6.setQuantity(2);
    c6.setUnit(Unit(MONTH));
    c6.setProject(p1);
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
    setup();
    ContributoriesList contributories;
    contributories.addProject(p1, Rate(12));

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
    c6.setProject(p3);

    contributories2.addContributory(c1); // 1440€
    contributories2.addContributory(c2); // 392€
    contributories2.addContributory(c3); // 840€
    contributories2.addContributory(c4); // 120€
    contributories2.addContributory(c6); // 3360€

    QCOMPARE(contributories2.getPrice(), 6152.);
}

void ContributoryListTest::getPriceOfProject() {
    setup();
    ContributoriesList contributories;
    contributories.addProject(p1, Rate(120));
    contributories.addProject(p2, Rate(28));
    contributories.addProject(p3, Rate(12));

    c1.setProject(p1);
    c2.setProject(p2);
    c3.setProject(p3);
    c4.setProject(p1);
    c5.setProject(p2);
    contributories.addContributory(c1); // 1440
    contributories.addContributory(c2); // 392
    contributories.addContributory(c3); // 840
    contributories.addContributory(c4); // 120
    contributories.addContributory(c5); // 350

    QCOMPARE(contributories.getPrice(p1), 1560.);
    QCOMPARE(contributories.getPrice(p1), contributories.getSumQuantity(p1)*7 * 120);

    QCOMPARE(contributories.getPrice(p2), 742.);
    QCOMPARE(contributories.getPrice(p2), contributories.getSumQuantity(p2)*7 * 28);

    QCOMPARE(contributories.getPrice(p3), 840.);
    QCOMPARE(contributories.getPrice(p3), contributories.getSumQuantity(p3)*7 * 12);
}

void ContributoryListTest::getQuantityTest()
{
    setup();
    ContributoriesList contributories;
    contributories.addProject(p1, Rate(120));
    contributories.addProject(p2, Rate(28));
    contributories.addProject(p3, Rate(12));

    c1.setProject(p1);
    c2.setProject(p2);
    c3.setProject(p3);
    c4.setProject(p1);
    c5.setProject(p2);
    contributories.addContributory(c1); // 1440
    contributories.addContributory(c2); // 392
    contributories.addContributory(c3); // 840
    contributories.addContributory(c4); // 120
    contributories.addContributory(c5); // 350

    QCOMPARE(Utils::Double::round(contributories.getSumQuantity(),3), 15.643);

}

void ContributoryListTest::getQuantityOfProjectTest()
{
    ContributoriesList contributories;
    contributories.addProject(p1, Rate(120));
    contributories.addProject(p2, Rate(28));
    contributories.addProject(p3, Rate(12));

    c1.setProject(p1);
    c2.setProject(p2);
    c3.setProject(p3);
    c4.setProject(p1);
    c5.setProject(p2);
    contributories.addContributory(c1); // 1440
    contributories.addContributory(c2); // 392
    contributories.addContributory(c3); // 840
    contributories.addContributory(c4); // 120
    contributories.addContributory(c5); // 350

    QCOMPARE(Utils::Double::round(contributories.getSumQuantity(p1), 3), 1.857);
    QCOMPARE(Utils::Double::round(contributories.getSumQuantity(p2), 3), 3.786);
    QCOMPARE(Utils::Double::round(contributories.getSumQuantity(p3), 2), 10.00);

}

