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

    void filterOnElements(QString &filter, const QStringList list, QString element);
    /**
     * @brief Search::filterOnCompany Search all companies contained in the
     * <i>list</i> of the <i>filter</i>
     * @param filter Text inputed in searchbar
     * @param list List of companies
     */
    void filterOnCompany(QString &filter, const QStringList list);

    /**
     * @brief Search::filterOnReferentLastname Search all referents last name
     * contained in the <i>list</i> of the <i>filter</i>
     * @param filter Text inputed in searchbar
     * @param list List of referent last name
     */
    void filterOnReferentLastname(QString &filter, const QStringList list);

    /**
     * @brief Search::filterOnProjects Search all projects contained in the
     * <i>list</i> of the <i>filter</i>
     * @param filter Text inputed in searchbar
     * @param list List of projects
     */
    void filterOnProjects(QString &filter, const QStringList list);

    /**
     * @brief Search::filterOnContributories Search all contributories contained
     *  in the <i>list</i> of the <i>filter</i>
     * @param filter Text inputed in searchbar
     * @param list List of contributories
     */
    void filterOnContributories(QString &filter, const QStringList list);

    /**
     * @brief Search::filterOnBillsOrQuotes Search all bills or quotes which are
     *  contained in the <i>list</i> of the <i>filter</i>
     * @param filter Text inputed in searchbar
     * @param list List of bills or quotes
     */
    void filterOnBillsOrQuotes(QString &filter, const QStringList list);

    /**
     * @brief Search::getSearchInCompanies Return if we search a company
     * @return boolean if we search a company
     */
    bool getSearchInCompanies() const;
    /**
     * @brief Search::setSearchInCompanies Modify the filter of companies search
     * @param getSearchInCompanies Search in companies is concerned
     */
    void setSearchInCompanies(bool searchInCompanies);

    /**
     * @brief Search::getSearchInReferentLastname Return if we search
     * a Last name referent
     * @return boolean if search concerns the last name of referent
     */
    bool getSearchInReferentLastname() const;
    /**
     * @brief Search::setSearchInReferentLastname Modify the filter of referents
     * last name search
     * @param searchInReferentLastname Search in referents last name which are
     * concerned
     */
    void setSearchInReferentLastname(bool searchInReferentLastname);

    /**
     * @brief Search::getSearchInProjects Return TRUE if it exists one or more
     * projets in database
     * @return boolean if project are existing
     */
    bool getSearchInProjects() const;
    /**
     * @brief Search::setSearchInProjects Modify the filter of projects search
     * @param searchInProjects Search in projects which are concerned
     */
    void setSearchInProjects(bool searchInProjects);

    /**
     * @brief Search::getSearchInContributories  Return TRUE if it exists one or
     *  more projets in database
     * @return boolean if contributories are existing
     */
    bool searchInContributories() const;
    /**
     * @brief Search::setSearchInContributories Modify the filter of
     * contributories search
     * @param searchInContributories Search in contributories which are
     * concerned
     */
    void setSearchInContributories(bool searchInContributories);

    /**
     * @brief Search::searchInBillsQuotes Return TRUE if it exists one or more
     * bills or quotes in database
     * @return boolean if bills or quotes are existing
     */
    bool getSearchInBillsQuotes() const;
    /**
     * @brief Search::setSearchInBillsQuotes Modify the filter of bills and
     * quotes search
     * @param searchInBillsQuotes Search in bills or quotes which are concerned
     */
    void setSearchInBillsQuotes(bool searchInBillsQuotes);

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
    bool _searchInProjects;         //!< Projets name in search
    bool _searchInContributories;   //!< Contributories involved in search
    bool _searchInBillsQuotes;      //!< Bills Quotes involved in search
    bool _groupFilter;              //!< filter of serach actived
    QString _text;                  //!< Text involved in the sql query
};
}
#endif // SEARCH_H
