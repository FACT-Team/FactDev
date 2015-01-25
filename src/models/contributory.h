#ifndef CONTRIBUTORY_H
#define CONTRIBUTORY_H
#include "models/project.h"
#include "models/idatabasemodel.h"

/**
 * @author
 * @brief The Contributory class
 */
class Contributory : public IDatabaseModel
{
public:
    /**
     * @brief Contributory::Contributory Contruct a Contributory
     */
    Contributory();

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

    double getNbHours() const;
    void setNbHours(double value);

    QString getDescription() const;
    void setDescription(const QString &getDescription);

private:
    Project* project;    //!<
    double _nbHours;
    QString _description;
};

#endif // CONTRIBUTORY_H
