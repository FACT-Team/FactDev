#ifndef HIERARCHICALSYSTEM_H
#define HIERARCHICALSYSTEM_H
#include <QMap>

#include "database/database.h"
#include "exceptions/dbexception.h"
#include "models/billing.h"
#include "models/customer.h"
#include "models/project.h"

namespace Utils {
/**
 * @author Florent Berbie
 * @brief The HierarchicalSystem class Create class which contains hierarchical
 * system of FactDev
 * @see Customer
 * @see Project
 * @see Billing
 */
class HierarchicalSystem {

public:    
    /**
     * @brief HierarchicalSystem::HierarchicalSystem Contruct a
     * HierarchicalSystem
     */
    HierarchicalSystem();
    ~HierarchicalSystem();

    /**
     * @brief HierarchicalSystem::getAllProjects Get all project and add each
     * project to Customer linked
     */
    void getAllProjects();

    /**
     * @brief HierarchicalSystem::addProjectToCustomer Add the Project <i>p</i>
     * to the Customer <i>c</i>
     * @param p Project
     * @param c Customer
     */
    void addProjectToCustomer(Models::Project p, Models::Customer c);

    /**
     * @brief HierarchicalSystem::addBillingToProject Add the Billing <i>b</i>
     * to the Project </i>p</i>
     * @param b Billing
     * @param p Project
     */
    void addBillingToProject(Models::Billing b, Models::Project p);

    /**
     * @brief HierarchicalSystem::getCustomers Return all customers and these
     * projects linked
     * @return Projects linked to Customers
     */
    QMap<Models::Project, Models::Customer> getCustomers() const;

    /**
     * @brief HierarchicalSystem::getProjects Return all projects and these
     * billing linked
     * @return Billing linked to Projects
     */
    QMap<Models::Billing, Models::Project> getProjects() const;

private:
    //!< Projects linked to Customers
    QMap<Models::Project, Models::Customer> _customers;
    //!< Billing linked to Projects
    QMap<Models::Billing, Models::Project> _projects;

};
}
#endif // HIERARCHICALSYSTEM_H
