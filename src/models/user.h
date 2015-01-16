#ifndef USER_H
#define USER_H
#include <QString>
#include "models/idatabasemodel.h"

class User
{
public:
    User();

    void commit();
    void hydrat(int getId);

    int getId() const;
    void setId(int getId);

    QString getFirstname() const;
    void setFirstname(const QString &getFirstname);

    QString getLastname() const;
    void setLastname(const QString &getLastname);

    QString getCompany() const;
    void setCompany(const QString &getCompany);

    QString getTitle() const;
    void setTitle(const QString &getTitle);

    QString getAddress() const;
    void setAddress(const QString &getAddress);

    QString getPostalCode() const;
    void setPostalCode(const QString &getPostalCode);

    QString getCity() const;
    void setCity(const QString &getCity);

    QString getCountry() const;
    void setCountry(const QString &getCountry);

    QString getEmail() const;
    void setEmail(const QString &getEmail);

    QString getMobilePhone() const;
    void setMobilePhone(const QString &getMobilePhone);

    QString getPhone() const;
    void setPhone(const QString &getPhone);

    QString getFax() const;
    void setFax(const QString &getFax);

    QString getNoSiret() const;
    void setNoSiret(const QString &getNoSiret);


private:
    int _id;
    QString _firstname;
    QString _lastname;
    QString _company;
    QString _title;
    QString _address;
    QString _postalCode;
    QString _city;
    QString _country;
    QString _email;
    QString _mobilePhone;
    QString _phone;
    QString _fax;
    QString _noSiret;
};

#endif // USER_H
