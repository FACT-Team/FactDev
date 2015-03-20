#include "projectdatabasetest.h"

#include "database/projectdatabase.h"

ProjectDatabaseTest::ProjectDatabaseTest()
{
    p1.setName("vehicula");
    p1.setDescription("a, facilisis non, bibendum sed, est. Nunc laoreet lectus quis massa. Mauris vestibulum, neque sed dictum eleifend, nunc risus varius orci, in consequat enim diam");
    p1.setDailyRate(13);
}

void ProjectDatabaseTest::insert()
{
    try {
        p1.setCustomer(QSharedPointer<Customer>(new Customer(14)));

        _lastInsert = Databases::ProjectDatabase::instance()->addProject(p1);
        Models::Project* p2 = Databases::ProjectDatabase::instance()->getProject(_lastInsert);
        QVERIFY(p1 == *p2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ProjectDatabaseTest::remove()
{
    try {
        Databases::ProjectDatabase::instance()->removeProject(_lastInsert);
        Project* p2 = Databases::ProjectDatabase::instance()->getProject(_lastInsert);
        QVERIFY(p2 == 0);
    } catch(DbException* e) {
        QFAIL(e->what());
    }

}

void ProjectDatabaseTest::update()
{
    try {
        _lastInsert = Databases::ProjectDatabase::instance()->addProject(p1);
        p1.setId(_lastInsert);
        p1.setName("New name");
        p1.setDescription("New description !");
        Databases::ProjectDatabase::instance()->updateProject(p1);
        Project* p2 = Databases::ProjectDatabase::instance()->getProject(_lastInsert);
        QVERIFY(*p2 == p1);
    } catch(DbException* e) {
        QFAIL(e->what());
    }

}

void ProjectDatabaseTest::selectCustomerNotFound()
{
    try {
        QVERIFY(Databases::ProjectDatabase::instance()->getProject(321654) == NULL);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ProjectDatabaseTest::selectCustomerFound()
{
    try {
        Project* p2 = Databases::ProjectDatabase::instance()->getProject(1);
        p1.setName("vehicula");
        p1.setDescription("a, facilisis non, bibendum sed, est. Nunc laoreet lectus quis massa. Mauris vestibulum, neque sed dictum eleifend, nunc risus varius orci, in consequat enim diam");
        p1.setDailyRate(13);

        QVERIFY(p1 == *p2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }

}

void ProjectDatabaseTest::getNbProjects()
{
    try {
        QCOMPARE(49, Databases::ProjectDatabase::instance()->getNbProjects());
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ProjectDatabaseTest::getNbProjectsForACustomer()
{
    try {
        QCOMPARE(4, Databases::ProjectDatabase::instance()->getNbProjectsForACustomer(1));
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}


