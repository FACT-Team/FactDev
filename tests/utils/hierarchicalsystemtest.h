#ifndef HIERARCHICALSYSTEMTEST_H
#define HIERARCHICALSYSTEMTEST_H
#include "QTestRunner/testrunner.h"
#include "utils/hierarchicalsystem.h"

class HierarchicalSystemTest : public QObject
{
    Q_OBJECT

public:
    HierarchicalSystemTest();
private slots:
    void numberOfCustomersTest();
    void numberOfProjectsTest();
};

DECLARE_TEST(HierarchicalSystemTest)

#endif // HIERARCHICALSYSTEMTEST_H
