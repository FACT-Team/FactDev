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
    p1.setCustomer(QSharedPointer<Customer>(new Customer(14)));
    p2.setCustomer(QSharedPointer<Customer>(new Customer(14)));

    QVERIFY(p1 == p2);
}
void ProjectModelTest::equals2()
{
    Project p;
    p.setDailyRate(13);
    p.setName("Not the same name");
    p.setCustomer(QSharedPointer<Customer>(new Customer(14)));

    p.setDescription("a, facilisis non, bibendum sed, est. Nunc laoreet lectus quis massa. Mauris vestibulum, neque sed dictum eleifend, nunc risus varius orci, in consequat enim diam");
    QVERIFY(!(p == p2));
}
void ProjectModelTest::notEquals()
{
    Project p;
    p.setDailyRate(13);
    p.setName("Not the same name");
    p.setCustomer(QSharedPointer<Customer>(new Customer(14)));

    p.setDescription("a, facilisis non, bibendum sed, est. Nunc laoreet lectus quis massa. Mauris vestibulum, neque sed dictum eleifend, nunc risus varius orci, in consequat enim diam");

    QVERIFY(p != p2);
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
    p1.setToRemoved(true);
    p1.commit();
    QVERIFY(Databases::ProjectDatabase::instance()->getProject(p1.getId()) == NULL);
}
void ProjectModelTest::getProjectsTable(void) {
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
}
