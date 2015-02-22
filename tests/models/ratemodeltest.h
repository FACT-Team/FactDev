#ifndef RATEMODELTEST_H
#define RATEMODELTEST_H
#include "QTestRunner/testrunner.h"
#include "models/rate.h"

using namespace Models;

class RateModelTest : public QObject
{
    Q_OBJECT

public:
    RateModelTest();

private slots:
    void setHourly();
    void setDaily();
    void getHourly();
    void getDaily();

    void setHourlyNotLegal();
    void setDailyNotLegal();

private:
    Models::Rate _rate;
};

DECLARE_TEST(RateModelTest)


#endif // RATEMODELTEST_H
