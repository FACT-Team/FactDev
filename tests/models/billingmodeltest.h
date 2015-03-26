#ifndef BILLINGMODELTEST_H
#define BILLINGMODELTEST_H
#include "QTestRunner/testrunner.h"

#include "models/billing.h"
#include "database/billingdatabase.h"

using namespace Models;
class BillingModelTest : public QObject
{
    Q_OBJECT
public:
    BillingModelTest();
private slots:
    void equals1();
    void equals2();
    void notEquals();

    void commitUpdate();
    void commitInsert();
    void hydrat();
    void hydratWithContributories();
    void commitRemove();
    void testSumQuantity();
private:
    Billing* b1;
    Billing* b2;
    void setup();
};
DECLARE_TEST(BillingModelTest)

#endif // BILLINGMODELTEST_H
