#include "userdatabasetest.h"

#include "database/userdatabase.h"

UserDatabaseTest::UserDatabaseTest()
{

}

void UserDatabaseTest::getUserTest()
{
    try {
        Models::User* u1 = Databases::UserDatabase::instance()->getUser();
        Models::User u2;
        u2.setId(1);
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
        u2.setFax("");
        u1->setFax("");

        bool b = *u1 == u2;
        QVERIFY(*u1 == u2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }

}

void UserDatabaseTest::noGetUserTest()
{
    try {
        Models::User* u1 = Databases::UserDatabase::instance()->getUser(42);

        QVERIFY(u1 == 0);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}
void UserDatabaseTest::updateUserTest()
{
    try {
        Models::User* u1 = Databases::UserDatabase::instance()->getUser();
        u1->setLastname("Beau No");
        Databases::UserDatabase::instance()->updateUser(*u1);
        Models::User* u2 = Databases::UserDatabase::instance()->getUser();
        u2->setId(1);
        u2->setFirstname("Jean");
        u2->setLastname("Beau No");
        u2->setCompany("FleuryMigeon");
        u2->setTitle("Artisan Développeur");
        u2->setAddress("42 Route de bayonne");
        u2->setPostalCode("31000");
        u2->setCity("Toulouse");
        u2->setEmail("jean.bonneau@fleury-migeon.com");
        u2->setMobilePhone("0616641337");
        u2->setPhone("0836656565");
        u2->setNoSiret("12345678912340");

        QVERIFY(*u1 == *u2);

    } catch(DbException* e) {
        QFAIL(e->what());
    }

}
