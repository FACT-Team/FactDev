#include "billingdatabasetest.h"
#include "database/billingdatabase.h"

BillingDatabaseTest::BillingDatabaseTest()
{
}

void BillingDatabaseTest::setup() {
    b1 = new Models::Billing();
    b1->setId(101);
    b1->setDate(QDate(2012,12,21));
    b1->setDescription("Création des donuts dorés");
    b1->setNumber(51);
    b1->setTitle("Maître donut");
    b1->setIsBilling(false);
    b1->setToRemoved(false);
}

void BillingDatabaseTest::insert()
{
    setup();
    _lastInsert = Databases::BillingDatabase::instance()->addBilling(*b1);
    Billing* b2 = Databases::BillingDatabase::instance()->getBilling(_lastInsert);

    QVERIFY(*b1 == *b2);
}

void BillingDatabaseTest::remove()
{
    Databases::BillingDatabase::instance()->removeBilling(_lastInsert);
    Billing *b2 = Databases::BillingDatabase::instance()->getBilling(_lastInsert);
    QVERIFY(b2 == 0);
}

void BillingDatabaseTest::update()
{
    _lastInsert = Databases::BillingDatabase::instance()->addBilling(*b1);
    b1->setId(_lastInsert);
    b1->setTitle("Paladin donut");
    b1->setDescription("Création des donuts platines");
    Databases::BillingDatabase::instance()->updateBilling(*b1);
    Billing *b2 = Databases::BillingDatabase::instance()->getBilling(_lastInsert);
    QVERIFY(*b1 == *b2);
}

void BillingDatabaseTest::selectBillingNotFound()
{
    setup();
    QVERIFY(Databases::BillingDatabase::instance()->getBilling(321654) == NULL);
}

void BillingDatabaseTest::selectBillingFound()
{
    Billing *b3 = Databases::BillingDatabase::instance()->getBilling(1);
    b1->setId(1);
    b1->setTitle("Coucou");
    b1->setDescription("Mon super devis de la mort qui rox du poulet");
    b1->setNumber(1);
    b1->setIsBilling(false);
    b1->setDate(QDate(2015,02,13));

    QVERIFY(*b1 == *b3);
}

void BillingDatabaseTest::addBillingProject()
{
    int project = 1, billing = 1, contributory = 1;
    Databases::BillingDatabase::instance()->addBillingProject(project,billing,contributory);

    QSqlQuery q;
    q.prepare("SELECT * from BillingProject "
              "WHERE idProject=1 "
              "AND idBilling=1 "
              "AND idContributory=1");

    if(!q.exec()) {
        throw new DbException(
                    "Impossible de selectionner le BillingProject",
                    "BddBillingDatabaseTest::addBillingProject",
                    "Databases::Database::instance()->lastError(q)",
                    1.3);
    }

    q.first();
    qDebug() << q.isNull(0);
    QVERIFY(q.value("idProject").toInt()==project &&
            q.value("idBilling").toInt()==billing &&
            q.value("idContributory").toInt()==contributory);
}

void BillingDatabaseTest::removeBillingProject()
{
    int project = 1, billing = 1, contributory = 1;
    Databases::BillingDatabase::instance()->removeBillingProject(project,billing,contributory);

    QSqlQuery q;
    q.prepare("SELECT * from BillingProject "
              "WHERE idProject=1 "
              "AND idBilling=1 "
              "AND idContributory=1");

    if(!q.exec()) {
        throw new DbException(
                    "Impossible de selectionner le BillingProject",
                    "BddBillingDatabaseTest::addBillingProject",
                    "Databases::Database::instance()->lastError(q)",
                    1.3);
    }
    q.first();
    QVERIFY(q.isNull(0) &&
            q.isNull(1) &&
            q.isNull(2));
}

void BillingDatabaseTest::getMaxBillingNumber()
{
    QCOMPARE(29, Databases::BillingDatabase::instance()->getMaxBillingNumber());
}

void BillingDatabaseTest::getMaxQuoteNumber()
{
     QCOMPARE(51, Databases::BillingDatabase::instance()->getMaxQuoteNumber());
}

