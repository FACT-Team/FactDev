#ifndef SEARCHTEST_H
#define SEARCHTEST_H
#include "QTestRunner/testrunner.h"
#include "models/search.h"

class searchTest : public QObject
{
    Q_OBJECT

public:
    searchTest();

private slots:
    void searchAll();
    void searchCompanyName();
    void searchReferentLastname();
    void searchWithoutFilters();

private:
    Search _search;
};
DECLARE_TEST(searchTest)

#endif // SEARCHTEST_H
