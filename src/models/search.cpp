#include "search.h"

Search::Search()
{
    _searchInCompanies = true;
    _searchInReferentLastname = true;
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
            filter += " OR lastnameReferent LIKE '%"+_text+"%'";
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
}





