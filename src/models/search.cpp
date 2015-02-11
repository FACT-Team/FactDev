#include "search.h"
#include <QDebug>
namespace Models {
Search::Search()
{
    _searchInCompanies = true;
    _searchInReferentLastname = true;
    _searchInProjects = true;
    _searchInContributories = true;
    _searchInBillsQuotes = true;
    _groupFilter = false;
}

Search::~Search()
{

}
/*
SELECT DISTINCT c.idCustomer , c.firstnameReferent,
c.lastnameReferent, c.company, c.phone, c.email
FROM Customer c, Project p, BillingProject bp, Billing b
WHERE p.idCustomer = c.idCustomer
AND bp.idProject = p.idProject
AND c.company LIKE '%'
AND c.lastnameReferent LIKE '%'
AND bp.idProject = (
    SELECT idProject FROM Project
    WHERE name LIKE '%')
AND bp.idContributory = (
    SELECT idContributory FROM Contributory
    WHERE name LIKE '%')
AND bp.idBilling = (
    SELECT idBilling FROM Billing
    WHERE title LIKE '%'
    AND number LIKE '%')
ORDER BY UPPER(c.company), UPPER(c.lastnameReferent)
*/
QString Search::getFilter()
{
    QString filter = "";
    QStringList list = _text.split(" ");

    if(!_text.isEmpty()) {
        filter = "AND (0 ";
        if(_searchInCompanies || !_groupFilter) {
            //filter += "OR company LIKE '%"+_text+"%' ";
            filterOnCompany(filter, list);
        }
        if(_searchInReferentLastname || !_groupFilter) {
            //filter += "OR lastnameReferent LIKE '%"+_text+"%'";
            filterOnReferentLastname(filter, list);
        }


        if(_searchInProjects || !_groupFilter) {
            filterOnProjects(filter, list);
        }

        if(_searchInContributories || !_groupFilter) {
            filterOnContributories(filter, list);
        }

        if(_searchInBillsQuotes || !_groupFilter) {
            filterOnBillsOrQuotes(filter, list);
        }

        filter += ")";
    }

    return filter;
}

void Search::filterOnVarcharElements(QString &filter, const QStringList list, QString element)
{
    for (QString str: list) {
        if (!str.isEmpty()) {
            filter += "OR " + element + " LIKE '%" + str + "%' ";
        }
    }
}

void Search::filterOnNumberElements(QString &filter, const QStringList list, QString element)
{
    QRegExp numberRgx("[0-9]{1,}");
    numberRgx.setCaseSensitivity(Qt::CaseInsensitive);
    numberRgx.setPatternSyntax(QRegExp::RegExp);

    for (QString str: list) {
        if (numberRgx.exactMatch(str)) {
            filter += "OR " + element + "=" + str + " ";
        }

    }
}

void Search::filterOnCompany(QString &filter, const QStringList list)
{
    filterOnVarcharElements(filter, list, "company");
}

void Search::filterOnReferentLastname(QString &filter, const QStringList list)
{
    filterOnVarcharElements(filter, list, "lastnameReferent");
}

void Search::filterOnProjects(QString &filter, const QStringList list)
{
    filter +=   " OR bp.idProject = ( "
                    "SELECT idProject FROM Project "
                    "WHERE 0 ";
    filterOnVarcharElements(filter, list, "name");
    filter +=   ")";
}

void Search::filterOnContributories(QString &filter, const QStringList list)
{
    filter +=   " OR bp.idContributory = ( "
                    "SELECT idContributory FROM Contributory "
                    "WHERE 0 ";
    filterOnVarcharElements(filter, list, "description");
    filter +=   ")";
}

void Search::filterOnBillsOrQuotes(QString &filter, const QStringList list)
{
    filter +=   " OR bp.idBilling = ( "
                    "SELECT idBilling FROM Billing "
                    "WHERE 0 ";
    filterOnVarcharElements(filter, list, "title");
    filter +=   " OR 0 ";
    filterOnNumberElements(filter, list, "number");
    filter +=   ")";
}

bool Search::getSearchInCompanies() const
{
    return _searchInCompanies;
}

void Search::setSearchInCompanies(bool searchInCompanies)
{
    _searchInCompanies = searchInCompanies;
}
bool Search::getSearchInReferentLastname() const
{
    return _searchInReferentLastname;
}

void Search::setSearchInReferentLastname(bool searchInReferentLastname)
{
    _searchInReferentLastname = searchInReferentLastname;
}
bool Search::getGroupFilter() const
{
    return _groupFilter;
}

void Search::setGroupFilter(bool groupFilter)
{
    _groupFilter = groupFilter;
}

QString Search::getText() const
{
    return _text;
}

void Search::setText(const QString &text)
{
    _text = text;
    _text.replace("'", "''");
}
bool Search::getSearchInBillsQuotes() const
{
    return _searchInBillsQuotes;
}

void Search::setSearchInBillsQuotes(bool searchInBillsQuotes)
{
    _searchInBillsQuotes = searchInBillsQuotes;
}

bool Search::getSearchInProjects() const
{
    return _searchInProjects;
}

void Search::setSearchInProjects(bool searchInProjects)
{
    _searchInProjects = searchInProjects;
}
bool Search::searchInContributories() const
{
    return _searchInContributories;
}

void Search::setSearchInContributories(bool searchInContributories)
{
    _searchInContributories = searchInContributories;
}


}
