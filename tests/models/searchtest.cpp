#include "searchtest.h"
#include "models/customer.h"
#include "database/customerdatabase.h"
searchTest::searchTest()
{

}

void searchTest::searchAll()
{
    _search.setGroupFilter(false);
    _search.setText("facilisis");
    QVERIFY(_search.getFilter() == "AND (0 OR company LIKE '%facilisis%' OR lastnameReferent LIKE '%facilisis%')");
    QStandardItemModel* model = CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
  //  qDebug() << _search.getFilter();
    QVERIFY(model->data(model->index(0, 2)) == "LARSON");
}

void searchTest::searchCompanyName()
{
    _search.setGroupFilter(true);
    _search.setSearchInCompanies(true);
    _search.setSearchInReferentLastname(false);
    _search.setText("facilisis");
    QVERIFY(_search.getFilter() == "AND (0 OR company LIKE '%facilisis%' )");
    QStandardItemModel* model = CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)) == "LARSON");
}
void searchTest::searchCompanyNameWithSimpleQuote()
{
    _search.setGroupFilter(true);
    _search.setSearchInCompanies(true);
    _search.setSearchInReferentLastname(false);
    _search.setText("facil'isis'");
    QVERIFY(_search.getFilter() == "AND (0 OR company LIKE '%facil''isis''%' )");

    QStandardItemModel* model = CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)) == QVariant::Invalid);
}

void searchTest::searchReferentLastname()
{
    _search.setGroupFilter(true);
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(true);
    _search.setText("larson");
    QVERIFY(_search.getFilter() == "AND (0 OR lastnameReferent LIKE '%larson%')");
    QStandardItemModel* model = CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)) == "LARSON");

}

void searchTest::searchWithoutFilters()
{
    _search.setGroupFilter(true);
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(false);
    _search.setText("larson");

    QVERIFY(_search.getFilter() == "AND (0 )");
    QStandardItemModel* model = CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)) == QVariant::Invalid);

}


