#include "usermodeltest.h"
#include "database/userdatabase.h"
UserModelTest::UserModelTest()
{
    u1.setFirstname("Jean");
    u1.setLastname("Bonneau");
    u1.setCompany("FleuryMigeon");
    u1.setTitle("Artisan Développeur");
    u1.setAddress("42 Route de bayonne");
    u1.setPostalCode("31000");
    u1.setCity("Toulouse");
    u1.setEmail("jean.bonneau@fleury-migeon.com");
    u1.setMobilePhone("0616641337");
    u1.setPhone("0836656565");
    u1.setNoSiret("12345678912340");
    u1.setPdflatexPath("pdflatex");

    u2.setFirstname("Jean");
    u2.setLastname("Bonneau");
    u2.setCompany("FleuryMigeon");
    u2.setTitle("Artisan Développeur");
    u2.setAddress("42 Route de bayonne");
    u2.setPostalCode("31000");
    u2.setCity("Toulouse");
    u2.setEmail("jean.bonneau@fleury-migeon.com");
    u2.setMobilePhone("0616641337");
    u2.setPhone("0836656565");
    u2.setNoSiret("12345678912340");
    u2.setPdflatexPath("pdflatex");

}

void UserModelTest::equals1()
{
    QVERIFY(u1 == u2);
}

void UserModelTest::equals2()
{
    u1.setFirstname("Not same firstname");
    QVERIFY(!(u1 == u2));
}

void UserModelTest::notEquals()
{
    u1.setFirstname("Not same firstname");
    QVERIFY(u1 != u2);
}

void UserModelTest::commitUpdate()
{
    u1.setId(1);
    u1.setFirstname("TESTOUILLE");

    try {
        QString a = u1.getFirstname();
        u1.setToRemoved(false);
        u1.commit();
        QString b = u1.getFirstname();
        u2 = *(Databases::UserDatabase::instance()->getUser(u1.getId()));
        QVERIFY(u1 == u2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void UserModelTest::hydrat()
{
    try {
        User u1(1);
        u2.setFirstname("TESTOUILLE");
        u2.setLastname("Bonneau");
        u2.setCompany("FleuryMigeon");
        u2.setTitle("Artisan Développeur");
        u2.setAddress("42 Route de bayonne");
        u2.setPostalCode("31000");
        u2.setCity("Toulouse");
        u2.setEmail("jean.bonneau@fleury-migeon.com");
        u2.setMobilePhone("0616641337");
        u2.setPhone("0836656565");
        u2.setNoSiret("12345678912340");
        QVERIFY(u1 == u2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void UserModelTest::commitRemove()
{
    u1.setToRemoved(true);
    u1.commit();
    QVERIFY(*Databases::UserDatabase::instance()->getUser() == u1);
}
