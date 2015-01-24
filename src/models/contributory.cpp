#include "contributory.h"
#include "database/contributorydatabase.h"
Contributory::Contributory()
{
    _description = "";
    _nbHours = 0.;
    _id = 0;
    _toRemoved = false;
    project = new Project();
}

void Contributory::commit()
{
    // TODO implement me !
    if(_id == 0) {
        ContributoryDatabase::instance()->addContributory(*this);
    } else if(_toRemoved) {
        remove();
    } else {
        ContributoryDatabase::instance()->updateContributory(*this);
    }
}

void Contributory::hydrat(int id)
{

}

void Contributory::remove()
{
    ContributoryDatabase::instance()->removeContributory(_id);
}

Project* Contributory::getProject() const
{
    return project;
}

void Contributory::setProject(Project* id)
{
    project = id;
}
double Contributory::getNbHours() const
{
    return _nbHours;
}

void Contributory::setNbHours(double value)
{
    _nbHours = value;
}
QString Contributory::getDescription() const
{
    return _description;
}

void Contributory::setDescription(const QString &description)
{
    _description = description;
}


