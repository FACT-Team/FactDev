#ifndef CUSTOMERDATABASETEST_H
#define CUSTOMERDATABASETEST_H
#include <QtTest/QtTest>
#include "QTestRunner/testrunner.h"

#include "models/customer.h"

class CustomerDatabaseTest : public QObject
{
    Q_OBJECT
public:
    CustomerDatabaseTest();
private slots:
    void insert();
    void remove();
    void update();
    void selectCustomerNotFound();
    void selectCustomerFound();
private:
    Customer c1;
    int _lastInsert;
};

DECLARE_TEST(CustomerDatabaseTest)

#endif // CUSTOMERDATABASETEST_H