#include "customermodeltest.h"

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

void CustomerModelTest::commit()
{
    // TODO implements me!
    QVERIFY(false);
}

void CustomerModelTest::hydrat()
{
    // TODO implements me!
    QVERIFY(false);
}

void CustomerModelTest::remove()
{
    // TODO implements me!
    QVERIFY(false);
}
