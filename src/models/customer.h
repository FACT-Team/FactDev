#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QString>
#include "models/imodel.h"


namespace Models {
/**
 * @author Antoine de Roquemaurel
 * @author Florent Berbie
 * @brief The Customer class Customer
 */
class Customer : public IModel
{
public:
    /**
     * @brief Customer::Customer Construct a Customer
     */
    Customer();
    /**
     * @brief Customer::Customer Constuct a Customer who is specidied by
     *  <i>id</i>
     * @param id Customer identify
     */
    Customer(int id);

    /**
     * @brief Customer::commit Update customer data on the database
     */
    void commit();

    /**
     * @brief Customer::hydrat Insert into database informations related to the
     *  Customer who is specified by <i>id</i>
     * @param id Customer identify
     */
    void hydrat(int id);

    /**
     * @brief Customer::remove Remove the current customer
     */
    void remove();

    /**
     * @brief getDataMap Get all data of model with a HashMap key/value
     * @return Model's data
     */
    QVariantHash getDataMap();

    /**
     * @brief Customer::getFirstnameReferent Return the firstname of the
     * referent Customer
     * @return Referent firstname of the customer
     */
    QString getFirstnameReferent() const;
    /**
     * @brief Customer::setFirstnameReferent Replace the referent firstname of
     * the customer by <i>firstnameReferent</i>
     * @param firstnameReferent New referent firstname of the Customer
     */
    void setFirstnameReferent(const QString &firstnameReferent);

    /**
     * @brief Customer::getLastnameReferent Return the lastname of the
     * referent Customer
     * @return Referent lastname of the customer
     */
    QString getLastnameReferent() const;
    /**
     * @brief Customer::setLarstnameReferent Replace the referent lastname of
     * the customer by <i>lastnameReferent</i>
     * @param lastnameReferent New referent lastname of the Customer
     */
    void setLastnameReferent(const QString &lastnameReferent);

    /**
     * @brief Customer::getCompany Return the name of the company customer
     * @return name of the company customer
     */
    QString getCompany() const;
    /**
     * @brief Customer::setCompany Replace the company name by <i>company</i>
     * @param company New company name
     */
    void setCompany(const QString &company);

    /**
     * @brief Customer::getAddress Return the address (name and street number)
     * of the customer company
     * @return company address
     */
    QString getAddress() const;
    /**
     * @brief Customer::setAddress Replace the current company address by the
     * new <i>address</i>
     * @param address New company address
     */
    void setAddress(const QString &address);

    /**
     * @brief Customer::getPostalCode  Return the postal code of the customer
     * company
     * @return postal code of the customer company
     */
    QString getPostalCode() const;
    /**
     * @brief Customer::setPostalCode Replace the current postal code of the
     * customer company by the new <i>postalCode</i>
     * @param postalCode New postal code of the customer company
     */
    void setPostalCode(const QString &postalCode);

    /**
     * @brief Customer::getCity Return the city of the customer company
     * @return city of the customer company
     */
    QString getCity() const;
    /**
     * @brief Customer::setCity Replace the current city of the customer company
     *  by the new <i>city</i>
     * @param city New city of the customer company
     */
    void setCity(const QString &city);

    /**
     * @brief Customer::getCountry Return the country of the customer company
     * @return country of the customer company
     */
    QString getCountry() const;
    /**
     * @brief Customer::setCountry Replace the country of the Customer company
     *  by <i>country</i>
     * @param country New country of the customer company
     */
    void setCountry(const QString &country);

    /**
     * @brief Customer::getEmail Return the email of the customer company
     * @return email of the customer company
     */
    QString getEmail() const;
    /**
     * @brief Customer::setEmail Replace the email of the Customer company by
     * <i>email</i>
     * @param email New email of the customer company
     */
    void setEmail(const QString &email);

    /**
     * @brief Customer::getMobilePhone Return the number of the mobile phone of
     * the customer company
     * @return number of mobile phone
     */
    QString getMobilePhone() const;
    /**
     * @brief Customer::setMobilePhone Replace the current mobile phone of the
     * customer company by <i>mobilePhone</i>
     * @param mobilePhone New number of mobile phone
     */
    void setMobilePhone(const QString &mobilePhone);

    /**
     * @brief Customer::getPhone Return the number of desktop phone
     * @return number of desktop phone
     */
    QString getPhone() const;
    /**
     * @brief Customer::setPhone Replace the current number of desktop phone by
     *  <i>phone</i>
     * @param phone New number of desktop phone
     */
    void setPhone(const QString &phone);

    /**
     * @brief Customer::getFax Return the fax number
     * @return fax number
     */
    QString getFax() const;
    /**
     * @brief Customer::setFax Replace the current fax number by <i>fax</i>
     * @param fax new fax number
     */
    void setFax(const QString &fax);

    /**
     * @brief Customer::getPath Return the path of the workspace for the current
     *  Customer
     * @return workspace path
     */
    QString getPath() const;

    /**
     * @brief Customer::getNameFolder Return the name of the current Customer's
     * folder in the workspace
     * @return name of the Customer's folder
     */
    QString getNameFolder() const;

    /**
     * @brief Customer::operator == Re-define the operator "==" to compare if
     * the current customer is the same to the other <b>Customer</b> <i>c</i>
     * Return TRUE if both customers are the same, else FALSE
     * @param c Customer to compare
     * @return boolean
     */
    bool operator ==(const Customer &c);
    /**
     * @brief Customer::operator == Re-define the operator "!=" to compare if
     * the current customer is differnt to the other <b>Customer</b> <i>c</i>
     * Return TRUE if both customers are different, else FALSE
     * @param c Customer to compare
     * @return boolean
     */
    bool operator !=(const Customer &c);


private:
    QString _firstnameReferent; //!< Firstname of the referent customer
    QString _lastnameReferent;  //!< Lastname of the referent customer
    QString _company;           //!< Company name of the customer
    QString _address;           //!< Company address (Name and number of street)
                                //!< of the Customer
    QString _postalCode;        //!< Postal code of the company
    QString _city;              //!< City of the company
    QString _country;           //!< Country of the company
    QString _email;             //!< Email of the customer
    QString _mobilePhone;       //!< Mobile phone number of the customer
    QString _phone;             //!< Phone number of the customer
    QString _fax;               //!< Fax number of the customer
};
}
#endif // CUSTOMER_H
