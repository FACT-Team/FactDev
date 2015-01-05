#ifndef PROJECT_H
#define PROJECT_H
#include <QString>

class Project
{
public:
    Project();

    QString getName() const;
    void setName(const QString &getName);

    QString getDescription() const;
    void setDescription(const QString &getDescription);

    double geDailyRate() const;
    void setDailyRate(double geDailyRate);

    int getIdCustomer() const;
    void setIdCustomer(int getIdCustomer);

private:
    int _id;
    QString _name;
    QString _description;
    double _dailyRate;
    int _idCustomer;
};

#endif // PROJECT_H
