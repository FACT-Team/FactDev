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
    //b1.setToRemoved(false);

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

    /*int id = BillingDatabase::instance()->addBilling(b1);
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

void BillingModelTest::remove()
{
    /*b1.remove();
    QVERIFY(BillingDatabase::instance()->getBilling(b1.getId()) == NULL);*/
}





