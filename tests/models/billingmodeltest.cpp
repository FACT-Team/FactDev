#include "billingmodeltest.h"
#include "gui/dialogs/userdatadialog.h"
#include "database/billingdatabase.h"
BillingModelTest::BillingModelTest()
{
}

void BillingModelTest::setup() {
    b1 = new Billing();
    b1->setId(7);
    b1->setTitle("Maitre boucher");
    b1->setDescription("Découpe de viande");
    b1->setNumber(1);
    b1->setDate(QDate(2012,12,21));
    b1->setIsBilling(false);
    b1->setIsPaid(false);

    b2 = new Billing();
    b2->setId(7);
    b2->setTitle("Maitre boucher");
    b2->setDescription("Découpe de viande");
    b2->setNumber(1);
    b2->setDate(QDate(2012,12,21));
    b2->setIsBilling(false);
    b2->setIsPaid(false);
}

void BillingModelTest::equals1()
{
    setup();
    QVERIFY(*b1 == *b2);
}

void BillingModelTest::equals2()
{
    setup();
    b1->setDescription("Découpe de cheval");
    QVERIFY(!(*b1 == *b2));
}

void BillingModelTest::notEquals()
{
    setup();
    b1->setDescription("Découpe de cheval");
    QVERIFY(*b1 != *b2);
}

void BillingModelTest::commitRemove()
{

    // Fucking TOOD ?
//    try {
//        Billing b1(12);
//        b1.setIsBilling(false);
//        b1.setIsPaid(false);
//        b1.setToRemoved(true);

//        b1.commit();
//        QVERIFY(Databases::BillingDatabase::instance()->getBilling(12) == 0);
//    } catch(DbException* e) {
//        QFAIL(e->what());
//    }
}

void BillingModelTest::commitUpdate()
{
    int id = Databases::BillingDatabase::instance()->addBilling(*b1);
    b1->setId(id);
    b1->setDescription("Découpe de poulet");
    try {
        b1->commit();
        Billing *b2 = Databases::BillingDatabase::instance()->getBilling(id);
        QVERIFY(*b1 == *b2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }

}

void BillingModelTest::commitInsert()
{
    setup();
    b1->setId(0);
    ContributoriesList contributories = Billing(1).getContributories();
    b1->setContributories(contributories);
    try {
        b1->commit();
        Billing *b2 = Databases::BillingDatabase::instance()->getBilling(b1->getId());
        QVERIFY(*b1 == *b2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void BillingModelTest::hydrat()
{
    setup();
    try {
        Billing b2 = Billing(1);
        b1->setId(1);
        b1->setTitle("Coucou");
        b1->setDescription("Mon super devis de la mort qui rox du poulet");
        b1->setNumber(1);
        b1->setIsBilling(false);
        b1->setDate(QDate(2015,02,13));
        b1->setIsPaid(false);
        QVERIFY(*b1 == b2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }

}

void BillingModelTest::hydratWithContributories() {
    setup();
    try {
        ContributoriesList contributories = Billing(24).getContributories();
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

void BillingModelTest::getPriceTest() {
    Billing b1(1);
    double testB1 = 0.0;
    for(Project* p : b1.getContributories().getProjects()) {
        testB1 += b1.getContributories().getPrice(p);
    }

    QCOMPARE(714.74, Utils::Double::round(b1.getPrice(), 2));
    QCOMPARE(b1.getContributories().getPrice(), b1.getPrice());
    QCOMPARE(testB1, b1.getPrice());

    Billing b2(2);
    double testB2 = 0.0;
    for(Project* p : b2.getContributories().getProjects()) {
        testB2 += b2.getContributories().getPrice(p);
    }

    QCOMPARE(550.7, Utils::Double::round(b2.getPrice(), 2));
    QCOMPARE(b1.getContributories().getPrice(), b1.getPrice());
    QCOMPARE(testB2, b2.getPrice());

    Billing b3(3);
    double testB3 = 0.0;
    for(Project* p : b3.getContributories().getProjects()) {
        testB3 += b3.getContributories().getPrice(p);
    }

    QCOMPARE(790.85, Utils::Double::round(b3.getPrice(), 2));
    QCOMPARE(b3.getContributories().getPrice(), b3.getPrice());
    QCOMPARE(testB3, b3.getPrice());

}

void BillingModelTest::sumQuantityTest() {
    Billing b1(1);
    QCOMPARE(7.71, Utils::Double::round(b1.getSumQuantity(), 2));
    QCOMPARE(b1.getContributories().getSumQuantity(), b1.getSumQuantity());

    Billing b2(2);
    QCOMPARE(6.43, Utils::Double::round(b2.getSumQuantity(), 2));
    QCOMPARE(b2.getContributories().getSumQuantity(), b2.getSumQuantity());

    Billing b3(3);
    QCOMPARE(11., Utils::Double::round(b3.getSumQuantity(), 2));
    QCOMPARE(b3.getContributories().getSumQuantity(), b3.getSumQuantity());
}
