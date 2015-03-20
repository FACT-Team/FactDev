#include "contributorylisttest.h"


ContributoryListTest::ContributoryListTest()
{
}

void ContributoryListTest::addProject()
{
    try {
        ContributoriesList contributories = ContributoriesList();
        contributories.addProject(new Project(1),Rate(12));
        QVERIFY(contributories.getAllContributories()->count() == 0);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}
