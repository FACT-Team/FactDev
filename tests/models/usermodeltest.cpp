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
    u1.setExtensionImage("jpg");
    QVERIFY(u1.getExtensionImage() == "jpg");

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

void UserModelTest::workLoadTest() {
    try {
        u1.setToRemoved(false);

        // I work ever and ever…
        u1.setNbDaysPerMonth(25);
        u1.setNbDaysPerWeek(6);
        u1.setNbHoursPerDay(10);

        QCOMPARE(u1.getNbDaysPerMonth(), 25.);
        QCOMPARE(u1.getNbDaysPerWeek(), 6.);
        QCOMPARE(u1.getNbHoursPerDay(), 10.);
        QCOMPARE(u1.getNbHoursPerMonth(), 250.);
        QCOMPARE(u1.getNbHoursPerWeek(), 60.);
        u1.commit();
        User u2(1);
        QCOMPARE(u2.getNbDaysPerMonth(), 25.);
        QCOMPARE(u2.getNbDaysPerWeek(), 6.);
        QCOMPARE(u2.getNbHoursPerDay(), 10.);
        QCOMPARE(u2.getNbHoursPerMonth(), 250.);
        QCOMPARE(u2.getNbHoursPerWeek(), 60.);


        // Reinit values for calculs tests
        u1.setNbDaysPerMonth(20);
        u1.setNbDaysPerWeek(5);
        u1.setNbHoursPerDay(7);
        QCOMPARE(u1.getNbHoursPerMonth(), 140.);
        QCOMPARE(u1.getNbHoursPerWeek(), 35.);

        u1.commit();
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}
