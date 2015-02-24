#ifndef HIERARCHICALSYSTEM_H
#define HIERARCHICALSYSTEM_H
#include <QMap>

#include "database/database.h"
#include "exceptions/dbexception.h"
#include "models/billing.h"
#include "models/customer.h"
#include "models/project.h"

using namespace Models;

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
     * @brief HierarchicalSystem::HierarchicalSystem Construct a
     *  HierarchicalSystem
     */
    HierarchicalSystem();

    /**
     * @brief HierarchicalSystem::getAllProjects Get all projects and add each
     * project to Customer linked
     */
    void getAllProjects();

    /**
     * @brief HierarchicalSystem::getAllBillings Get all billings and add each
     * billing to Project linked
     */
    void getAllBillings();

    /**
     * @brief HierarchicalSystem::updateData Update data on Customers, Projects,
     *  Billings
     */
    void updateData();

    /**
     * @brief HierarchicalSystem::addProjectToCustomer Add the Project <i>p</i>
     * to the Customer <i>c</i>
     * @param p Project
     * @param c Customer
     */
    void addProjectToCustomer(Project *p, Customer c);

    /**
     * @brief HierarchicalSystem::addBillingToProject Add the Billing <i>b</i>
     * to the Project </i>p</i>
     * @param b Billing
     * @param p Project
     */
    void addBillingToProject(Billing *b, Project *p);

    /**
     * @brief HierarchicalSystem::getCustomers Return all customers and these
     * projects linked
     * @return Projects linked to Customers
     */
    QMap<Project *, Customer> getCustomers() const;

    /**
     * @brief HierarchicalSystem::getProjects Return all projects and these
     * billing linked
     * @return Billing linked to Projects
     */
    QMap<Billing *, Project*> getProjects() const;

private:

    QMap<Project*, Customer> _customers;    //!< Projects linked to Customers
    QMap<Billing*, Project*> _projects;      //!< Billing linked to Projects
};
}

#endif // HIERARCHICALSYSTEM_H
