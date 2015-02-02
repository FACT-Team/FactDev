#include "billingmodeltest.h"

#include <database/billingdatabase.h>

BillingModelTest::BillingModelTest()
{
    b1.setId(7);
    b1.setTitle("Maitre boucher");
    b1.setDescription("Découpe de viande");
    b1.setNumber(1);
    b1.setDate(QDate(2012,12,21));
    b1.setIsBilling(false);

    b2.setId(7);
    b2.setTitle("Maitre boucher");
    b2.setDescription("Découpe de viande");
    b2.setNumber(1);
    b2.setDate(QDate(2012,12,21));
    b2.setIsBilling(false);
}

void BillingModelTest::equals1()
{
    QVERIFY(b1 == b2);
}

void BillingModelTest::equals2()
{
    b1.setDescription("Découpe de cheval");
    QVERIFY(!(b1 == b2));
}

void BillingModelTest::notEquals()
{
    QVERIFY(b1 != b2);
}

void BillingModelTest::commitUpdate()
{
    // TODO implementation
    /*
    int id = BillingDatabase::instance()->addBilling(b1);
    b1.setId(id);
    b1.setDescription("Découpe de poulet");
    b1.commit();
    Billing *b2 = BillingDatabase::instance()->getBilling(id);
    QVERIFY(b1 == *b2);*/
}

void BillingModelTest::commitInsert()
{
    b1.setId(0);
    b1.commit();
    Billing *b2 = BillingDatabase::instance()->getBilling(b1.getId());
    QVERIFY(b1 == *b2);
}

void BillingModelTest::hydrat()
{
    Billing b2 = Billing(1);
    b1.setId(1);
    b1.setTitle("fringilla,");
    b1.setDescription("tempus risus. Donec egestas. "
                      "Duis ac arcu. Nunc mauris. Morbi");
    b1.setNumber(9);
    b1.setIsBilling(true);
    b1.setDate(QDate(2015,04,24));
    QVERIFY(b1 == b2);
}

void BillingModelTest::hydratWithContributories() {
    QMap<Project *, QList<Contributory> *> contributories = Billing(1).getContributories();
    QVERIFY(contributories.count() == 7);

    // we only check id… Remaining are already tested (getProject, getContributory)
    for(auto i = contributories.begin(); i != contributories.end() ; ++i) {
        switch(i.key()->getId()) {
        case 22:
            QVERIFY(i.value()->count() == 2);
            QVERIFY(i.value()->at(0).getId() == 17);
            QVERIFY(i.value()->at(1).getId() == 108);
            break;
        case 29:
            QVERIFY(i.value()->count() == 2);
            QVERIFY(i.value()->at(0).getId() == 220);
            QVERIFY(i.value()->at(1).getId() == 239);
            break;
        case 30:
            QVERIFY(i.value()->count() == 1);
            QVERIFY(i.value()->at(0).getId() == 24);
            break;
        case 32:
            QVERIFY(i.value()->count() == 1);
            QVERIFY(i.value()->at(0).getId() == 89);
            break;
        case 33:
            QVERIFY(i.value()->count() == 1);
            QVERIFY(i.value()->at(0).getId() == 50);
            break;
        case 34:
            QVERIFY(i.value()->count() == 1);
            QVERIFY(i.value()->at(0).getId() == 276);
            break;
        case 40:
            QVERIFY(i.value()->count() == 1);
            QVERIFY(i.value()->at(0).getId() == 74);
            break;
        default:
            QVERIFY(false);
        }
    }
}
