#ifndef CUSTOMERDATABASETEST_H
#define CUSTOMERDATABASETEST_H
#include <QtTest/QtTest>
#include "QTestRunner/testrunner.h"

#include "models/customer.h"

using namespace Models;
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
    void getCustomerTableException();
    void getNbCustomersTest();
    void getCustomers();
private:
    Customer c1;
    int _lastInsert;
};

DECLARE_TEST(CustomerDatabaseTest)

#endif // CUSTOMERDATABASETEST_H
