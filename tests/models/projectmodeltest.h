#ifndef PROJECTMODELTEST_H
#define PROJECTMODELTEST_H
#include "QTestRunner/testrunner.h"
#include "models/project.h"

using namespace Models;


class ProjectModelTest : public QObject
{
    Q_OBJECT

public:
    ProjectModelTest();

private slots:
    void equals1();
    void equals2();
    void notEquals();

    void commitUpdate();
    void commitInsert();
    void hydrat();
    void remove();

private:
    Project p1;
    Project p2;
};
DECLARE_TEST(ProjectModelTest)

#endif // PROJECTMODELTEST_H