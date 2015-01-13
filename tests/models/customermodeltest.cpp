#include "customermodeltest.h"
#include "database/customerdatabase.h"

CustomerModelTest::CustomerModelTest()
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

    c2.setAddress("Address");
    c2.setCity("Toulouse");
    c2.setCompany("Mine");
    c2.setCountry("France");
    c2.setEmail("coucou@truc.fr");
    c2.setFax("0102030405");
    c2.setFirstnameReferent("John");
    c2.setLastnameReferent("Doe");
    c2.setId(42);
    c2.setMobilePhone("02030405");
    c2.setPhone("03040506");
    c2.setPostalCode("31500");
}

void CustomerModelTest::equals1()
{
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
    c1.commit();
    Customer* c2 = CustomerDatabase::instance()->getCustomer(c1.getId());
    QVERIFY(*c2 == c1);
}

void CustomerModelTest::commitUpdate()
{
    int id = CustomerDatabase::instance()->addCustomer(c1);
    c1.setAddress("NEW ADDRESS");
    c1.setId(id);
    c1.commit();
    Customer* c2 = CustomerDatabase::instance()->getCustomer(id);
    QVERIFY(*c2 == c1);
}


void CustomerModelTest::hydrat()
{
    Customer c2 = Customer(1);
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

    QVERIFY(c1 == c2);
}

void CustomerModelTest::remove()
{
    c1.remove();
    QVERIFY(CustomerDatabase::instance()->getCustomer(c1.getId()) == NULL);

}