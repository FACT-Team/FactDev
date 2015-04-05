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
        QCOMPARE(4, Databases::ProjectDatabase::instance()->getNbProjects(1));
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ProjectDatabaseTest::getAllProjectsTest() {
    try {
        QList<Models::Project*> projects = Databases::ProjectDatabase::instance()->getAllProjects();
        QCOMPARE(projects.count(), 49);
        QCOMPARE(projects.first()->getId(), 1);
        QCOMPARE(projects[5]->getId(), 6);
        QCOMPARE(projects.last()->getId(), 50);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ProjectDatabaseTest::getCostProjectTest() {
    try {
        QList<Models::Project*> projects = Databases::ProjectDatabase::instance()->getAllProjects();
        double test = 0.0;
        for(Project* p : projects) {
            test += p->getCost();
        }
        QCOMPARE(Databases::ProjectDatabase::instance()->getCostProjects(projects), test);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ProjectDatabaseTest::getProjectOfCustomer() {
    try {
        QMap<int, Project> projects = Databases::ProjectDatabase::instance()->getProjectsOfCustomer(QSharedPointer<Customer>(new Customer(1)));
        QCOMPARE(projects.count(), 4);
        QCOMPARE(projects[9].getId(), 9);
        QCOMPARE(projects[14].getId(), 14);
        QCOMPARE(projects[47].getId(), 47);
        QCOMPARE(projects[48].getId(), 48);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}
