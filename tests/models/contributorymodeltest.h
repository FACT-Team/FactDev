#ifndef CONTRIBUTORYMODELTEST_H
#define CONTRIBUTORYMODELTEST_H
#include "QTestRunner/testrunner.h"

#include "models/contributory.h"

#include "utils/double.h"
using namespace Models;

class ContributoryModelTest : public QObject
{
    Q_OBJECT
public:
    ContributoryModelTest();

private slots:
    void equals1();
    void equals2();
    void notEquals();

    void commitUpdate();
    void commitInsert();
    void hydrat();
    void commitRemove();

    void getRateTest();
private:
    void setup(void);

    Contributory c1;
    Contributory c2;

};
DECLARE_TEST(ContributoryModelTest)

#endif // CONTRIBUTORYMODELTEST_H
