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
    b1->setIsPaid(false);
}

void BillingDatabaseTest::insert()
{
    setup();
    try {
        _lastInsert = Databases::BillingDatabase::instance()->addBilling(*b1);
        Billing* b2 = Databases::BillingDatabase::instance()->getBilling(_lastInsert);

        QVERIFY(*b1 == *b2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void BillingDatabaseTest::remove()
{
    try {
        Databases::BillingDatabase::instance()->removeBilling(_lastInsert);
        Billing *b2 = Databases::BillingDatabase::instance()->getBilling(_lastInsert);
        QVERIFY(b2 == 0);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void BillingDatabaseTest::update()
{
    try {
        _lastInsert = Databases::BillingDatabase::instance()->addBilling(*b1);
        b1->setId(_lastInsert);
        b1->setTitle("Paladin donut");
        b1->setDescription("Création des donuts platines");
        Databases::BillingDatabase::instance()->updateBilling(*b1);
        Billing *b2 = Databases::BillingDatabase::instance()->getBilling(_lastInsert);
        QVERIFY(*b1 == *b2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }

}

void BillingDatabaseTest::selectBillingNotFound()
{
    setup();
    try {
        QVERIFY(Databases::BillingDatabase::instance()->getBilling(321654) == NULL);
    } catch(DbException* e) {
        QFAIL(e->what());
    }

}

void BillingDatabaseTest::selectBillingFound()
{
    try {
        Billing *b3 = Databases::BillingDatabase::instance()->getBilling(1);
        b1->setId(1);
        b1->setTitle("Coucou");
        b1->setDescription("Mon super devis de la mort qui rox du poulet");
        b1->setNumber(1);
        b1->setIsBilling(false);
        b1->setDate(QDate(2015,02,13));

        QVERIFY(*b1 == *b3);
    } catch(DbException* e) {
        QFAIL(e->what());
    }

}

void BillingDatabaseTest::addBillingProject()
{
    int project = 1, billing = 1, contributory = 1;
    try {
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
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void BillingDatabaseTest::removeBillingProject()
{
    int project = 1, billing = 1, contributory = 1;
    try {
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
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void BillingDatabaseTest::getMaxBillingNumber()
{
    try {
        QCOMPARE(29, Databases::BillingDatabase::instance()->getMaxBillingNumber());
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void BillingDatabaseTest::getMaxQuoteNumber()
{
    try {
        QCOMPARE(51, Databases::BillingDatabase::instance()->getMaxQuoteNumber());
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void BillingDatabaseTest::getMaxBillingNumberOfCustomer()
{
    try {
        //client 17
        QCOMPARE(5, Databases::BillingDatabase::instance()->getMaxBillingNumberOfCustomer(17));
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void BillingDatabaseTest::getMaxQuoteNumberOfCustomer()
{
    try {
        QCOMPARE(4, Databases::BillingDatabase::instance()->getMaxQuoteNumberOfCustomer(17));
    } catch(DbException* e) {
        QFAIL(e->what());
    }

}

void BillingDatabaseTest::getBilling()
{
    try {
        QSqlQuery q;

        q.prepare("SELECT idBilling, title, description, number,"
                  "isBilling, date, isPaid "
                  "FROM Billing "
                  "WHERE idBilling = :idBilling ");

        q.bindValue(":idBilling",1);
        if(!q.exec()) {
            throw new DbException(
                        "Impossible de récupérer les Factures/Devis",
                        "BddCustomer::getBillingsTable",
                        "Databases::Database::lastError(q)",
                        1.3);
        }

        q.first();

        Billing b = *Databases::BillingDatabase::instance()->getBilling(q);

        bool test = b.getId() == 1
                && b.getTitle() == "Coucou"
                && b.getDescription() == "Mon super devis de la mort qui rox du poulet"
                && b.getNumber() == 1
                && b.getDate().year() == 2015
                && b.getDate().day() == 13
                && b.getDate().month() == 2
                && b.isPaid() == 1;
        QVERIFY(b.getId() == 1
                && b.getTitle() == "Coucou"
                && b.getDescription() == "Mon super devis de la mort qui rox du poulet"
                && b.getNumber() == 1
                && b.getDate().year() == 2015
                && b.getDate().day() == 13
                && b.getDate().month() == 2
                && b.isPaid() == 1);
    } catch(DbException* e) {
        QFAIL(e->what());
    }

}

void BillingDatabaseTest::getAllBillingsOnly()
{
 bool billing = true;

 for (Billing b : Databases::BillingDatabase::instance()->getAllBillingsOnly(23)) {
     if (!b.isBilling()) {
         billing = false;
     }
 }

 QVERIFY(billing);

}

void BillingDatabaseTest::getBillingsBetweenDates()
{
    try {
    QList<Billing> bills;
    QList<Billing> bills2;
    bills.append(Billing(1));
    bills.append(Billing(2));

    bills2 = Databases::BillingDatabase::instance()
            ->getBillingsBetweenDates(QDate(2015,2,13),QDate(2035,2,13));


    QCOMPARE(bills2.count(), 1);
    QVERIFY(bills2.first().getDate() == QDate(2015,2,13));
    QVERIFY(bills2.first().getTitle() == "Coucou");
    QVERIFY(bills2.first().getDescription() == "Mon super devis de la mort qui rox du poulet");
//    QVERIFY(bills2.last().getDate() == QDate(2015,2,13));
//    QVERIFY(bills2.last().getTitle() == "Bonjour");
//    QVERIFY(bills2.last().getDescription() == "Manger du poney");
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

