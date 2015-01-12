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
    _lastInsert = CustomerDatabase::instance()->addCustomer(c1);
    Customer* c2 = CustomerDatabase::instance()->getCustomer(_lastInsert);
    QVERIFY(c1 == *c2);
}

void CustomerDatabaseTest::remove()
{
    CustomerDatabase::instance()->removeCustomer(_lastInsert);
    Customer* c2 = CustomerDatabase::instance()->getCustomer(_lastInsert);
    QVERIFY(c2 == 0);
}

void CustomerDatabaseTest::selectCustomerNotFound()
{
    QVERIFY(CustomerDatabase::instance()->getCustomer(321654) == NULL);
}

void CustomerDatabaseTest::selectCustomerFound()
{
    // Is assumed the id 0 contains tests :
    // INSERT INTO `Customer` VALUES ("Jonah","Boyle","Sit Amet Ornare Consulting","P.O. Box 592, 3094 Vel Rd.","9924BN","Miraj","Greece","pede.ultrices@atnisiCum.org","(672) 742-3297","(831) 972-1407","(535) 117-9670");
    Customer* c2 = CustomerDatabase::instance()->getCustomer(1);
    c1.setFirstnameReferent("Jonah");
    c1.setLastnameReferent("Boyle");
    c1.setCompany("Sit Amet Ornare Consulting");
    c1.setAddress("P.O. Box 592, 3094 Vel Rd.");
    c1.setPostalCode("9924BN");
    c1.setCity("Miraj");
    c1.setCountry("Greece");
    c1.setEmail("pede.ultrices@atnisiCum.org");
    c1.setMobilePhone("(831) 972-1407");
    c1.setPhone("(672) 742-3297");
    c1.setFax("(535) 117-9670");

    QVERIFY(c1 == *c2);
}
