#include "database/projectdatabase.h"
#include "database/billingdatabase.h"
#include "exceptions/dbexception.h"
#include "hierarchicalsystem.h"
#include <QDebug>

namespace Utils {
HierarchicalSystem::HierarchicalSystem() {
    updateData();
}


void HierarchicalSystem::getAllProjects()
{
    Customer c;
    for (Project* p: Databases::ProjectDatabase::instance()->getAllProjects())
    {
        c = *(p->getCustomer());
        //qDebug() << p.getName() << "-" << c.getFirstnameReferent();
        addProjectToCustomer(p, c);
    }
}

void HierarchicalSystem::getAllBillings()
{
    QMap<int,Billing*> map =
            Databases::BillingDatabase::instance()->getAllBillingsOfProject();

    for (auto it = map.cbegin(); it != map.cend(); ++it)
    {
        addBillingToProject(it.value(), Project(it.key()));
    }
}

void HierarchicalSystem::updateData()
{
    Project p;
    Customer c;
    getAllProjects();
    getAllBillings();

    qDebug() << _customers.keys().count();    
//    for (Project* p : _customers.keys()) {
//        c = _customers.value(p);
//        qDebug() <<  "map contains:" << c.getFirstnameReferent() << " - " << p->getName();
//    }
}

void HierarchicalSystem::addProjectToCustomer(Project* p, Customer c)
{     
    _customers.insert(p,c);
    for (Project* p : _customers.keys()) {
        c = _customers.value(p);
        qDebug() <<  "add:" << c.getFirstnameReferent() << " - " << p->getName();
    }
}

void HierarchicalSystem::addBillingToProject(Billing* b, Project p)
{
    _projects.insert(b,p);

}
QMap<Project*, Customer> HierarchicalSystem::getCustomers() const
{
    return _customers;
}


QMap<Billing*, Project> HierarchicalSystem::getProjects() const
{
    return _projects;
}

}

