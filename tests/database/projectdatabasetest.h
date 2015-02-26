#ifndef PROJECTDATABASETEST_H
#define PROJECTDATABASETEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "QTestRunner/testrunner.h"
#include "models/project.h"
class ProjectDatabaseTest : public QObject
{
    Q_OBJECT

public:
    ProjectDatabaseTest();

private slots:
    void insert();
    void remove();
    void update();
    void selectCustomerNotFound();
    void selectCustomerFound();
    void getNbProjects();
    void getNbProjectsForACustomer();
private:
    Models::Project p1;
    int _lastInsert;
};

DECLARE_TEST(ProjectDatabaseTest)

#endif // PROJECTDATABASETEST_H
