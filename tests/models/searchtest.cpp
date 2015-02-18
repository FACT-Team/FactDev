#include "searchtest.h"
#include "models/customer.h"
#include "database/customerdatabase.h"
searchTest::searchTest()
{

}

void searchTest::searchAll()
{
    _search.setGroupFilter(false);
    _search.setText("at insti");

    QVERIFY(_search.getFilter() == "AND (0  OR company LIKE '%at insti%'  OR lastnameReferent LIKE '%at insti%' OR p.name LIKE '%at%insti%'  AND bp.idProject = p.idProject  OR bp.idContributory = ( SELECT idContributory FROM Contributory WHERE 0 OR description LIKE '%at%insti%' ) AND 1 OR bp.idBilling = ( SELECT idBilling FROM Billing WHERE 0 OR title LIKE '%at%insti%'  OR 0 ))");
    WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "HALEY");
}

void searchTest::searchCompanyName()
{
    _search.setGroupFilter(true);
    _search.setSearchInCompanies(true);
    _search.setSearchInReferentLastname(false);
    _search.setSearchInProjects(false);
    _search.setSearchInContributories(false);
    _search.setSearchInBillsQuotes(false);
    _search.setText("at insti");
    QVERIFY(_search.getFilter() == "AND (0  OR company LIKE '%at insti%' )");
    WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "HALEY");
}
void searchTest::searchCompanyNameWithSimpleQuote()
{
    _search.setGroupFilter(true);
    _search.setSearchInCompanies(true);
    _search.setSearchInReferentLastname(false);
    _search.setSearchInProjects(false);
    _search.setSearchInContributories(false);
    _search.setSearchInBillsQuotes(false);
    _search.setText("at'institute'");
    QVERIFY(_search.getFilter() ==  "AND (0  OR company LIKE '%at''institute''%' )");

    WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)) == QVariant::Invalid);
}

void searchTest::searchReferentLastname()
{
    _search.setGroupFilter(true);
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(true);
    _search.setSearchInProjects(false);
    _search.setSearchInContributories(false);
    _search.setSearchInBillsQuotes(false);
    _search.setText("haley");
    QVERIFY(_search.getFilter() == "AND (0  OR lastnameReferent LIKE '%haley%' )");
    WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "HALEY");

}

void searchTest::searchProjectName()
{
    _search.setGroupFilter(true);
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(false);
    _search.setSearchInProjects(true);
    _search.setSearchInContributories(false);
    _search.setSearchInBillsQuotes(false);
    _search.setText("aliquam");
    QVERIFY(_search.getFilter() == "AND (0 OR p.name LIKE '%aliquam%'  AND bp.idProject = p.idProject )");
    WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "DELGADO");

}

void searchTest::searchContributoryDescription()
{
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(false);
    _search.setSearchInProjects(false);
    _search.setSearchInContributories(true);
    _search.setSearchInBillsQuotes(false);
    _search.setText("manger");
    QVERIFY(_search.getFilter() == "AND (0  OR bp.idContributory = ( SELECT idContributory FROM Contributory WHERE 0 OR description LIKE '%manger%' ))");
    WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "LOVE");
}

void searchTest::searchBillOrQuoteTitle()
{
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(false);
    _search.setSearchInProjects(false);
    _search.setSearchInContributories(false);
    _search.setSearchInBillsQuotes(true);
    _search.setText("Baobab");
    QVERIFY(_search.getFilter() == "AND (0  AND 1 OR bp.idBilling = ( SELECT idBilling FROM Billing WHERE 0 OR title LIKE '%Baobab%'  OR 0 ))");
    WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "LOVE");
}

void searchTest::searchBillOrQuoteNumber()
{
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(false);
    _search.setSearchInProjects(false);
    _search.setSearchInContributories(false);
    _search.setSearchInBillsQuotes(true);
    _search.setText("5");
    QVERIFY(_search.getFilter() == "AND (0  AND 1 OR bp.idBilling = ( SELECT idBilling FROM Billing WHERE 0 OR title LIKE '%5%'  OR 0 OR number=5 ))");
    WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "LOVE");
}

void searchTest::searchWithoutFilters()
{
    _search.setGroupFilter(true);
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(false);
    _search.setText("larson");

    QVERIFY(_search.getFilter() == "AND (0 )");
    WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)) == QVariant::Invalid);

}


