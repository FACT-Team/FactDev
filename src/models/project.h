#ifndef PROJECT_H
#define PROJECT_H
#include <QString>
#include "models/idatabasemodel.h"
#include "models/customer.h"

class Project : public IDatabaseModel
{
public:
    Project();
    Project(int id);
    void commit();
    void hydrat(int getId);
    void remove();

    QString getName() const;
    void setName(const QString &getName);

    QString getDescription() const;
    void setDescription(const QString &getDescription);

    double getDailyRate() const;
    void setDailyRate(double getDailyRate);

    Customer getCustomer() const;
    void setCustomer(Customer getCustomer);

private:

    QString _name;
    QString _description;
    double _dailyRate;
    Customer _customer;
};

#endif // PROJECT_H
