#ifndef IMODEL_H
#define IMODEL_H
#include <QVariantHash>

/**
 * @brief Models classes
 */
namespace Models {
/**
 * @author Antoine de Roquemaurel
 * @brief The IModel class
 */
class IModel
{
public:
    /**
     * @brief ~IModel Remove an instance of IModel
     */
    virtual ~IModel() {}

    /**
     * @brief IModel::commit Update or insert data into the database
     */
    virtual void commit() = 0;
    /**
     * @brief IModel::hydrat Get data of the element which is specified
     * by the identify <i>id</i> from the database
     * @param id
     */
    virtual void hydrat(int id) = 0;
    /**
     * @brief IModel::remove Remove the current element in the database
     */
    virtual void remove() = 0;

    /**
     * @brief getDataMap Get all data of model with a HashMap key/value
     * @return Model's data
     */
    virtual QVariantHash getDataMap() = 0;
    /**
     * @brief IModel::getId Return the identify of the element of the
     * database
     * @return identity
     */
    int getId() const { return _id; }
    /**
     * @brief IModel::setId Replace the current identify by <i>id</i>
     * @param id New identify
     */
    void setId(int id) { _id = id; }

    /**
     * @brief toRemoved return if object must be removed.
     * @return boolean
     */
    bool isToRemoved() const
    {
        return _toRemoved;
    }

    /**
     * @brief setToRemoved Change the flag for removed object
     * @param toRemoved The new flag
     */
    void setToRemoved(bool toRemoved)
    {
        _toRemoved = toRemoved;
    }

protected:
    int _id;            //!< Element identify
    bool _toRemoved;    //!< Flag to know if the object must be removed
};
}
#endif // IModel_H
