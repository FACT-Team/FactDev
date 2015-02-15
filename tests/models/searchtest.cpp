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
    QStandardItemModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
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
    QStandardItemModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
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

    QStandardItemModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
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
    QStandardItemModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
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
    QStandardItemModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "DELGADO");

}

void searchTest::searchContributoryDescription()
{
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(false);
    _search.setSearchInProjects(false);
    _search.setSearchInContributories(true);
    _search.setSearchInBillsQuotes(false);
    _search.setText("amet, conse");
    QVERIFY(_search.getFilter() == "AND (0  OR company LIKE '%amet, conse%'  OR bp.idContributory = ( SELECT idContributory FROM Contributory WHERE 0 OR description LIKE '%amet,%conse%' ))");
    QStandardItemModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "BELL");
}

void searchTest::searchBillOrQuoteTitle()
{
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(false);
    _search.setSearchInProjects(false);
    _search.setSearchInContributories(false);
    _search.setSearchInBillsQuotes(true);
    _search.setText("mollis nec");
    QVERIFY(_search.getFilter() == "AND (0  AND 1 OR bp.idBilling = ( SELECT idBilling FROM Billing WHERE 0 OR title LIKE '%mollis%nec%'  OR 0 ))");
    QStandardItemModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "COTE");
}

void searchTest::searchBillOrQuoteNumber()
{
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(false);
    _search.setSearchInProjects(false);
    _search.setSearchInContributories(false);
    _search.setSearchInBillsQuotes(true);
    _search.setText("");
    QVERIFY(_search.getFilter() == "");
    QStandardItemModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "");
}

void searchTest::searchWithoutFilters()
{
    _search.setGroupFilter(true);
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(false);
    _search.setText("larson");

    QVERIFY(_search.getFilter() == "AND (0 )");
    QStandardItemModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
    QVERIFY(model->data(model->index(0, 2)) == QVariant::Invalid);

}


