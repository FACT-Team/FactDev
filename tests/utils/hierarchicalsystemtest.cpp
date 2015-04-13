#include "hierarchicalsystemtest.h"
#include <QDebug>

HierarchicalSystemTest::HierarchicalSystemTest() {

}

void HierarchicalSystemTest::numberOfCustomersTest() {
    Utils::HierarchicalSystem h;
    QVERIFY(50 == h.getCustomers().size());
}

void HierarchicalSystemTest::numberOfProjectsTest()
{
    Utils::HierarchicalSystem h;
    QVERIFY(74 == h.getProjects().size());
}

