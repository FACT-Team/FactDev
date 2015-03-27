#include "projectmodeltest.h"

#include "database/projectdatabase.h"
#include "gui/widgets/widgetsmodels/projectstablemodel.h"
ProjectModelTest::ProjectModelTest()
{
    p1.setName("vehicula");
    p1.setDescription("a, facilisis non, bibendum sed, est. Nunc laoreet lectus quis massa. Mauris vestibulum, neque sed dictum eleifend, nunc risus varius orci, in consequat enim diam");
    p1.setDailyRate(13);

    p2.setName("vehicula");
    p2.setDescription("a, facilisis non, bibendum sed, est. Nunc laoreet lectus quis massa. Mauris vestibulum, neque sed dictum eleifend, nunc risus varius orci, in consequat enim diam");
    p2.setDailyRate(13);

    Project p3("Nom");
    QVariantHash q = p3.getDataMap();
    bool b = p3 < p2;
}

void ProjectModelTest::equals1()
{
    try {
        p1.setCustomer(QSharedPointer<Customer>(new Customer(14)));
        p2.setCustomer(QSharedPointer<Customer>(new Customer(14)));

        QVERIFY(p1 == p2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}
void ProjectModelTest::equals2()
{
    try {
        Project p;
        p.setDailyRate(13);
        p.setName("Not the same name");
        p.setCustomer(QSharedPointer<Customer>(new Customer(14)));

        p.setDescription("a, facilisis non, bibendum sed, est. Nunc laoreet lectus quis massa. Mauris vestibulum, neque sed dictum eleifend, nunc risus varius orci, in consequat enim diam");
        QVERIFY(!(p == p2));
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}
void ProjectModelTest::notEquals()
{
    try {
        Project p;
        p.setDailyRate(13);
        p.setName("Not the same name");
        p.setCustomer(QSharedPointer<Customer>(new Customer(14)));

        p.setDescription("a, facilisis non, bibendum sed, est. Nunc laoreet lectus quis massa. Mauris vestibulum, neque sed dictum eleifend, nunc risus varius orci, in consequat enim diam");

        QVERIFY(p != p2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ProjectModelTest::commitInsert()
{
    try {
        p1.setId(0);
        p1.commit();
        Project* p2 = Databases::ProjectDatabase::instance()->getProject(p1.getId());
        QVERIFY(*p2 == p1);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ProjectModelTest::commitUpdate()
{
    try {
        int id = Databases::ProjectDatabase::instance()->addProject(p1);
        p1.setName("NEW NAME");
        p1.setId(id);
        p1.setToRemoved(false);
        p1.commit();
        Project* p2 = Databases::ProjectDatabase::instance()->getProject(id);
        QVERIFY(p2 != 0);
        QVERIFY(*p2 == p1);
        p1.setToRemoved(true);
        p1.commit();
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}


void ProjectModelTest::hydrat()
{
    try {
        Project p2 = Project(1);
        p1.setName("vehicula");
        p1.setDescription("a, facilisis non, bibendum sed, est. Nunc laoreet lectus quis massa. Mauris vestibulum, neque sed dictum eleifend, nunc risus varius orci, in consequat enim diam");
        p1.setDailyRate(13);

        QVERIFY(p1 == p2);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ProjectModelTest::remove()
{
    try {
        p1.setToRemoved(true);
        p1.commit();
        QVERIFY(Databases::ProjectDatabase::instance()->getProject(p1.getId()) == NULL);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ProjectModelTest::getProjectsTable(void) {
    try {
        WdgModels::ProjectsTableModel* w = Databases::ProjectDatabase::instance()->getProjectsTable(1);

        for(Project p : w->getProjects()) {
            switch(p.getId()) {
            case 9:
            case 14:
            case 47:
            case 48:
                QVERIFY(true);
                break;
            default:
                QVERIFY2(false, QString("Oups: "+QString::number(p.getId())).toStdString().c_str());
            }

        }
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void ProjectModelTest::turnoverComputeTest() {
    Project p1(28);
    Project p2(42);
    Project p3(23);

    QCOMPARE(p1.getCost(), 84.0);
    QCOMPARE(p2.getCost(), 15.586);
    QCOMPARE(p3.getCost(), 521.64);
}
