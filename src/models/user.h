#ifndef USER_H
#define USER_H
#include <QString>
#include "models/idatabasemodel.h"

class User : public IDatabaseModel
{
public:
    User(int id);
    User();
    void commit();
    void hydrat(int id=1);
    void remove();

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

    QString getEmail() const;
    void setEmail(const QString &getEmail);

    QString getMobilePhone() const;
    void setMobilePhone(const QString &getMobilePhone);

    QString getPhone() const;
    void setPhone(const QString &getPhone);

    int getNoSiret() const;
    void setNoSiret(int getNoSiret);

private:
    /**
     * @brief _firstname User firstname
     */
    QString _firstname;
    QString _lastname;
    QString _company;
    QString _title;
    QString _address;
    QString _postalCode;
    QString _city;
    QString _email;
    QString _mobilePhone;
    QString _phone;
    int _noSiret;
};

#endif // USER_H
