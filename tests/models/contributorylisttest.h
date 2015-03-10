#ifndef CONTRIBUTORYLISTTEST_H
#define CONTRIBUTORYLISTTEST_H
#include "QTestRunner/testrunner.h"

#include "models/contributorieslist.h"

using namespace Models;

class ContributoryListTest : public QObject
{
    Q_OBJECT
public:
    ContributoryListTest();
private slots:
    void addProject();

};
DECLARE_TEST(ContributoryListTest)

#endif // CONTRIBUTORYLISTTEST_H
