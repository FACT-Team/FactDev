#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QString>
#include "models/idatabasemodel.h"

class Customer : public IDatabaseModel
{
public:
    Customer();
    void commit();
    void hydrat(int getId);
    void remove();

    QString getFirstnameReferent() const;
    void setFirstnameReferent(const QString &getFirstnameReferent);

    QString getLastnameReferent() const;
    void setLastnameReferent(const QString &getLastnameReferent);

    QString getCompany() const;
    void setCompany(const QString &getCompany);

    QString getAddress() const;
    void setAddress(const QString &getAddress);

    QString getPostalCode() const;
    void setPostalCode(const QString &getPostalCode);

    QString getCity() const;
    void setCity(const QString &getCity);

    QString getCountry() const;
    void setCountry(const QString &country);

    QString getEmail() const;
    void setEmail(const QString &getEmail);

    QString getMobilePhone() const;
    void setMobilePhone(const QString &getMobilePhone);

    QString getPhone() const;
    void setPhone(const QString &getPhone);

    QString getFax() const;
    void setFax(const QString &getFax);

    bool operator ==(const Customer &c);
    bool operator !=(const Customer &c);
private:
    int _id;
    QString _firstnameReferent;
    QString _lastnameReferent;
    QString _company;
    QString _address;
    QString _postalCode;
    QString _city;
    QString _country;
    QString _email;
    QString _mobilePhone;
    QString _phone;
    QString _fax;
};

#endif // CUSTOMER_H
