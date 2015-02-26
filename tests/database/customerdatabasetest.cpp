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
    c1.setFirstnameReferent("John");
    c1.setLastnameReferent("Doe");
    c1.setId(42);
    c1.setMobilePhone("02030405");
    c1.setPhone("03040506");
    c1.setPostalCode("31500");

}

void CustomerDatabaseTest::insert()
{
    _lastInsert = Databases::CustomerDatabase::instance()->addCustomer(c1);
    QSharedPointer<Customer> c2 = Databases::CustomerDatabase::instance()->getCustomer(_lastInsert);
    QVERIFY(c1 == *c2);
}

void CustomerDatabaseTest::remove()
{
    Databases::CustomerDatabase::instance()->removeCustomer(_lastInsert);
    QSharedPointer<Customer> c2 = Databases::CustomerDatabase::instance()->getCustomer(_lastInsert);
    QVERIFY(c2 == 0);
}

void CustomerDatabaseTest::update()
{
    _lastInsert = Databases::CustomerDatabase::instance()->addCustomer(c1);
    c1.setId(_lastInsert);
    c1.setAddress("New address");
    c1.setFirstnameReferent("New name !");
    Databases::CustomerDatabase::instance()->updateCustomer(c1);
    QSharedPointer<Customer> c2 = Databases::CustomerDatabase::instance()->getCustomer(_lastInsert);
    QVERIFY(*c2 == c1);
}

void CustomerDatabaseTest::selectCustomerNotFound()
{
    QVERIFY(Databases::CustomerDatabase::instance()->getCustomer(321654) == NULL);
}

void CustomerDatabaseTest::selectCustomerFound()
{
    // Is assumed the id 1 contains tests :
    // INSERT INTO `Customer` (`firstnameReferent`,`lastnameReferent`,`company`,`address`,`postalCode`,`city`,`country`,`email`,`phone`,`mobilePhone`,`fax`) VALUES ("Jonah","Boyle","Sit Amet Ornare Consulting","P.O. Box 592, 3094 Vel Rd.","9924BN","Miraj","Greece","pede.ultrices@atnisiCum.org","01 02 03 04 05","02 03 04 05 06","05 35 11 79 67");
    QSharedPointer<Customer> c2 = Databases::CustomerDatabase::instance()->getCustomer(1);
    c1.setFirstnameReferent("Jonah");
    c1.setLastnameReferent("Boyle");
    c1.setCompany("Sit Amet Ornare Consulting");
    c1.setAddress("P.O. Box 592, 3094 Vel Rd.");
    c1.setPostalCode("9924BN");
    c1.setCity("Miraj");
    c1.setCountry("Greece");
    c1.setEmail("pede.ultrices@atnisiCum.org");
    c1.setPhone("01 02 03 04 05");
    c1.setMobilePhone("02 03 04 05 06");
    c1.setFax("05 35 11 79 67");

    QVERIFY(c1 == *c2);
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

//void CustomerDatabaseTest::getCustomerTreeException()
//{
//    try {
//        Databases::CustomerDatabase::instance()->getTree("FROM Billing");
//        QFAIL("Exception not thrown");
//    } catch(DbException*) {
//        QVERIFY(true);
//    }

//    try {
//        Databases::CustomerDatabase::instance()->getTree("");
//        QVERIFY(true);
//    } catch(DbException*) {
//        QFAIL("Exception not thrown");
//    }
//}


