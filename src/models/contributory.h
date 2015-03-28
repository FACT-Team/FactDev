#ifndef CONTRIBUTORY_H
#define CONTRIBUTORY_H
#include "models/project.h"
#include "models/imodel.h"
#include "models/unit.h"
#include "models/calculable.h"

namespace Models {
/**
 * @brief The Unit enum Unity of work : hour or day
 */

/**
 * @author
 * @brief The Contributory class
 */
class Contributory : public IModel, public Calculable
{
public:
    /**
     * @brief Contributory::Contributory Contruct a Contributory
     */
    Contributory();

    /**
     * @brief Contributory::Contributory Contruct a Contributory and get data in
     *  database
     * @param id Contributory's id
     */
    Contributory(int id);

    /**
      @brief Destroy an contributory object
      */
    ~Contributory();

    /**
     * @brief Contributory::commit Update or insert a contributory to the
     * database
     */
    void commit();

    /**
     * @brief Contributory::hydrat Get data about the Contributory which is
     *  specified by the identify <i>id</i>
     * @param id Contributory identify
     */
    void hydrat(int id);

    /**
     * @brief Contributory::remove Remove the current Contributory
     */
    void remove();

    /**
     * @brief getPrice Return the price of a contributory
     * @return The price
     */
    double getPrice(const bool paied=false);

    /**
     * @brief ContributoriesList::getSumQuantity Return the sum of quantity
     * (number of hours) of the Contributories
     * @return sum of quantity in hours
     */
    double getSumQuantity();

    /**
     * @brief getDataMap Get all data of model with a HashMap key/value
     * @return Model's data
     */
    QVariantHash getDataMap();

    /**
     * @brief Contributory::getProject Return the project linked to this
     * Contributory
     * @return Project linked to this Contributory
     */
    Project* getProject() const;

    /**
     * @brief Contributory::setProject Modify the identify <i>id</i> of the
     *  Project linked to this Contributory
     * @param id Project Identify
     */
    void setProject(Project *id);

    /**
     * @brief getNbHours Number of work hour of a contributory
     * @return Then number of hours
     */
    double getQuantity() const;

    /**
     * @brief setNbHours Change nbHours
     * @param value The new value of nbHours
     */
    void setQuantity(double value);

    /**
     * @brief getDescription Description of a contributory
     * @return The description
     */
    QString getDescription() const;

    /**
     * @brief setDescription Change the contributory description
     * @param getDescription The new description
     */
    void setDescription(const QString &getDescription);

    /**
     * @brief operator == define the operator "==" to compare two
     * <b>Contributory</b>
     * @param c the <b>Contributory</b> to compare with the current
     * <b>Contributory</b>
     * @return true if the <b>Contributory</b> are equals else false
     */
    bool operator ==(const Contributory &c);

    /**
     * @brief operator != define the operator "!=" to compare two
     * <b>Contributory</b>
     * @param c the <b>Contributory</b> to compare with the current
     * <b>Contributory</b>
     * @return true if the <b>Contributory</b> are different else false
     */
    bool operator !=(const Contributory &c);

    /**
     * @brief getLongDescription A contributory has a long description : display in tex appendix
     * @return The long description
     */
    QString getLongDescription() const;

    /**
     * @brief setLongDescription Change the long description
     * @param getLongDescription The new description
     */
    void setLongDescription(const QString &getLongDescription);

    /**
     * @brief getUnit Return the unit (hour or day) of contributory
     * @return The unit
     */
    Unit getUnit() const;

    /**
     * @brief setUnit Change the unit
     * @param value The new unit
     */
    void setUnit(const Unit &value);

    /**
     * @brief getHourlyRate Hourly rate for this contributory
     * @return  The hourly rate
     */
    double getHourlyRate() const;

    /**
     * @brief setHourlyRate Change the hourly rate for this contributory
     * @param value The hourly rate
     */
    void setHourlyRate(double value);

private:
    Project* _project;          //!< Contributory project
    double _quantity;            //!< Quantity of work of this contributory
    double _hourlyRate;         //!< Hourly rate for this contributory
    Unit _unit;                  //!< Unit of work of this contributory
    QString _description;       //!< Contributory description
    QString _longDescription;   //!< Long contributory description
};
}
#endif // CONTRIBUTORY_H
