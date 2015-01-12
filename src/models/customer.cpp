#include "models/customer.h"

Customer::Customer()
{
}

void Customer::commit()
{
    // TODO implement me !
}

void Customer::hydrat(int id)
{
    // TODO implement me !
}

void Customer::remove()
{
    // TODO implement me !
}
bool Customer::operator==(const Customer &c)
{
    // all fields are the same.
    return getAddress() == c.getAddress() && getFirstnameReferent() == c.getFirstnameReferent() &&
            getCity() == c.getCity() && getCompany() == c.getCompany() && getCountry() == c.getCountry() &&
            getEmail() == c.getEmail() && getFax() == c.getFax() && getId() == c.getId() &&
            getLastnameReferent() == c.getLastnameReferent() &&
            getMobilePhone() == c.getMobilePhone() && getPhone() == c.getPhone() && getPostalCode() == c.getPostalCode();
}

bool Customer::operator!=(const Customer &c)
{
    return !(*this == c); // not equals
}

QString Customer::getFirstnameReferent() const
{
    return _firstnameReferent;
}

void Customer::setFirstnameReferent(const QString &firstnameReferent)
{
    _firstnameReferent = firstnameReferent;
}
QString Customer::getLastnameReferent() const
{
    return _lastnameReferent;
}

void Customer::setLastnameReferent(const QString &lastnameReferent)
{
    _lastnameReferent = lastnameReferent;
}
QString Customer::getCompany() const
{
    return _company;
}

void Customer::setCompany(const QString &company)
{
    _company = company;
}
QString Customer::getAddress() const
{
    return _address;
}

void Customer::setAddress(const QString &address)
{
    _address = address;
}
QString Customer::getPostalCode() const
{
    return _postalCode;
}

void Customer::setPostalCode(const QString &postalCode)
{
    _postalCode = postalCode;
}
QString Customer::getCity() const
{
    return _city;
}

void Customer::setCity(const QString &city)
{
    _city = city;
}
QString Customer::getEmail() const
{
    return _email;
}

void Customer::setEmail(const QString &email)
{
    _email = email;
}
QString Customer::getMobilePhone() const
{
    return _mobilePhone;
}

void Customer::setMobilePhone(const QString &mobilePhone)
{
    _mobilePhone = mobilePhone;
}
QString Customer::getPhone() const
{
    return _phone;
}

void Customer::setPhone(const QString &phone)
{
    _phone = phone;
}
QString Customer::getFax() const
{
    return _fax;
}

void Customer::setFax(const QString &fax)
{
    _fax = fax;
}


QString Customer::getCountry() const
{
    return _country;
}

void Customer::setCountry(const QString &country)
{
    _country = country;
}











