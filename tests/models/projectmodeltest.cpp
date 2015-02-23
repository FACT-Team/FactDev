#include "projectmodeltest.h"

#include "database/projectdatabase.h"
ProjectModelTest::ProjectModelTest()
{
    p1.setName("vehicula");
    p1.setDescription("a, facilisis non, bibendum sed, est. Nunc laoreet lectus quis massa. Mauris vestibulum, neque sed dictum eleifend, nunc risus varius orci, in consequat enim diam");
    p1.setDailyRate(13);

    p2.setName("vehicula");
    p2.setDescription("a, facilisis non, bibendum sed, est. Nunc laoreet lectus quis massa. Mauris vestibulum, neque sed dictum eleifend, nunc risus varius orci, in consequat enim diam");
    p2.setDailyRate(13);
}

void ProjectModelTest::equals1()
{
    p1.setCustomer(QSharedPointer<Customer>(new Customer(14)));
    p2.setCustomer(QSharedPointer<Customer>(new Customer(14)));

    QVERIFY(p1 == p2);
}
void ProjectModelTest::equals2()
{
    p1.setName("Not the same name");
    QVERIFY(!(p1 == p2));
}
void ProjectModelTest::notEquals()
{
    QVERIFY(p1 != p2);
}

void ProjectModelTest::commitInsert()
{
    p1.setId(0);
    p1.commit();
    Project* p2 = Databases::ProjectDatabase::instance()->getProject(p1.getId());
    QVERIFY(*p2 == p1);
}

void ProjectModelTest::commitUpdate()
{
    int id = Databases::ProjectDatabase::instance()->addProject(p1);
    p1.setName("NEW NAME");
    p1.setId(id);
    p1.commit();
    Project* p2 = Databases::ProjectDatabase::instance()->getProject(id);
    QVERIFY(*p2 == p1);
}


void ProjectModelTest::hydrat()
{
    Project p2 = Project(1);
    p1.setName("vehicula");
    p1.setDescription("a, facilisis non, bibendum sed, est. Nunc laoreet lectus quis massa. Mauris vestibulum, neque sed dictum eleifend, nunc risus varius orci, in consequat enim diam");
    p1.setDailyRate(13);

    QVERIFY(p1 == p2);
}

void ProjectModelTest::remove()
{
    p1.remove();
    QVERIFY(Databases::ProjectDatabase::instance()->getProject(p1.getId()) == NULL);
}
