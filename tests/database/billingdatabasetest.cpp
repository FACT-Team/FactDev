#include "billingdatabasetest.h"
#include "database/billingdatabase.h"

BillingDatabaseTest::BillingDatabaseTest()
{
    b1.setId(120);
    b1.setDate(QDate(2012,12,21));
    b1.setDescription("Création des donuts dorés");
    b1.setNumber(51);
    b1.setTitle("Maître donut");
    b1.setIsBilling(false);
    b1.setToRemoved(false);
}

void BillingDatabaseTest::insert()
{
    /*_lastInsert = BillingDatabase::instance()->addBilling(b1);
    Billing * b2 = BillingDatabase::instance()->getBilling(_lastInsert);
    QVERIFY(b1 == *b2);*/
}

void BillingDatabaseTest::remove()
{
    BillingDatabase::instance()->removeBilling(_lastInsert);
    Billing *b2 = BillingDatabase::instance()->getBilling(_lastInsert);
    QVERIFY(b2 == 0);
}

void BillingDatabaseTest::update()
{
    //TO DO: Ajouter des jeux de tests avec tous les champs remplis
   /* _lastInsert = BillingDatabase::instance()->addBilling(b1);
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
    //TO DO: Ajouter des jeux de tests avec tous les champs remplis
    /*Billing *b2 = BillingDatabase::instance()->getBilling(1);
    b1.setId(1);
    b1.setTitle("faucibus");
    b1.setDescription("");
    //TO DO: des jeux de tests insérant des vraies descriptions
    b1.setNumber(1);//A changer
    b1.setIsBilling(0);
    b1.setDate(QDate(2011,7,29));
    QVERIFY(b1 == *b2);*/
}
