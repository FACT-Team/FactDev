#ifndef PROJECTDATABASE_H
#define PROJECTDATABASE_H
#include "database/database.h"
#include "exceptions/dbexception.h"
#include "models/project.h"
class ProjectDatabase : public Database
{
private:
    static ProjectDatabase* _instance;
    ProjectDatabase() throw (DbException*);
public:
    static ProjectDatabase*  instance() throw (DbException*);

    /**
     * @brief getProject
     * @param pId project
     * get informations about the project identified by 'pId'
     * @return the project
     */
    Project *getProject(const int pId);

    /**
     * @brief addProject
     * add the project 'pProject' to the database
     * @return project id
     */
    int addProject(const Project&);

    /**
     * @brief updateProject
     * update informations about the project
     */
    void updateProject(const Project&);

    /**
     * @brief removeProject
     * @param pId project id
     * remove the project with the id 'pId'
     */
    void removeProject(const int pId);

    /**
     * @brief getNbProjects
     * Return the number of projects existing
     * @return number of projects
     */
    int getNbProjects();
};

#endif // PROJECTDATABASE_H
