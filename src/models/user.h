#ifndef USER_H
#define USER_H
#include <QString>
#include "models/idatabasemodel.h"

/**
 * @author Florent Berbie
 * @brief The User class <b>User</b> of it application
 */
class User : public IDatabaseModel
{
public:
    /**
     * @brief User::User. Contruct an User
     */
    User();

    /**
     * @brief User::User. Construct a User with the identify <i>id</i>
     * @param id User id
     */
    User(int id);

    /**
     * @brief User::commit Update user data in User table on the database
     */
    void commit();

    /**
     * @brief User::hydrat Get data of the user who is specified by <i>id</i>
     * from the database
     * @param id User identify
     */
    void hydrat(int id=1);

    /**
     * @brief remove Remove the current User
     */
    void remove();

    /**
     * @brief User::getFirstname Return the user firstname
     * @return User firstname
     */
    QString getFirstname() const;
    /**
     * @brief User::setFirstnament Modify the user <i>firstname</i>
     * @param firstname New user firstname
     */
    void setFirstname(const QString &firstname);

    /**
     * @brief User::getLastname Return the user lastname
     * @return  User lastname
     */
    QString getLastname() const;
    /**
     * @brief User::setLastname Modify the user <i>lastname</i>
     * @param lastname New user lastname
     */
    void setLastname(const QString &lastname);

    /**
     * @brief User::getCompany Return the user company
     * @return New company name
     */
    QString getCompany() const;
    /**
     * @brief User::setCompany Modify the user <i>company</i> name
     * @param company New user company name
     */
    void setCompany(const QString &company);

    /**
     * @brief User::getTitle Return a short description of User (company)
     *  activity
     * @return a short description of user (company) activity
     */
    QString getTitle() const;
    /**
     * @brief User::setTitle Modify the user/company activities
     *  <i>description</i>
     * @param title Short description on activity(ies) of customer company
     */
    void setTitle(const QString &title);

    /**
     * @brief User::getAddress Return the company addess (Number and name of
     *  street)
     * @return Address company
     */
    QString getAddress() const;
    /**
     * @brief User::setAddress Modify the user company <i>address</i>
     * @param address Company address (name and number of street)
     */
    void setAddress(const QString &address);

    /**
     * @brief User::getPostalCode Return the postal code
     * @return postal code
     */
    QString getPostalCode() const;
    /**
     * @brief User::setPostalCode Modify the postal code <i>postalCode</i>
     * @param postalCode New postal code
     */
    void setPostalCode(const QString &postalCode);

    /**
     * @brief User::getCity Return the city
     * @return city
     */
    QString getCity() const;
    /**
     * @brief User::setCity Modify the <i>city</i>
     * @param city Company city address
     */
    void setCity(const QString &city);

    /**
     * @brief User::getEmail Return the user professional <i>email</i>
     * @return professional email
     */
    QString getEmail() const;
    /**
     * @brief User::setEmail Modify the user professional <i>email</i>
     * @param email The user professional email
     */
    void setEmail(const QString &email);

    /**
     * @brief User::getMobilePhone Return the number of the professional
     *  mobile phone
     * @return number of mobile phone
     */
    QString getMobilePhone() const;
    /**
     * @brief User::setMobilePhone Modify the number of the professional user
     *  mobile phone <i>mobilePhone</i>
     * @param mobilePhone Number of the professional mobile phone
     */
    void setMobilePhone(const QString &mobilePhone);

    /**
     * @brief User::getPhone Return the number of the desktop phone
     * @return number of the desktop phone
     */
    QString getPhone() const;
    /**
     * @brief User::setPhone Modify the number of the desktop <i>phone</i>
     * @param phone Number of the desktop phone
     */
    void setPhone(const QString &phone);

    /**
     * @brief User::getNoSiret Return the SIRET number (company registration
     *  number)
     * @return SIRET number
     */
    int getNoSiret() const;
    /**
     * @brief User::setNoSiret Modify the SIRET number (company registration
     *  number) <i>noSiret</i>
     * @param noSiret SIRET number
     */
    void setNoSiret(int noSiret);

private:
    QString _firstname;     //!< User firstname
    QString _lastname;      //!< User lastname
    QString _company;       //!< Company name of the User
    QString _title;         //!< Customer/Company description on it activity
    QString _address;       //!< Name and number of street
    QString _postalCode;    //!< Postal code
    QString _city;          //!< City
    QString _email;         //!< Professionnal email of the company
    QString _mobilePhone;   //!< Professionnal number of mobile phone
    QString _phone;         //!< Number of desktop phone
    int _noSiret;           //!<  SIRET number (company registration number)
};

#endif // USER_H
