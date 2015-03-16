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

    try {
        QVERIFY(_search.getFilter() == ", Project p, BillingProject bp WHERE c.idCustomer = p.idCustomer AND bp.idProject = p.idProject AND 1 AND (0  OR company LIKE '%at insti%'  OR lastnameReferent LIKE '%at insti%' OR p.name LIKE '%at%insti%'  AND bp.idProject = p.idProject  OR bp.idContributory = ( SELECT idContributory FROM Contributory WHERE 0 OR description LIKE '%at%insti%' LIMIT 1) AND 1 OR bp.idBilling = ( SELECT idBilling FROM Billing WHERE 0 OR title LIKE '%at%insti%'  OR 0 ))  UNION SELECT DISTINCT c.idCustomer as cidcustomer, c.firstnameReferent as cfirstnameReferent, UPPER(c.lastnameReferent) as clastnameReferent, c.company as ccompany, c.address as caddress, c.postalCode as cpostalcode, c.city as ccity, c.country as ccountry, c.email as cemail, c.phone as cphone, c.mobilephone as cmobilephone, c.fax as cfax FROM Customer c WHERE 1 AND (0  OR company LIKE '%at insti%'  OR lastnameReferent LIKE '%at insti%' ) ");
        WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
        QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "HALEY");
    } catch(DbException* e) {
        QFAIL(e->what());
    }
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
    try {
        QVERIFY(_search.getFilter() == ", Project p, BillingProject bp WHERE c.idCustomer = p.idCustomer AND bp.idProject = p.idProject AND 1 AND (0  OR company LIKE '%at insti%' )  UNION SELECT DISTINCT c.idCustomer as cidcustomer, c.firstnameReferent as cfirstnameReferent, UPPER(c.lastnameReferent) as clastnameReferent, c.company as ccompany, c.address as caddress, c.postalCode as cpostalcode, c.city as ccity, c.country as ccountry, c.email as cemail, c.phone as cphone, c.mobilephone as cmobilephone, c.fax as cfax FROM Customer c WHERE 1 AND (0  OR company LIKE '%at insti%'  OR lastnameReferent LIKE '%at insti%' ) ");
        WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
        QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "HALEY");
    } catch(DbException* e) {
        QFAIL(e->what());
    }
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
    try {
        QVERIFY(_search.getFilter() ==  ", Project p, BillingProject bp WHERE c.idCustomer = p.idCustomer AND bp.idProject = p.idProject AND 1 AND (0  OR company LIKE '%at''institute''%' )  UNION SELECT DISTINCT c.idCustomer as cidcustomer, c.firstnameReferent as cfirstnameReferent, UPPER(c.lastnameReferent) as clastnameReferent, c.company as ccompany, c.address as caddress, c.postalCode as cpostalcode, c.city as ccity, c.country as ccountry, c.email as cemail, c.phone as cphone, c.mobilephone as cmobilephone, c.fax as cfax FROM Customer c WHERE 1 AND (0  OR company LIKE '%at''institute''%'  OR lastnameReferent LIKE '%at''institute''%' ) ");

        WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
        QVERIFY(model->data(model->index(0, 2)) == QVariant::Invalid);
    } catch(DbException* e) {
        QFAIL(e->what());
    }
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
    try {
        QVERIFY(_search.getFilter() == ", Project p, BillingProject bp WHERE c.idCustomer = p.idCustomer AND bp.idProject = p.idProject AND 1 AND (0  OR lastnameReferent LIKE '%haley%' )  UNION SELECT DISTINCT c.idCustomer as cidcustomer, c.firstnameReferent as cfirstnameReferent, UPPER(c.lastnameReferent) as clastnameReferent, c.company as ccompany, c.address as caddress, c.postalCode as cpostalcode, c.city as ccity, c.country as ccountry, c.email as cemail, c.phone as cphone, c.mobilephone as cmobilephone, c.fax as cfax FROM Customer c WHERE 1 AND (0  OR company LIKE '%haley%'  OR lastnameReferent LIKE '%haley%' ) ");
        WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
        QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "HALEY");
    } catch(DbException* e) {
        QFAIL(e->what());
    }

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
    try {
        QVERIFY(_search.getFilter() == ", Project p, BillingProject bp WHERE c.idCustomer = p.idCustomer AND bp.idProject = p.idProject AND 1 AND (0 OR p.name LIKE '%aliquam%'  AND bp.idProject = p.idProject )  UNION SELECT DISTINCT c.idCustomer as cidcustomer, c.firstnameReferent as cfirstnameReferent, UPPER(c.lastnameReferent) as clastnameReferent, c.company as ccompany, c.address as caddress, c.postalCode as cpostalcode, c.city as ccity, c.country as ccountry, c.email as cemail, c.phone as cphone, c.mobilephone as cmobilephone, c.fax as cfax FROM Customer c WHERE 1 AND (0  OR company LIKE '%aliquam%'  OR lastnameReferent LIKE '%aliquam%' ) ");
        WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
        QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "DELGADO");
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void searchTest::searchContributoryDescription()
{
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(false);
    _search.setSearchInProjects(false);
    _search.setSearchInContributories(true);
    _search.setSearchInBillsQuotes(false);
    _search.setText("manger");
    try {
        QVERIFY(_search.getFilter() == ", Project p, BillingProject bp WHERE c.idCustomer = p.idCustomer AND bp.idProject = p.idProject AND 1 AND (0  OR bp.idContributory = ( SELECT idContributory FROM Contributory WHERE 0 OR description LIKE '%manger%' LIMIT 1))  UNION SELECT DISTINCT c.idCustomer as cidcustomer, c.firstnameReferent as cfirstnameReferent, UPPER(c.lastnameReferent) as clastnameReferent, c.company as ccompany, c.address as caddress, c.postalCode as cpostalcode, c.city as ccity, c.country as ccountry, c.email as cemail, c.phone as cphone, c.mobilephone as cmobilephone, c.fax as cfax FROM Customer c WHERE 1 AND (0  OR company LIKE '%manger%'  OR lastnameReferent LIKE '%manger%' ) ");
        WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
        QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "LOVE");
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void searchTest::searchBillOrQuoteTitle()
{
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(false);
    _search.setSearchInProjects(false);
    _search.setSearchInContributories(false);
    _search.setSearchInBillsQuotes(true);
    _search.setText("Baobab");
    try {
        QVERIFY(_search.getFilter() == ", Project p, BillingProject bp WHERE c.idCustomer = p.idCustomer AND bp.idProject = p.idProject AND 1 AND (0  AND 1 OR bp.idBilling = ( SELECT idBilling FROM Billing WHERE 0 OR title LIKE '%Baobab%'  OR 0 ))  UNION SELECT DISTINCT c.idCustomer as cidcustomer, c.firstnameReferent as cfirstnameReferent, UPPER(c.lastnameReferent) as clastnameReferent, c.company as ccompany, c.address as caddress, c.postalCode as cpostalcode, c.city as ccity, c.country as ccountry, c.email as cemail, c.phone as cphone, c.mobilephone as cmobilephone, c.fax as cfax FROM Customer c WHERE 1 AND (0  OR company LIKE '%Baobab%'  OR lastnameReferent LIKE '%Baobab%' ) ");
        WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
        QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "LOVE");
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void searchTest::searchBillOrQuoteNumber()
{
    _search.setGroupFilter(true);
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(false);
    _search.setSearchInProjects(false);
    _search.setSearchInContributories(false);
    _search.setSearchInBillsQuotes(true);
    _search.setText("5");
    try {
        QVERIFY(_search.getFilter() == ", Project p, BillingProject bp WHERE c.idCustomer = p.idCustomer AND bp.idProject = p.idProject AND 1 AND (0  AND 1 OR bp.idBilling = ( SELECT idBilling FROM Billing WHERE 0 OR title LIKE '%5%'  OR 0 OR number=5 ))  UNION SELECT DISTINCT c.idCustomer as cidcustomer, c.firstnameReferent as cfirstnameReferent, UPPER(c.lastnameReferent) as clastnameReferent, c.company as ccompany, c.address as caddress, c.postalCode as cpostalcode, c.city as ccity, c.country as ccountry, c.email as cemail, c.phone as cphone, c.mobilephone as cmobilephone, c.fax as cfax FROM Customer c WHERE 1 AND (0  OR company LIKE '%5%'  OR lastnameReferent LIKE '%5%' ) ");
        WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
        QVERIFY(model->data(model->index(0, 2)).toString().toUpper() == "LOVE");
    } catch(DbException* e) {
        QFAIL(e->what());
    }
}

void searchTest::searchWithoutFilters()
{
    _search.setGroupFilter(true);
    _search.setSearchInCompanies(false);
    _search.setSearchInReferentLastname(false);
    _search.setSearchInProjects(false);
    _search.setSearchInContributories(false);
    _search.setSearchInBillsQuotes(false);
    _search.setText("larson");

    try {
        QVERIFY(_search.getFilter() == ", Project p, BillingProject bp WHERE c.idCustomer = p.idCustomer AND bp.idProject = p.idProject AND 1 AND (0 )  UNION SELECT DISTINCT c.idCustomer as cidcustomer, c.firstnameReferent as cfirstnameReferent, UPPER(c.lastnameReferent) as clastnameReferent, c.company as ccompany, c.address as caddress, c.postalCode as cpostalcode, c.city as ccity, c.country as ccountry, c.email as cemail, c.phone as cphone, c.mobilephone as cmobilephone, c.fax as cfax FROM Customer c WHERE 1 AND (0  OR company LIKE '%larson%'  OR lastnameReferent LIKE '%larson%' ) ");
        WdgModels::CustomersTableModel* model = Databases::CustomerDatabase::instance()->getCustomersTable(_search.getFilter());
        QVERIFY(model->data(model->index(0, 2)) == QVariant::Invalid);
    } catch(DbException* e) {
        QFAIL(e->what());
    }

}


