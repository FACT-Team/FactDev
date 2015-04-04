#include "statisticmodeltest.h"

StatisticModelTest::StatisticModelTest()
{
}

void StatisticModelTest::getTurnoverBeetweenDates() {
    QPair<int, double> turnover =
            Models::Statistics::getTurnoverBetweenDates(QDate(2015, 1, 1), QDate(2015, 3, 27));
    QVERIFY(turnover.first = 1);
    QVERIFY(turnover.second = 621.226);
}

void StatisticModelTest::getGlobalTurnover() {
    double d = Models::Statistics::getGlobalTurnover();
    QVERIFY(d = 621.226);
}
