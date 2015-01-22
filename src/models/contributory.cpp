#include "contributory.h"

Contributory::Contributory()
{
    _description = "";
    _nbHours = 0.;
}

void Contributory::commit()
{
    // TODO implement me !
}

void Contributory::hydrat(int id)
{
    // TODO implement me !
}

void Contributory::remove()
{
    // TODO implement me !
}

Project Contributory::getProject() const
{
    return project;
}

void Contributory::setProject(const Project &id)
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


