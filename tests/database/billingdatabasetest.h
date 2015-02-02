#ifndef BILLINGDATABASETEST_H
#define BILLINGDATABASETEST_H
#include <QtTest/QtTest>
#include "QTestRunner/testrunner.h"

#include "models/billing.h"

class BillingDatabaseTest : public QObject
{
    Q_OBJECT
public:
     BillingDatabaseTest();

private slots:
     void insert();
     void remove();
     void update();
     void selectBillingNotFound();
     void selectBillingFound();
private:
     Billing b1;
     int _lastInsert;
};

DECLARE_TEST(BillingDatabaseTest)

#endif // BILLINGDATABASETEST_H
