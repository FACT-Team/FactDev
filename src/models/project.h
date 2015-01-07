#ifndef PROJECT_H
#define PROJECT_H
#include <QString>
#include "models/idatabasemodel.h"
#include "models/customer.h"

class Project : public IDatabaseModel
{
public:
    Project();
    void commit();
    void hydrat(int getId);
    void remove();

    QString getName() const;
    void setName(const QString &getName);

    QString getDescription() const;
    void setDescription(const QString &getDescription);

    double geDailyRate() const;
    void setDailyRate(double geDailyRate);

    Customer getCustomer() const;
    void setCustomer(Customer getCustomer);

private:
    int _id;
    QString _name;
    QString _description;
    double _dailyRate;
    Customer _customer;
};

#endif // PROJECT_H
