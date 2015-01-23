#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include "models/idatabasemodel.h"
#include "models/customer.h"

/**
 * @author Florent Berbie
 * @brief The Project class : Project linked to a Customer
 * @see IDatabaseModel
 */
class Project : public IDatabaseModel
{
public:
    /**
     * @brief Project::Project Construct a Project
     */
    Project();


    /**
     * @brief Project::project Construct a project with a name
     */
    Project(QString name);


    /**
     * @brief Project::Project Construct a Project which is specified by an
     * <i>id</i>
     * @param id
     */
    Project(int id);

    /**
     * @brief Project::commit Update project data in the database
     */
    void commit();
    /**
     * @brief Project::hydrat Insert project data which is specified by
     * <i>id</i> in the database
     * @param id Project identify
     */
    void hydrat(int id);
    /**
     * @brief Project::remove Remove the current project
     */
    void remove();

    /**
     * @brief Project::getName Return the project name
     * @return project name
     */
    QString getName() const;
    /**
     * @brief Project::setName Modify the project <i>name</i>
     * @param name Project name
     */
    void setName(const QString &name);

    /**
     * @brief Project::getDescription Return a project description
     * @return project description
     */
    QString getDescription() const;
    /**
     * @brief Project::setDescription Modify the project <i>description</i>
     * @param description New project description
     */
    void setDescription(const QString &description);

    /**
     * @brief Project::getDailyRate Return the daily rate estimated for this
     * project
     * @return the daily rate linket to the current project
     */
    double getDailyRate() const;
    /**
     * @brief Project::setDailyRate Modify the daily rate <i>dailyRate</i> of
     * the current project
     * @param dailyRate New daily rate associated to the current project
     */
    void setDailyRate(double dailyRate);

    /**
     * @brief Project::getCustomer Return the reference to the customer linked
     * to this project
     * @return customer linked to this project
     */
    Customer* getCustomer() const;
    /**
     * @brief Project::setCustomer Modify the <i>customer</i> linked to this
     * project
     * @param customer New customer associated to this project
     */
    void setCustomer(Customer *customer);

private:
    QString _name;          //!< Project name
    QString _description;   //!< Description on the targets of this project
    double _dailyRate;      //!< Daily rate linked to this project
    Customer* _customer;    //!< Customer linked to this project
};

#endif // PROJECT_H
