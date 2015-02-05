#ifndef SEARCH_H
#define SEARCH_H

#include <QString>

namespace Models {
/**
 * @author Antoine de Roquemaurel
 * @brief The Search class
 */
class Search
{
public:
    /**
     * @brief Search::Search Construct a search
     */
    Search();
    /**
     * @brief Search::Search Destruct a search
     */
    ~Search();

    /**
     * @brief Search::getFilter Return the search filter
     * @return filter selected (sql portion)
     */
    QString getFilter();
    /**
     * @brief Search::getSearchInCompanies Return if we search a company
     * @return boolean if we search a company
     */
    bool getSearchInCompanies() const;
    /**
     * @brief Search::setSearchInCompanies Modify the filter of search
     * @param getSearchInCompanies Search in companies is concerned
     */
    void setSearchInCompanies(bool getSearchInCompanies);

    /**
     * @brief Search::getSearchInReferentLastname Return if we search
     * a Last name referent
     * @return boolean if search concerns the last name of referent
     */
    bool getSearchInReferentLastname() const;
    /**
     * @brief Search::setSearchInReferentLastname Modify the filter of search
     * @param getSearchInReferentLastname Search in referent last name is concerned
     */
    void setSearchInReferentLastname(bool getSearchInReferentLastname);

    /**
     * @brief Search::getGroupFilter Return if the filter is actived
     * @return boolean if search filter is actived
     */
    bool getGroupFilter() const;
    /**
     * @brief Search::setGroupFilter Modify if we active search filter
     * @param getGroupFilter Get if filter is actived
     */
    void setGroupFilter(bool getGroupFilter);

    /**
     * @brief Search::getText Return sql portion of filter
     * @return QString the sql portion
     */
    QString getText() const;
    /**
     * @brief Search::setText Modify sql portion
     * @param getText Get sql portion
     */
    void setText(const QString &getText);

private:
    bool _searchInCompanies;        //!< Companies involved in search
    bool _searchInReferentLastname; //!< Referent last name involved in search
    bool _groupFilter;              //!< filter of serach actived
    QString _text;                  //!< Text involved in the sql query
};
}
#endif // SEARCH_H
