#include "models/people.h"
#include <QDebug>

namespace Models {

People::People()
{

}

QString People::getFirstname() const
{
    return _firstname;
}

void People::setFirstname(const QString &firstname)
{
    _firstname = firstname;
}

QString People::getLastname() const
{
    return _lastname;
}

void People::setLastname(const QString &lastname)
{
    _lastname = lastname;
}

QString People::getCompany() const
{
    return _company;
}

void People::setCompany(const QString &company)
{
    _company = company;
}

QString People::getAddress() const
{
    return _address;
}

void People::setAddress(const QString &address)
{
    _address = address;
}

QString People::getPostalCode() const
{
    return _postalCode;
}

void People::setPostalCode(const QString &postalCode)
{
    _postalCode = postalCode;
}

QString People::getCity() const
{
    return _city;
}

void People::setCity(const QString &city)
{
    _city = city;
}

QString People::getCountry() const
{
    return _country;
}

void People::setCountry(const QString &country)
{
    _country = country;
}

QString People::getEmail() const
{
    return _email;
}

void People::setEmail(const QString &email)
{
    _email = email;
}

QString People::getPhone() const
{
    return _phone;
}

void People::setPhone(const QString &phone)
{
    _phone = phone;
}

QString People::getMobilePhone() const
{
    return _mobilePhone;
}

void People::setMobilePhone(const QString &mobilePhone)
{
    _mobilePhone = mobilePhone;
}

QString People::getFax() const
{
    return _fax;
}

void People::setFax(const QString &fax)
{
    _fax = fax;
}

QPixmap *People::getImage() const
{
    return _image;
}

void People::setImage(QPixmap *image)
{
    _image = image;
}

bool People::operator ==(const People &p)
{
    return  p.getFirstname() == getFirstname()
            && p.getLastname() == getLastname()
            && p.getCompany() == getCompany()
            && p.getAddress() == getAddress()
            && p.getPostalCode() == getPostalCode()
            && p.getCity() == getCity()
            && p.getCountry() == getCountry()
            && p.getEmail() == getEmail()
            && p.getPhone() == getPhone()
            && p.getMobilePhone() == getMobilePhone()
            && p.getFax() == getFax();
}

bool People::operator !=(const People &u)
{
    return !(*this == u);
}

QString People::getExtensionImage() const
{
    return _extensionImage;
}

void People::setExtensionImage(const QString &ext)
{
    _extensionImage = ext;
}




}

