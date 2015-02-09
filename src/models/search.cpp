#include "search.h"

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

QString Search::getFilter()
{
    QString filter = "";
    if(_text != "") {
        filter = "AND (0 ";
        if(_searchInCompanies || !_groupFilter) {
            filter += "OR company LIKE '%"+_text+"%' ";
        }
        if(_searchInReferentLastname || !_groupFilter) {
            filter += "OR lastnameReferent LIKE '%"+_text+"%'";
        }

        // -------------------
        if(_searchInProjects || !_groupFilter) {
            filter += "OR name LIKE '%"+_text+"%'";
        }
        if(_searchInContributories || !_groupFilter) {
            filter += "OR description '%"+_text+"%'";
        }
        if(_searchInBillsQuotes || !_groupFilter) {
            filter +=   "OR title '%"+_text+"%' "
                        +"OR number '%"+_text+"%' ";

        }
        filter += ")";
    }

    return filter;
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
bool Search::searchInBillsQuotes() const
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
