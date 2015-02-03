#ifndef CHECKPOSTALCODE_H
#define CHECKPOSTALCODE_H

#include "checkuntilfield.h"

/**
 * @brief The CheckPostalCode class Line Edit of postal code with a check icon
 */
class CheckPostalCode : public CheckUntilField
{
public:
    /**
     * @brief CheckPostalCode::CheckPostalCode Construct a CheckPostalCode
     * @param w QWidget linked to <b>CheckPostalCode</b>
     */
    CheckPostalCode (QWidget* w = 0, QPushButton* btn = 0);

    /**
     * @brief CheckPostalCode::check Check if the field  is valid.
     * To be valid, a name should be composed of a character
     * @param text
     * @return boolean
     */
    bool check(QString text);

    /**
     * @brief CheckPostalCode::getCountry Return the country linked to current
     * field
     * @return country
     */
    QString getCountry() const;
    /**
     * @brief CheckPostalCode::setCountry Modify the <i>country</i> linked to
     * field
     * @param country New country
     */
    void setCountry(const QString &country);

private :
    QString _country;
};

#endif // CHECKPOSTALCODE_H
