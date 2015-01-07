#ifndef BILLING_H
#define BILLING_H
#include "models/idatabasemodel.h"
#include "models/project.h"
#include <QString>
#include <QDate>
#include <QMap>
#include <QList>

class Billing:public IDatabaseModel
{
public:
    Billing();
    void commit();
    void hydrat(int getId);
    void remove();

    QMap<Project, QList<Contributory> > getContributories() const;
    void setContributories(const QMap<Project, QList<Contributory> > &getContributories);

    QString getTitle() const;
    void setTitle(const QString &getTitle);

    int getNumber() const;
    void setNumber(int getNumber);

    bool isBilling() const;
    void setIsBilling(bool isBilling);

    QDate getDate() const;
    void setDate(const QDate &getDate);

private:
    QMap<Project,QList<Contributory> > _contributories;
    QString _title;
    int _number;
    bool _isBilling;
    QDate _date;


};

#endif // BILLING_H
