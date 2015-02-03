#include "database/projectdatabase.h"
#include "utils.h"
#include "log.h"
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

Project* ProjectDatabase::getProject(QSqlQuery& q) {
    Project* project = new Project();
    project->setId(value(q, "idProject").toInt());
    project->setName(value(q,"name").toString());
    project->setDescription(value(q,"description").toString());
    project->setDailyRate(value(q,"dailyRate").toDouble());
    project->setCustomer(new Customer(value(q,"idCustomer").toInt()));

    return project;
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
        project = getProject(q);
    } else {
        project = NULL;
        Log::instance(WARNING) << "Project is null…";
    }

    return project;
}

int ProjectDatabase::addProject(const Project &pProject)
{
    QSqlQuery q;

    q.prepare(
        "INSERT INTO Project "
        "(name, description, beginDate, dailyRate, idCustomer)"
        " VALUES "
        "(:name, :description, :beginDate, :dailyRate, :idCustomer)"
    );

    q.bindValue(":name", pProject.getName());
    q.bindValue(":description", pProject.getDescription());
    q.bindValue(":beginDate",pProject.getBeginDate().toString());
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

    // N.B: We can't change the customer of a project.
    // Function transfer maybe later.
    q.prepare(
        "UPDATE Project SET "
        "name = :name, description = :description, dailyRate = :dailyRate "
        "WHERE idProject= :idProject");

    q.bindValue(":idProject", pProject.getId());

    q.bindValue(":name", pProject.getName());
    q.bindValue(":description", pProject.getDescription());
    q.bindValue(":dailyRate", pProject.getDailyRate());


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
    q.prepare("SELECT * FROM PROJECT WHERE idCustomer = :pId ORDER BY UPPER(name)");
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
QStandardItemModel *ProjectDatabase::getProjectsTable(const int pId)
    throw(DbException*)
{
    QStandardItemModel* retour = new QStandardItemModel();

        retour->setColumnCount(3);
        retour->setHorizontalHeaderLabels(
                    QStringList()
                    << ("Id")
                    << ("Nom")
                    << ("Description")
                    << ("Date de création")
                    << ("Date de fin")
                    );
    QSqlQuery q;


    q.prepare("SELECT idProject ,name, description,beginDate,endDate "
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
        QList<QStandardItem*> ligne;

        ligne << new QStandardItem(value(q, "idProject").toString());
        ligne << new QStandardItem(
                     Utils::firstLetterToUpper(value(q,"name").toString()));
        ligne << new QStandardItem(
                    value(q, "description").toString());
        ligne << new QStandardItem(
                     value(q,"beginDate").toString());
        ligne << new QStandardItem(
                     value(q,"endDate").toString());
        retour->appendRow(ligne);
    }

    return retour;
}
