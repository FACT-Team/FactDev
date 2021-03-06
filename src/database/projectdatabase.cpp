#include "database/projectdatabase.h"
namespace Databases {

ProjectDatabase::ProjectDatabase() : Database() {
    _instances << this;
}

// SINGLETON
ProjectDatabase* ProjectDatabase::_instance = 0;

ProjectDatabase *ProjectDatabase::instance()
{
    if (!_instance) {
        _instance = new ProjectDatabase();
    }

    return _instance;
}

Models::Project* ProjectDatabase::getProject(QSqlQuery& q) {
    Models::Project* project = new Models::Project();
    project->setId(value(q, "idProject").toInt());
    project->setName(value(q,"name").toString());
    project->setDescription(value(q,"pdescription").toString());
    project->setBeginDate(value(q,"beginDate").toDate());
    project->setEndDate(value(q,"endDate").toDate());
    project->setDailyRate(value(q,"dailyRate").toDouble());
    project->setCustomer(
                QSharedPointer<Models::Customer>(
                    new Models::Customer(value(q,"idCustomer").toInt())));


    return project;
}


QSharedPointer<Models::Project> ProjectDatabase::updateProject(QSqlQuery& q)
{
    QSharedPointer<Models::Project> project =
            QSharedPointer<Models::Project>(new Models::Project());
    project->setId(         value(q, "idProject").toInt());
    project->setName(       value(q, "name").toString());
    project->setDescription(value(q, "description").toString());
    project->setBeginDate(  value(q, "beginDate").toDate());
    project->setEndDate(    value(q, "endDate").toDate());
    project->setDailyRate(  value(q, "dailyRate").toDouble());
    project->setCustomer(
                QSharedPointer<Models::Customer>(
                    new Models::Customer(value(q, "idCustomer").toInt())));
    return project;

}

QList<Project*> ProjectDatabase::getAllProjects()
{
    QList<Project*> list;

    QSqlQuery q;
    q.prepare("SELECT * FROM Project");

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'obtenir la liste des Projects",
                    "ProjectDatabase::getAllProjects",
                    lastError(q),
                    1.9);
    }

    while(q.next()) {
        list << new Project(value(q, "idProject").toInt());
    }
    return list;
}

double ProjectDatabase::getCostProjects(QList<Project *> projects)
{
    double cost = 0;
    for (Project *p: projects) {
        cost+= p->getCost();
    }
    return cost;
}


Models::Project* ProjectDatabase::getProject(const int pId)
{
    QSqlQuery q;
    Models::Project* project;

    q.prepare("SELECT idProject, name, description as pDescription, beginDate, "
              "endDate, dailyRate, idCustomer "
              "FROM Project WHERE idProject = :pId");
    q.bindValue(":pId", pId);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'ajouter le Project",
                    "BddProject::getProject",
                    lastError(q),
                    1.2);
    }

    if(q.first()) {
        project = getProject(q);
    } else {
        project = NULL;
        Log::instance(WARNING) << "Project is null…";
    }

    return project;
}

int ProjectDatabase::addProject(const Models::Project &pProject)
{
    QSqlQuery q;

    q.prepare(
                "INSERT INTO Project "
                "(name, description, beginDate, dailyRate, idCustomer, endDate)"
                " VALUES "
                "(:name, :description, :beginDate, :dailyRate, :idCustomer, :endDate)"
                );

    q.bindValue(":name", pProject.getName());
    q.bindValue(":description", pProject.getDescription());
    q.bindValue(":beginDate",pProject.getBeginDate());
    q.bindValue(":endDate",pProject.getEndDate());
    q.bindValue(":dailyRate", pProject.getDailyRate());
    q.bindValue(":idCustomer", pProject.getCustomer()->getId());


    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'ajouter le Project",
                    "BddProject::addProject",
                    lastError(q),
                    1.3);
    }

    return q.lastInsertId().toInt();
}

void ProjectDatabase::updateProject(const Models::Project &pProject)
{
    QSqlQuery q;

    // N.B: We can't change the customer of a project.
    // Function transfer maybe later.
    q.prepare(
                "UPDATE Project SET "
                "name = :name, description = :description, dailyRate = :dailyRate, beginDate=:beginDate, endDate=:endDate "
                "WHERE idProject= :idProject");

    q.bindValue(":idProject", pProject.getId());

    q.bindValue(":name", pProject.getName());
    q.bindValue(":description", pProject.getDescription());
    q.bindValue(":dailyRate", pProject.getDailyRate());
    q.bindValue(":beginDate", pProject.getBeginDate());
    q.bindValue(":endDate", pProject.getEndDate());


    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'éditer les informations du Project",
                    "BddProject::updateProject",
                    lastError(q),
                    1.4);
    }
}

void ProjectDatabase::removeProject(const int pId)
{
    QSqlQuery q;
    q.prepare(
                "DELETE FROM Project "
                "WHERE idProject = :pId"
                );

    q.bindValue(":pId", pId);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'éditer les informations du Project",
                    "BddProject::removeProject",
                    lastError(q),
                    1.5);
    }
}

int ProjectDatabase::getNbProjects()
{
    QSqlQuery q;

    q.prepare("SELECT count(idProject) AS nb_p FROM Project");

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'éditer les informations du Project",
                    "BddProject::getNbProject",
                    lastError(q),
                    1.6);
    }
    q.first();
    return value(q, "nb_p").toInt();
}

int ProjectDatabase::getNbProjects(const int customerId) {
    QSqlQuery q;
    QString request("SELECT COUNT(idProject) FROM Project");
    if (customerId > 0) {
        request += " WHERE idCustomer = :customerId";
    }
    q.prepare(request);
    q.bindValue(":customerId", customerId);
    if(!q.exec()) {
        throw new DbException(
                    "Impossible de récupérer le nombre de projets",
                    "ProjectDatabase::getNbProjects",
                    lastError(q),
                    1.6);
    }
    q.first();
    return q.value(0).toInt();
}

QMap<int, Models::Project> ProjectDatabase::getProjectsOfCustomer(QSharedPointer<Models::Customer> c, const bool projectLocked) {
    QSqlQuery q;
    QMap<int, Models::Project> ret;
    Models::Project project;
    q.prepare("SELECT * FROM Project WHERE idCustomer = :pId ORDER BY UPPER(name)");
    q.bindValue(":pId", c->getId());
    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'obtenir les informations du projet",
                    "BddProject::getProjectsOfCustomer",
                    lastError(q),
                    1.7);
    }
    while(q.next()) {
        project = Models::Project();
        project.setId(value(q, "idProject").toInt());
        project.setName(value(q,"name").toString());
        project.setDescription(value(q,"description").toString());
        project.setDailyRate(value(q,"dailyRate").toDouble());
        project.setCustomer(c);
        project.setBeginDate(value(q, "beginDate").toDate());
        project.setEndDate(value(q, "endDate").toDate());
        if(projectLocked || !project.isLocked()) {
            ret.insert(project.getId(), project);
        }
    }

    return ret;
}

QList<Project> ProjectDatabase::getProjects(const int customerId) {
    QList<Project> ret;
    Models::Project project;

    QSqlQuery q;

    q.prepare("SELECT idProject, name, description, beginDate, endDate, "
              "dailyRate, idCustomer "
              "FROM Project "
              "WHERE idCustomer= :pId "
              "ORDER BY UPPER(name), UPPER(description)");

    q.bindValue(":pId",customerId);
    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'obtenir les informations du projet",
                    "ProjectDatabase::getProjects(const int customerId)",
                    lastError(q),
                    1.7);
    }
    while(q.next()) {
        project = Models::Project();
        project.setId(value(q, "idProject").toInt());
        project.setName(value(q,"name").toString());
        project.setDescription(value(q,"description").toString());
        project.setDailyRate(value(q,"dailyRate").toDouble());
        ret.append(project);
    }

    return ret;
}

WdgModels::ProjectsTableModel *ProjectDatabase::getProjectsTable(const int pId)
{
    WdgModels::ProjectsTableModel* ret
            = new WdgModels::ProjectsTableModel();

    QSqlQuery q;

    q.prepare("SELECT idProject, name, description, beginDate, endDate, "
              "dailyRate, idCustomer "
              "FROM Project "
              "WHERE idCustomer= :pId "
              "ORDER BY UPPER(name), UPPER(description)");

    q.bindValue(":pId",pId);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'obtenir la liste des Projects",
                    "ProjectDatabase::getProjectsTable",
                    lastError(q),
                    1.1);
    }
    while(q.next()) {
        ret->append(*updateProject(q));
    }

    return ret;
}
}
