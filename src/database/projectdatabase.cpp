#include "projectdatabase.h"

ProjectDatabase::ProjectDatabase() throw(DbException*) : Database() {
    _instances << this;
}

// SINGLETON
ProjectDatabase* ProjectDatabase::_instance = 0;

ProjectDatabase *ProjectDatabase::instance() throw(DbException*)
{
    if (!_instance) {
        _instance = new ProjectDatabase();
    }

    return _instance;
}

Project *ProjectDatabase::getProject(const int pId)
{
    QSqlQuery q;
    Project* project;

    q.prepare("SELECT * FROM Project WHERE idProject = :pId");
    q.bindValue(":pId", pId);

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'ajouter le Project",
            "BddProject::getProject",
            lastError(q),
            1.2);
    }

    if(q.first()) {
        project = new Project();
        project->setId(value(q, "idProject").toInt());
        project->setName(value(q,"name").toString());
        project->setDescription(value(q,"description").toString());
        project->setDailyRate(value(q,"dailyRate").toDouble());
        project->setCustomer(new Customer(value(q,"idCustomer").toInt()));
    } else {
        project = NULL;
    }

    return project;
}

int ProjectDatabase::addProject(const Project &pProject)
{
    QSqlQuery q;

    q.prepare(
        "INSERT INTO Project "
        "(name, description, dailyRate, idCustomer)"
        " VALUES "
        "(:name, :description, :dailyRate, :idCustomer)"
    );

    q.bindValue(":name", pProject.getName());
    q.bindValue(":description", pProject.getDescription());
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

void ProjectDatabase::updateProject(const Project &pProject)
{

    QSqlQuery q;
    q.prepare(
        "UPDATE Project SET "
        "name = :name, description = :description, dailyRate = :dailyRate, "
        "idCustomer = :idCustomer "
        "WHERE idProject= :idProject");

    q.bindValue(":idProject", pProject.getId());

    q.bindValue(":name", pProject.getName());
    q.bindValue(":description", pProject.getDescription());
    q.bindValue(":dailyRate", pProject.getDailyRate());
//    q.bindValue(":idProject", pProject.getCustomer()->getId());


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
    q.next();

    return value(q, "nb_p").toInt();
}

int ProjectDatabase::getNbProjectsForACustomer(const int pId) {
    QSqlQuery q;

    q.prepare("SELECT count(*) AS nb_p FROM PROJECT WHERE idCustomer = :pId");
    q.bindValue(":pId", pId);
    if(!q.exec()) {
        throw new DbException(
            "Impossible d'éditer les informations du Project",
            "BddProject::getNbProjectForACustomer",
            lastError(q),
            1.6);
    }
    q.next();

    return value(q, "nb_p").toInt();
}

QMap<int, Project> ProjectDatabase::getProjectsOfCustomer(Customer* c) {
    QSqlQuery q;
    QMap<int, Project> ret;
    Project project;
    q.prepare("SELECT * FROM PROJECT WHERE idCustomer = :pId");
    q.bindValue(":pId", c->getId());
    if(!q.exec()) {
        throw new DbException(
            "Impossible d'obtenir les informations du projet",
            "BddProject::getProjectsOfCustomer",
            lastError(q),
            1.7);
    }
    while(q.next()) {
        project = Project();
        project.setId(value(q, "idProject").toInt());
        project.setName(value(q,"name").toString());
        project.setDescription(value(q,"description").toString());
        project.setDailyRate(value(q,"dailyRate").toDouble());
        project.setCustomer(c);

        ret.insert(project.getId(), project);
    }

    return ret;
}
