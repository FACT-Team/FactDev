#include "database/customerdatabase.h"
#include "hierarchicalsystem.h"

namespace Utils {

HierarchicalSystem::HierarchicalSystem()
{
    getAllProjects();
}

HierarchicalSystem::~HierarchicalSystem()
{

}

void HierarchicalSystem::getAllProjects()
{
    Project p;
    // TODO SQL requete
    /*
    QSqlQuery q;
    q.prepare();
    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'obtenir la liste des Customers",
                    "CustomerDatabase::getCustomersTable",
                    lastError(q),
                    1.1);
    }

    while(q.next()) {

    }
    */
}

void HierarchicalSystem::addProjectToCustomer(Models::Project p, Models::Customer c)
{
    if (!_customers.contains(c)) {
        _customers.insert(c,p);
    }
}

void HierarchicalSystem::addBillingToProject(Models::Billing b, Models::Project p)
{
    if (!_projects.contains(b)) {
        _projects.insert(p,b);
    }
}
QMap<Models::Project, Models::Customer> HierarchicalSystem::getCustomers() const
{
    return _customers;
}


QMap<Models::Billing, Models::Project> HierarchicalSystem::projects() const
{
    return _projects;
}

}
