#ifndef CONTRIBUTORY_H
#define CONTRIBUTORY_H
#include "models/project.h"
#include "models/imodel.h"

namespace Models {
/**
 * @author
 * @brief The Contributory class
 */
class Contributory : public IModel
{
public:
    /**
     * @brief Contributory::Contributory Contruct a Contributory
     */
    Contributory();

    /**
     * @brief Contributory::Contributory Contruct a Contributory and get data in database
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
     *  Project linke to this Contributory
     * @param id Project Identify
     */
    void setProject(Project *id);

    /**
     * @brief getNbHours Number of work hour of a contributory
     * @return Then number of hours
     */
    double getNbHours() const;

    /**
     * @brief setNbHours Change nbHours
     * @param value The new value of nbHours
     */
    void setNbHours(double value);

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

private:
    Project* _project;    //!< Contributory project
    double _nbHours; //!< Nb of work hours of this contribution
    QString _description; //!< Description
};
}
#endif // CONTRIBUTORY_H
