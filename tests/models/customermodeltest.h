#ifndef CUSTOMERMODELTEST_H
#define CUSTOMERMODELTEST_H
#include "QTestRunner/testrunner.h"
#include "models/customer.h"
#include "utils/double.h"

using namespace Models;
class CustomerModelTest : public QObject
{
    Q_OBJECT
public:
    CustomerModelTest();
    void setup();
private slots:
    void equals1();
    void equals2();
    void notEquals();

    void commitUpdate();
    void commitInsert();
    void commitRemove();
    void hydrat();
    void remove();
    void getPath();
    void getNameFolder();
    void turnoverComputeTest();
private:
    Customer c1;
    Customer c2;
};
DECLARE_TEST(CustomerModelTest)

#endif // CUSTOMERMODELTEST_H
