#ifndef SEARCH_H
#define SEARCH_H

#include <QString>

/**
 * @author Antoine de Roquemaurel
 * @brief The Search class
 */
class Search
{
public:
    Search();
    ~Search();
    QString getFilter();
    bool getSearchInCompanies() const;
    void setSearchInCompanies(bool getSearchInCompanies);

    bool getSearchInReferentLastname() const;
    void setSearchInReferentLastname(bool getSearchInReferentLastname);

    bool getGroupFilter() const;
    void setGroupFilter(bool getGroupFilter);

    QString getText() const;
    void setText(const QString &getText);

private:
    bool _searchInCompanies;
    bool _searchInReferentLastname;
    bool _groupFilter;
    QString _text;
};

#endif // SEARCH_H
