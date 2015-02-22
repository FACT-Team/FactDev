#include "database/projectdatabase.h"
#include "database/billingdatabase.h"
#include "exceptions/dbexception.h"
#include "hierarchicalsystem.h"

namespace Utils {
HierarchicalSystem::HierarchicalSystem() {
    updateData();
}


void HierarchicalSystem::getAllProjects()
{
    for (Project p: Databases::ProjectDatabase::instance()->getAllProjects())
    {
        addProjectToCustomer(p, Customer(p.getId()));
    }
}

void HierarchicalSystem::getAllBillings()
{
    QMap<int,Billing> map =
            Databases::BillingDatabase::instance()->getAllBillingsOfProject();

    for (auto it = map.cbegin(); it != map.cend(); ++it)
    {
        addBillingToProject(it.value(), Project(it.key()));
    }
}

void HierarchicalSystem::updateData()
{

    getAllProjects();
    getAllBillings();
}

void HierarchicalSystem::addProjectToCustomer(Models::Project p, Models::Customer c)
{
    if (!_customers.contains(p)) {
        _customers.insert(p,c);
    }
}

void HierarchicalSystem::addBillingToProject(Models::Billing b, Models::Project p)
{
    if (!_projects.contains(b)) {
        _projects.insert(b,p);
    }
}
QMap<Project, Customer> HierarchicalSystem::getCustomers() const
{
    return _customers;
}


QMap<Billing, Project> HierarchicalSystem::getProjects() const
{
    return _projects;
}

}

