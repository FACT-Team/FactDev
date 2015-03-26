#include "customermodeltest.h"
#include "database/customerdatabase.h"
#include "database/userdatabase.h"

void CustomerModelTest::setup()
{
    c1.setAddress("Address");
    c1.setCity("Toulouse");
    c1.setCompany("Mine");
    c1.setCountry("France");
    c1.setEmail("coucou@truc.fr");
    c1.setFax("0102030405");
    c1.setFirstname("John");
    c1.setLastname("Doe");
    c1.setId(42);
    c1.setMobilePhone("02030405");
    c1.setPhone("03040506");
    c1.setPostalCode("31500");

    c2.setAddress("Address");
    c2.setCity("Toulouse");
    c2.setCompany("Mine");
    c2.setCountry("France");
    c2.setEmail("coucou@truc.fr");
    c2.setFax("0102030405");
    c2.setFirstname("John");
    c2.setLastname("Doe");
    c2.setId(42);
    c2.setMobilePhone("02030405");
    c2.setPhone("03040506");
    c2.setPostalCode("31500");
}

CustomerModelTest::CustomerModelTest()
{
}

void CustomerModelTest::equals1()
{
    setup();

    QVERIFY(c1 == c2);
}
void CustomerModelTest::equals2()
{
    c1.setAddress("Not the same address");

    QVERIFY(!(c1 == c2));
}
void CustomerModelTest::notEquals()
{
    QVERIFY(c1 != c2);
}

void CustomerModelTest::commitInsert()
{
    c1.setId(0);
    try {
        c1.commit();
        QSharedPointer<Customer> c2 = Databases::CustomerDatabase::instance()->getCustomer(c1.getId());
        QVERIFY(*c2 == c1);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void CustomerModelTest::commitUpdate()
{
    try {
        int id = Databases::CustomerDatabase::instance()->addCustomer(c1);
        c1.setAddress("NEW ADDRESS");
        c1.setId(id);
        c1.setToRemoved(false);
        c1.commit();
        QSharedPointer<Customer> c2 = Databases::CustomerDatabase::instance()->getCustomer(id);

        QVERIFY(c2 != 0);
        QVERIFY(*c2 == c1);
        c1.setToRemoved(true);
        c1.commit();
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void CustomerModelTest::commitRemove()
{
    int id = Databases::CustomerDatabase::instance()->addCustomer(c1);
    c1.setAddress("NEW ADDRESS");
    c1.setId(id);
    c1.setToRemoved(true);
    c1.commit();
    QVERIFY(Databases::CustomerDatabase::instance()->getCustomer(c1.getId()) == NULL);
}


void CustomerModelTest::hydrat()
{
    try {
        Customer c2 = Customer(1);
        c1.setFirstname("Jonah");
        c1.setLastname("Boyle");
        c1.setCompany("Sit Amet Ornare Consulting");
        c1.setAddress("P.O. Box 592, 3094 Vel Rd.");
        c1.setPostalCode("9924BN");
        c1.setCity("Miraj");
        c1.setCountry("Greece");
        c1.setEmail("pede.ultrices@atnisiCum.org");
        c1.setPhone("01 02 03 04 05");
        c1.setMobilePhone("02 03 04 05 06");
        c1.setFax("05 35 11 79 67");

        QVERIFY(c1 == c2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void CustomerModelTest::remove()
{
    try {
        c1.remove();
        QVERIFY(Databases::CustomerDatabase::instance()->getCustomer(c1.getId()) == NULL);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void CustomerModelTest::getPath()
{
    QVERIFY(c1.getPath() ==QDir::homePath() +"/"+QStandardPaths::displayName(QStandardPaths::DocumentsLocation)+
            "/FactDev/SIT AMET ORNARE CONSULTING Boyle Jonah");
}

void CustomerModelTest::getNameFolder()
{
    QVERIFY(c1.getNameFolder() == "SIT AMET ORNARE CONSULTING Boyle Jonah");
}

void CustomerModelTest::turnoverComputeTest() {
    Customer c(17);
    QCOMPARE(Utils::Double::round(c1.getTurnover(), 2), 0.);
    Customer c2(8);
    QCOMPARE(Utils::Double::round(c2.getTurnover(), 2), 147.16);
}
