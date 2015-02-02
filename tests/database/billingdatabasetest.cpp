#include "billingdatabasetest.h"
#include "database/billingdatabase.h"

BillingDatabaseTest::BillingDatabaseTest()
{
    b1.setId(101);
    b1.setDate(QDate(2012,12,21));
    b1.setDescription("Création des donuts dorés");
    b1.setNumber(51);
    b1.setTitle("Maître donut");
    b1.setIsBilling(false);
    b1.setToRemoved(false);
}

void BillingDatabaseTest::insert()
{
    _lastInsert = BillingDatabase::instance()->addBilling(b1);
    Billing* b2 = BillingDatabase::instance()->getBilling(_lastInsert);
    //qDebug() << "insert" << b1.getDate() << " " << b2->getDate();
    QVERIFY(b1 == *b2);
}

void BillingDatabaseTest::remove()
{
    /*qDebug() << _lastInsert;
    BillingDatabase::instance()->removeBilling(_lastInsert);
    Billing *b2 = BillingDatabase::instance()->getBilling(_lastInsert);
    QVERIFY(b2 == 0);*/
}

void BillingDatabaseTest::update()
{
    /*_lastInsert = BillingDatabase::instance()->addBilling(b1);
    b1.setId(_lastInsert);
    b1.setTitle("Paladin donut");
    b1.setDescription("Création des donuts platines");
    BillingDatabase::instance()->updateBilling(b1);
    Billing *b2 = BillingDatabase::instance()->getBilling(_lastInsert);
    QVERIFY(b1 == *b2);*/
}

void BillingDatabaseTest::selectBillingNotFound()
{
    QVERIFY(BillingDatabase::instance()->getBilling(321654) == NULL);
}

void BillingDatabaseTest::selectBillingFound()
{
    Billing *b2 = BillingDatabase::instance()->getBilling(1);
    b1.setId(1);
    b1.setTitle("fringilla,");
    b1.setDescription("tempus risus. Donec egestas. "
                      "Duis ac arcu. Nunc mauris. Morbi");
    b1.setNumber(9);
    b1.setIsBilling(true);
    b1.setDate(QDate(2015,04,24));
    QVERIFY(b1 == *b2);
}

