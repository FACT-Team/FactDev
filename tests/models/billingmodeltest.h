#ifndef BILLINGMODELTEST_H
#define BILLINGMODELTEST_H
#include "QTestRunner/testrunner.h"
#include <models/billing.h>

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
private:
    Billing b1;
    Billing b2;
};
DECLARE_TEST(BillingModelTest)

#endif // BILLINGMODELTEST_H
