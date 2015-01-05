#ifndef BILLING_H
#define BILLING_H
#include "models/idatabasemodel.h"
#include <QString>
#include <QDate>
#include <QMap>
#include <QList>
class Billing:public IDatabaseModel
{
public:
    Billing();

private:
    QMap<Project,QList<Contributory> > contributories;
    QString _title;
    int _number;
    bool _isBilling;
    QDate _date;
);

};

#endif // BILLING_H
