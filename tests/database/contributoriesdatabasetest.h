#ifndef CONTRIBUTORIESDATABASETEST_H
#define CONTRIBUTORIESDATABASETEST_H
#include <QtTest/QtTest>
#include "QTestRunner/testrunner.h"

#include "models/contributory.h"

using namespace Models;
class ContributoriesDatabaseTest : public QObject
{
    Q_OBJECT
public:
    ContributoriesDatabaseTest();

private slots:
    void getContributoriesByBilling();
    void insert();
    void remove();
    void update();
    void selectContributoryNotFound();
    void selectContributoryFound();
private:
    Contributory* c1;
    int _lastInsert;

    void setup();
};
DECLARE_TEST(ContributoriesDatabaseTest)

#endif // CONTRIBUTORIESDATABASETEST_H
