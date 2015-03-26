#ifndef PEOPLE_H
#define PEOPLE_H
#include <QString>
#include <QPixmap>

namespace Models {
/**
 * @brief The People class People
 */
class People
{
public:
    /**
     * @brief People::People Construct a People
     */
    People();

    /**
     * @brief People::getFirstname Return the People firstname
     * @return People firstname
     */
    QString getFirstname() const;
    /**
     * @brief People::setFirstnament Modify the People <i>firstname</i>
     * @param firstname New People firstname
     */
    void setFirstname(const QString &firstname);

    /**
     * @brief People::getLastname Return the People lastname
     * @return People lastname
     */
    QString getLastname() const;
    /**
     * @brief People::setLastname Modify the People <i>lastname</i>
     * @param lastname New People lastname
     */
    void setLastname(const QString &lastname);

    /**
     * @brief People::getCompany Return the People company
     * @return New company name
     */
    QString getCompany() const;
    /**
     * @brief People::setCompany Modify the People <i>company</i> name
     * @param company New People company name
     */
    void setCompany(const QString &company);

    /**
     * @brief People::getAddress Return the company addess (Number and name of
     * street)
     * @return Address company
     */
    QString getAddress() const;
    /**
     * @brief People::setAddress Modify the People company <i>address</i>
     * @param address Company address (name and number of street)
     */
    void setAddress(const QString &address);

    /**
     * @brief People::getPostalCode Return the postal code
     * @return postal code
     */
    QString getPostalCode() const;
    /**
     * @brief People::setPostalCode Modify the postal code <i>postalCode</i>
     * @param postalCode New postal code
     */
    void setPostalCode(const QString &postalCode);

    /**
     * @brief People::getCity Return the city
     * @return city
     */
    QString getCity() const;
    /**
     * @brief People::setCity Modify the <i>city</i>
     * @param city Company city address
     */
    void setCity(const QString &city);

    /**
     * @brief People::getCountry Return the country of the People
     * @return country of the People
     */
    QString getCountry() const;
    /**
     * @brief People::setCountry Replace the country of the People
     * by <i>country</i>
     * @param country New country of the People
     */
    void setCountry(const QString &country);

    /**
     * @brief People::getEmail Return the People professional <i>email</i>
     * @return professional email
     */
    QString getEmail() const;
    /**
     * @brief People::setEmail Modify the People professional <i>email</i>
     * @param email The People professional email
     */
    void setEmail(const QString &email);

    /**
     * @brief People::getPhone Return the number of the desktop phone
     * @return number of the desktop phone
     */
    QString getPhone() const;
    /**
     * @brief People::setPhone Modify the number of the desktop <i>phone</i>
     * @param phone Number of the desktop phone
     */
    void setPhone(const QString &phone);

    /**
     * @brief People::getMobilePhone Return the number of the professional
     * mobile phone
     * @return number of mobile phone
     */
    QString getMobilePhone() const;
    /**
     * @brief People::setMobilePhone Modify the number of the professional People
     * mobile phone <i>mobilePhone</i>
     * @param mobilePhone Number of the professional mobile phone
     */
    void setMobilePhone(const QString &mobilePhone);
    /**
     * @brief People::getFax Return the fax number
     * @return fax number
     */
    QString getFax() const;
    /**
     * @brief People::setFax Replace the current fax number by <i>fax</i>
     * @param fax new fax number
     */
    void setFax(const QString &fax);

    /**
     * @brief People::getImage Return the compagny image
     * @return compagny image
     */
    QPixmap getImage() const;
    /**
     * @brief People::setImage Modify the current compagny image by <i>image</i>
     * @param image Compagny image
     */
    void setImage(const QPixmap &image);

    /**
     * @brief People::getExtensionImage Return the extension of the image file
     * @return Extension of image file
     */
    QString getExtensionImage() const;
    /**
     * @brief People::setExtensionImage Change the extension of the image file
     * by the new <i>ext</i>
     * @param ext Extension file
     */
    void setExtensionImage(const QString &ext);

    /**
     * @brief People::operator == Re-define the operator "==" to compare if
     * the current People is the same to the other <b>People</b> <i>c</i>
     * Return TRUE if both Peoples are the same, else FALSE
     * @param c People to compare
     * @return boolean
     */
    bool operator ==(const People &c);
    /**
     * @brief People::operator == Re-define the operator "!=" to compare if
     * the current People is differnt to the other <b>People</b> <i>c</i>
     * Return TRUE if both Peoples are different, else FALSE
     * @param c People to compare
     * @return boolean
     */
    bool operator !=(const People &c);

protected:
    QPixmap _image;         //!< Compagny image

private:
    QString _firstname;     //!< People firstname
    QString _lastname;      //!< People lastname
    QString _company;       //!< Company name of the People
    QString _address;       //!< Name and number of street
    QString _postalCode;    //!< Postal code
    QString _city;          //!< City
    QString _country;       //!< Country
    QString _email;         //!< Professionnal email
    QString _phone;         //!< Number of desktop phone
    QString _mobilePhone;   //!< Professionnal number of mobile phone
    QString _fax;           //!< Fax number of the people
    QString _extensionImage;//!< Image extension

};
}

#endif // PEOPLE_H
