#ifndef SEARCHTEST_H
#define SEARCHTEST_H
#include "QTestRunner/testrunner.h"
#include "models/search.h"
#include "gui/widgets/widgetsmodels/customerstablemodel.h"

using namespace Models;
using namespace Gui::Widgets;

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
    void searchCompanyNameWithSimpleQuote();
    void searchProjectName();
    void searchContributoryDescription();
    void searchBillOrQuoteTitle();
    void searchBillOrQuoteNumber();
private:
    Search _search;
};
//DECLARE_TEST(searchTest)

#endif // SEARCHTEST_H
