#ifndef USER_H
#define USER_H
#include <QString>
#include <QDir>
#include <QStandardPaths>

#include "models/imodel.h"
#include "models/project.h"
#include "models/customer.h"

#include "utils/log.h"
#include "utils/directories.h"

namespace Models {
/**
 * @author Florent Berbie
 * @brief The User class <b>User</b> of it application
 */
class User : public IModel
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
     * @brief getDataMap Get all data of model with a HashMap key/value
     * @return Model's data
     */
    QVariantHash getDataMap();


    /**
     * @brief MainWindow::updateFolders Make directories which contain quotes
     * and billings. Directories are the same than theirs of the Tree
     * organisation (without Projects).
     *
     * Organisation of folders are formed like this:
     *  + COMPANY CustomerLastname CustomerFirstname/
     *      + Quotes/
     *          - quote1
     *          ...
     *      + Billings/
     *          - billing1
     *          ...
     */
    void updateFolders(void);

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
     * @param title Short description on activity(ies) of User company
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
    QString getNoSiret() const;
    /**
     * @brief User::setNoSiret Modify the SIRET number (company registration
     *  number) <i>noSiret</i>
     * @param noSiret SIRET number
     */
    void setNoSiret(const QString &noSiret);

    /**
     * @brief User::getWorkspaceName Return the name of the workspace user
     * @return workspace name
     */
    QString getWorkspaceName() const;
    /**
     * @brief User::setWorkspaceName Change the current workspace name by the
     * new <i>workspaceName</i>
     * @param workspaceName
     */
    void setWorkspaceName(const QString &workspaceName);

    /**
     * @brief User::getWorkspacePath Return the path of the workspace user
     * @return workspace path
     */
    QString getWorkspacePath() const;
    /**
     * @brief User::setWorkspacePath Change the current workspace path by the
     * new <i>workspacePath</i>
     * @param workspacePath
     */
    void setWorkspacePath(const QString &workspacePath);

    /** @brief User::operator == Re-define the operator "==" to compare if
     * the current User is the same to the other <b>User</b> <i>c</i>
     * Return TRUE if both Users are the same, else FALSE
     * @param u User to compare
     * @return boolean
     */
    bool operator ==(const User &u);
    /**
     * @brief User::operator == Re-define the operator "!=" to compare if
     * the current User is differnt to the other <b>User</b> <i>c</i>
     * Return TRUE if both Users are different, else FALSE
     * @param u User to compare
     * @return boolean
     */
    bool operator !=(const User &u);

private:
    QString _firstname;     //!< User firstname
    QString _lastname;      //!< User lastname
    QString _company;       //!< Company name of the User
    QString _title;         //!< User/Company description on it activity
    QString _address;       //!< Name and number of street
    QString _postalCode;    //!< Postal code
    QString _city;          //!< City
    QString _email;         //!< Professionnal email of the company
    QString _mobilePhone;   //!< Professionnal number of mobile phone
    QString _phone;         //!< Number of desktop phone
    QString _noSiret;       //!< SIRET number (company registration number)
    QString _workspaceName; //!< Workspace name
    QString _workspacePath; //!< Workspace directory path
};
}
#endif // USER_H
