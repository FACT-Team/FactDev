#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QDate>
#include <QSharedPointer>

#include "models/imodel.h"
#include "models/customer.h"

namespace Models {
/**
 * @author Florent Berbie
 * @brief The Project class : Project linked to a Customer
 * @see IModel
 */
class Project : public IModel
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
     * @brief ~Project Desctruct project object
     */
    virtual ~Project();

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
     * @brief getDataMap Get all data of model with a HashMap key/value
     * @return Model's data
     */
    QVariantHash getDataMap();

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
     * @brief Project::getBeginDate return the date of creation
     * of the <b>Project</b>
     * @return the begin date of the Project
     */
    QDate getBeginDate() const;

    /**
     * @brief Project::setBeginDate Modify <i>beginDate</i> of a <b>Project</b>
     * @param beginDate the new date of creation of the project
     */
    void setBeginDate(QDate beginDate);

    /**
     * @brief Project::getEndDate Return the <i>endDate</i> of the <b>Project</b>
     * @return the end date of the project
     */
    QDate getEndDate() const;

    /**
     * @brief Project::setEndDate Modify <i>endDate</i> of <b>Project</b>
     * @param endDate the new end date of the project
     */
    void setEndDate(QDate endDate);

    /**
     * @brief Project::getCost Return the <b>Project</b> <i>cost</i>
     * @return the project cost
     */
    double getCost() const;

    /**
     * @brief Project::setCost Modify the <b>Project</b> <i>cost</i>
     * @param cost the projectCost
     */
    void setCost(double cost);

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
    QSharedPointer<Customer> getCustomer() const;

    /**
     * @brief Project::setCustomer Modify the <i>customer</i> linked to this
     * project
     * @param customer New customer associated to this project
     */
    void setCustomer(QSharedPointer<Customer> customer);

    /**
     * @brief Project::operator == Re-define the operator "==" to compare if
     * the current project is the same to the other <b>Project</b> <i>p</i>
     * Return TRUE if both projects are the same, else FALSE
     * @param c Project to compare
     * @return boolean
     */
    bool operator ==(const Project &p);

    /**
     * @brief Project::operator < defines the operator "< to compare two
     * <b>Project</b> and to see if the fisrt is anterior to the second
     * @param b the <b>Project</b> to compare with the current <b>Project</b>
     * @return true if the <b>Project</b> are different else false
     */
    bool operator <(const Project &p) const;

    /**
     * @brief Project::operator == Re-define the operator "!=" to compare if
     * the current project is differnt to the other <b>Project</b> <i>p</i>
     * Return TRUE if both projects are different, else FALSE
     * @param c Project to compare
     * @return boolean
     */
    bool operator !=(const Project &p);

    /**
     * @brief Project::costCompute compute the <b>Project</b> <i>cost</i>
     * @return the project cost
     */
    double costCompute();

private:
    QString _name;          //!< Project name
    QString _description;   //!< Description on the targets of this project
    QDate _beginDate;       //!< Date of creation of the project
    QDate _endDate;         //!< End date of the project
    double _cost;           //!< Project cost
    double _dailyRate;      //!< Daily rate linked to this project
    QSharedPointer<Customer> _customer;    //!< Customer linked to this project
};
}
#endif // PROJECT_H
