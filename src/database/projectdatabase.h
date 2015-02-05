#ifndef PROJECTDATABASE_H
#define PROJECTDATABASE_H
#include "database/database.h"

#include "exceptions/dbexception.h"

#include "models/project.h"

#include "utils/string.h"
#include "utils/log.h"

using namespace Utils;
using namespace Exceptions;

namespace Database {

/**
 * @author Florent Berbie
 * @brief The ProjectDatabase class Project table database
 * @see Database
 * @see Project
 */
class ProjectDatabase : public Database
{
private:
    static ProjectDatabase* _instance; //!< Singleton instance of ProjectDatabase

    /**
     * @brief ProjectDatabase: is a singleton
     */
    ProjectDatabase() throw (DbException*);
public:
    /**
     * @brief ProjectDatabase::getInstance Return an instance of ProjectDatabase
     * @return Instance of ProjectDatabase
     */
    static ProjectDatabase*  instance() throw (DbException*);

    /**
     * @brief ProjectDatabasegetProject Get informations about the project
     * identified by 'pId'
     * @param pId project
     * @return the project
     */
    Models::Project *getProject(const int pId);

    /**
     * @brief ProjectDatabase:addProject Add the project 'pProject' to the
     * database
     * @return project id
     */
    int addProject(const Models::Project&);

    /**
     * @brief ProjectDatabase:updateProject Update informations about the
     * project
     */
    void updateProject(const Models::Project&);

    /**
     * @brief removeProject Remove the project with the id 'pId'
     * @param pId project id
     */
    void removeProject(const int pId);

    /**
     * @brief ProjectDatabase:getNbProjects Return the number of projects
     * existing
     * @return number of projects
     */
    int getNbProjects();

    /**
     * @brief ProjectDatabase:getNbProjectsForACustomer Return the number of
     * projects existing for an identify customer <i>pId</i>
     * @param pId Project id
     * @return number of projects
     */
    int getNbProjectsForACustomer(const int pId);

    /**
     * @brief getProjectsOfCustomer Return all projects of a customer
     * @param c The customer
     * @return All projects of c with id in key
     */
    QMap<int, Models::Project> getProjectsOfCustomer(QSharedPointer<Models::Customer> c);

    /**
      * @brief getProjectsTable Return all projects of a customer in QStandardItemModel
      * @param filter Select only projects who are specified by <i>filter</i>
      * @return QStandardItemModel an item model for QTableView
      */
    QStandardItemModel* getProjectsTable(const int pId) throw(DbException*);

    /**
     * @brief getProject Obtain a project without new query
     * @param q The query to use
     * @return The project linked to q
     */
    Models::Project *getProject(QSqlQuery &q);
};
}
#endif // PROJECTDATABASE_H
