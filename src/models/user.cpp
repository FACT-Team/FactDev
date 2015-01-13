#include "models/user.h"
#include "database/userdatabase.h"

User::User()
{
    _id = 1;
}

void User::commit() {
    UserDatabase::instance()->updateUser(*this);
}

void User::hydrat(int id)
{
    User* user = UserDatabase::instance()->getUser();
    _id = id;
    _firstname = user->getFirstname();
    _lastname = user->getLastname();
    _address = user->getAddress();
    _city = user->getCity();
    _company = user->getCompany();
    _country = user->getCountry();
    _email = user->getEmail();
    _fax = user->getFax();    
    _phone = user->getPhone();
    _mobilePhone = user->getMobilePhone();
    _postalCode = user->getPostalCode();
    _noSiret = user->getNoSiret();
}

int User::getId() const {
    return _id;
}

void User::setId(int id) {
    _id = id;
}

QString User::getFirstname() const
{
    return _firstname;
}

void User::setFirstname(const QString &firstname)
{
    _firstname = firstname;
}

QString User::getLastname() const
{
    return _lastname;
}

void User::setLastname(const QString &lastname)
{
    _lastname = lastname;
}

QString User::getCompany() const
{
    return _company;
}

void User::setCompany(const QString &company)
{
    _company = company;
}
QString User::getAddress() const
{
    return _address;
}

void User::setAddress(const QString &address)
{
    _address = address;
}
QString User::getPostalCode() const
{
    return _postalCode;
}

void User::setPostalCode(const QString &postalCode)
{
    _postalCode = postalCode;
}
QString User::getCity() const
{
    return _city;
}

void User::setCity(const QString &city)
{
    _city = city;
}
QString User::getCountry() const
{
    return _country;
}

void User::setCountry(const QString &country)
{
    _country = country;
}
QString User::getEmail() const
{
    return _email;
}

void User::setEmail(const QString &email)
{
    _email = email;
}
QString User::getMobilePhone() const
{
    return _mobilePhone;
}

void User::setMobilePhone(const QString &mobilePhone)
{
    _mobilePhone = mobilePhone;
}
QString User::getPhone() const
{
    return _phone;
}

void User::setPhone(const QString &phone)
{
    _phone = phone;
}
QString User::getFax() const
{
    return _fax;
}

void User::setFax(const QString &fax)
{
    _fax = fax;
}
QString User::getNoSiret() const
{
    return _noSiret;
}

void User::setNoSiret(const QString &noSiret)
{
    _noSiret = noSiret;
}
