#ifndef PROJECTDATABASE_H
#define PROJECTDATABASE_H

#include "database/database.h"
#include "exceptions/dbexception.h"
#include "models/project.h"

/**
 * @author Florent Berbie
 * @brief The ProjectDatabase class
 */
class ProjectDatabase : public Database
{
private:
    static ProjectDatabase* _instance;

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
    Project *getProject(const int pId);

    /**
     * @brief ProjectDatabase:addProject Add the project 'pProject' to the
     * database
     * @return project id
     */
    int addProject(const Project&);

    /**
     * @brief ProjectDatabase:updateProject Update informations about the
     * project
     */
    void updateProject(const Project&);

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
};

#endif // PROJECTDATABASE_H
