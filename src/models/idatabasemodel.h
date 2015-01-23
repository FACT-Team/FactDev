#ifndef IDATABASEMODEL_H
#define IDATABASEMODEL_H

/**
 * @author Antoine de Roquemaurel
 * @brief The IDatabaseModel class
 */
class IDatabaseModel
{
public:
    /**
     * @brief IDatabaseModel::commit Update or insert data into the database
     */
    virtual void commit() = 0;
    /**
     * @brief IDatabaseModel::hydrat Get data of the element which is specified
     * by the identify <i>id</i> from the database
     * @param id
     */
    virtual void hydrat(int id) = 0;
    /**
     * @brief IDatabaseModel::remove Remove the current element in the database
     */
    virtual void remove() = 0;

    /**
     * @brief IDatabaseModel::getId Return the identify of the element of the
     * database
     * @return identity
     */
    int getId() const { return _id; }
    /**
     * @brief IDatabaseModel::setId Replace the current identify by <i>id</i>
     * @param id New identify
     */
    void setId(int id) { _id = id; }

    /**
     * @brief toRemoved return if object must be removed.
     * @return
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
    int _id;    //!< Element identify
    bool _toRemoved; //!< Flag to know if the object must be removed
};

#endif // IDATABASEMODEL_H





