#ifndef CONTRIBUTORIESDATABASETEST_H
#define CONTRIBUTORIESDATABASETEST_H

#include <QObject>
#include "QTestRunner/testrunner.h"

class ContributoriesDatabaseTest : public QObject
{
    Q_OBJECT

private slots:
    void getContributoriesByBilling();
};
DECLARE_TEST(ContributoriesDatabaseTest)

#endif // CONTRIBUTORIESDATABASETEST_H
