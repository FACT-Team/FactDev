#include "customerdatabasetest.h"
#include "database/customerdatabase.h"

CustomerDatabaseTest::CustomerDatabaseTest()
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

}

void CustomerDatabaseTest::insert()
{
    try {
        _lastInsert = Databases::CustomerDatabase::instance()->addCustomer(c1);
        QSharedPointer<Customer> c2 = Databases::CustomerDatabase::instance()->getCustomer(_lastInsert);
        QVERIFY(c1 == *c2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void CustomerDatabaseTest::remove()
{
    try {
        Databases::CustomerDatabase::instance()->removeCustomer(_lastInsert);
        QSharedPointer<Customer> c2 = Databases::CustomerDatabase::instance()->getCustomer(_lastInsert);
        QVERIFY(c2 == 0);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void CustomerDatabaseTest::update()
{
    try {
        _lastInsert = Databases::CustomerDatabase::instance()->addCustomer(c1);
        c1.setId(_lastInsert);
        c1.setAddress("New address");
        c1.setFirstname("New name !");
        Databases::CustomerDatabase::instance()->updateCustomer(c1);
        QSharedPointer<Customer> c2 = Databases::CustomerDatabase::instance()->getCustomer(_lastInsert);
        QVERIFY(*c2 == c1);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void CustomerDatabaseTest::selectCustomerNotFound()
{
    try {
        QVERIFY(Databases::CustomerDatabase::instance()->getCustomer(321654) == NULL);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void CustomerDatabaseTest::selectCustomerFound()
{
    // Is assumed the id 1 contains tests :
    // INSERT INTO `Customer` (`firstnameReferent`,`lastnameReferent`,`company`,`address`,`postalCode`,`city`,`country`,`email`,`phone`,`mobilePhone`,`fax`) VALUES ("Jonah","Boyle","Sit Amet Ornare Consulting","P.O. Box 592, 3094 Vel Rd.","9924BN","Miraj","Greece","pede.ultrices@atnisiCum.org","01 02 03 04 05","02 03 04 05 06","05 35 11 79 67");

    try {
        QSharedPointer<Customer> c2 = Databases::CustomerDatabase::instance()->getCustomer(1);
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

        QVERIFY(c2 != 0);
        QVERIFY(c1 == *c2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void CustomerDatabaseTest::getCustomerTableException()
{
    try {
        Databases::CustomerDatabase::instance()->getCustomersTable("FROM Billing");
        QFAIL("Exception not thrown");
    } catch(DbException*) {
        QVERIFY(true);
    }

    try {
        Databases::CustomerDatabase::instance()->getCustomersTable("");
        QVERIFY(true);
    } catch(DbException*) {
        QFAIL("Exception not thrown");
    }
}

void CustomerDatabaseTest::getCustomerTreeException()
{
    try {
        Databases::CustomerDatabase::instance()->getTree("FROM Billing");
        QFAIL("Exception not thrown");
    } catch(DbException*) {
        QVERIFY(true);
    }

    /*try {
        Databases::CustomerDatabase::instance()->getTree("");
        QVERIFY(true);
    } catch(DbException*) {
        QFAIL("Exception not thrown");
    }*/
}

void CustomerDatabaseTest::getNbCustomersTest() {
    try {
        QCOMPARE(Databases::CustomerDatabase::instance()->getNbCustomers(), 22);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}
