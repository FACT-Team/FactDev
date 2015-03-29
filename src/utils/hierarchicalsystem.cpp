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
    Customer c;
    for (Project* p: Databases::ProjectDatabase::instance()->getAllProjects()) {
        c = *(p->getCustomer());
        addProjectToCustomer(p, c);
    }
}

void HierarchicalSystem::getAllBillings()
{
    QMap<Project*,Billing*> map =
            Databases::BillingDatabase::instance()->getAllBillingsOfProject();

    for (auto it = map.cbegin(); it != map.cend(); ++it)
    {
        addBillingToProject(it.value(), it.key());
    }
}

void HierarchicalSystem::updateData()
{
    getAllProjects();
    getAllBillings();
}

void HierarchicalSystem::addProjectToCustomer(Project* p, Customer c)
{     
    _customers.insert(p,c);
}

void HierarchicalSystem::addBillingToProject(Billing* b, Project* p)
{
    _projects.insert(b,p);
}

QMap<Project*, Customer> HierarchicalSystem::getCustomers() const
{
    return _customers;
}


QMap<Billing*, Project*> HierarchicalSystem::getProjects() const
{
    return _projects;
}

}

