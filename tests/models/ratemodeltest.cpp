#include "ratemodeltest.h"

RateModelTest::RateModelTest()
{

}

void RateModelTest::setHourly()
{
    _rate = Models::Rate();
    _rate.setHourlyRate(12.42);
    QCOMPARE(12.42, _rate.getHourlyRate());
    QCOMPARE(12.42 * _rate.getNbDailyHours(), _rate.getDailyRate());

    _rate = Models::Rate(13.37);
    QCOMPARE(13.37, _rate.getHourlyRate());
    QCOMPARE(13.37 * _rate.getNbDailyHours(), _rate.getDailyRate());
}

void RateModelTest::setDaily()
{
    _rate = Models::Rate();
    _rate.setDailyRate(100.5);
    QCOMPARE(100.5, _rate.getDailyRate());
    QCOMPARE(100.5 / _rate.getNbDailyHours(), _rate.getHourlyRate());
}

void RateModelTest::getHourly()
{
    _rate = Models::Rate(12);
    QCOMPARE(12.0, _rate.getHourlyRate());
}

void RateModelTest::getDaily()
{
    _rate = Models::Rate();
    _rate.setDailyRate(105.42);
    QCOMPARE(105.42, _rate.getDailyRate());

}

void RateModelTest::setHourlyNotLegal()
{
    _rate = Models::Rate();
    _rate.setHourlyRate(2.42);
    //QCOMPARE(_rate.getLegalRate(), _rate.getHourlyRate());
    //QCOMPARE(_rate.getLegalRate() * _rate.getNbDailyHours(), _rate.getDailyRate());

    _rate = Models::Rate(8.42);
    //QCOMPARE(_rate.getLegalRate(), _rate.getHourlyRate());
    //QCOMPARE(_rate.getLegalRate() * _rate.getNbDailyHours(), _rate.getDailyRate());

}

void RateModelTest::setDailyNotLegal()
{
    _rate = Models::Rate();
    _rate.setDailyRate(50.5);
//    QCOMPARE(_rate.getLegalRate()*_rate.getNbDailyHours(), _rate.getDailyRate());
//    QCOMPARE(_rate.getLegalRate()*_rate.getNbDailyHours() / _rate.getNbDailyHours(), _rate.getHourlyRate());
}
