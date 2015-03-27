#ifndef STATISTICMODELTEST_H
#define STATISTICMODELTEST_H
#include "QTestRunner/testrunner.h"
#include "models/statistics.h"


class StatisticModelTest : public QObject
{
    Q_OBJECT
public:
    StatisticModelTest();

private slots:
    void getTurnoverBeetweenDates();
    void getGlobalTurnover();

private:
    Statistics s1;
    Statistics s2;
};

DECLARE_TEST(StatisticModelTest)

#endif // STATISTICMODELTEST_H
