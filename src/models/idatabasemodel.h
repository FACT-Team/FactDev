#ifndef IDATABASEMODEL_H
#define IDATABASEMODEL_H

class IDatabaseModel
{
public:
    void virtual commit() = 0;
    void virtual hydrat() = 0;
    void virtual remove() = 0;
protected:
    int id;
};

#endif // IDATABASEMODEL_H
