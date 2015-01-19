#ifndef IDATABASEMODEL_H
#define IDATABASEMODEL_H

/**
 * @author Antoine de Roquemaurel
 * @brief The IDatabaseModel class
 */
class IDatabaseModel
{
public:
    virtual void commit() = 0;
    virtual void hydrat(int id) = 0;
    virtual void remove() = 0;

    int getId() const { return _id; }
    void setId(int id) { _id = id; }

protected:
    int _id;
};

#endif // IDATABASEMODEL_H

