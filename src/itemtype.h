#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <QString>
#include "models/idatabasemodel.h"

class ItemType
{
public:
    static const int CUSTOMER = 0;
    static const int PROJECT = 1;
    static const int BILLING = 2;
    static const int QUOTE = 3;

    ItemType(int type, QString name);

    QString getName() const;
    void setName(const QString &name);

    IDatabaseModel* getModel(int id);
    int getType() const;
    void setType(int getType);

private:
    QString _name;
    int _type;
};

#endif // ITEMTYPE_H
