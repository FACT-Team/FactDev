#ifndef CONTRIBUTORYLISTTEST_H
#define CONTRIBUTORYLISTTEST_H
#include "QTestRunner/testrunner.h"

#include "models/contributorieslist.h"

#include "utils/double.h"
using namespace Models;

class ContributoryListTest : public QObject
{
    Q_OBJECT
public:
    ContributoryListTest();
private slots:
    void addProject();
    void getPriceTest();
    void getPriceOfProject();

    void getQuantityTest();
    void getQuantityOfProjectTest();

    void testMonthQuantity();
    void testDifferentUnit();

    void testInsert();
private:
    void setup();

    Project* p1;
    Project* p2;
    Project* p3;

    Contributory c1;
    Contributory c2;
    Contributory c3;
    Contributory c4;
    Contributory c5;
    Contributory c6;
};
DECLARE_TEST(ContributoryListTest)

#endif // CONTRIBUTORYLISTTEST_H
