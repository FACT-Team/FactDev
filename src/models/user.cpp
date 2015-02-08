#include "models/user.h"
#include "database/userdatabase.h"

using namespace Database;

namespace Models {
User::User()
{

}

User::User(int id)
{
    hydrat(id);
}

void User::commit() {
    if(!_toRemoved) {
        UserDatabase::instance()->updateUser(*this);
    } else {
        remove();
    }
}

void User::remove()
{
    // Not use
    Log::instance(WARNING) << "User::remove is not implemented";
}

QVariantHash User::getDataMap()
{
    QVariantHash data;

    data["firstName"] = _firstname;
    data["lastName"] = _lastname;
    data["title"] = _title;
    data["address"] = _address;
    // TODO user address additions…
    data["postalCode"] = _postalCode;
    data["city"] = _city;
    data["phone"] = _phone;
    data["email"] = _email;

    return data;
}

void User::hydrat(int id)
{
    User* user = UserDatabase::instance()->getUser(id);
    _id = id;
    _firstname = user->getFirstname();
    _lastname = user->getLastname();
    _company = user->getCompany();
    _title = user->getTitle();
    _address = user->getAddress();
    _postalCode = user->getPostalCode();
    _city = user->getCity();
    _email = user->getEmail();
    _mobilePhone = user->getMobilePhone();
    _phone = user->getPhone();
    _noSiret = user->getNoSiret();
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

QString User::getTitle() const
{
    return _title;
}

void User::setTitle(const QString &title)
{
    _title = title;
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
QString User::getNoSiret() const
{
    return _noSiret;
}

void User::setNoSiret(const QString &noSiret)
{
    _noSiret = noSiret;
}
}
