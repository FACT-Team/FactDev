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

void BillingModelTest::testGetItem() {
    try {
        Models::Billing b(1);
        QVERIFY(b.getItem()->data(Qt::DisplayRole).toString() == "02-2015 Coucou");
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

