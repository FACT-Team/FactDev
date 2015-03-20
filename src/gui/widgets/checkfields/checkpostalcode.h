#ifndef CHECKPOSTALCODE_H
#define CHECKPOSTALCODE_H

#include "checkuntilfield.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {
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
     * @param text Text to check
     * @return boolean Validity of the text
     */
    bool check(QString text);

    /**
     * @brief CheckPostalCode::getCountry Return the country linked to current
     * field
     * @return country Country of the field
     */
    QString getCountry() const;
    /**
     * @brief CheckPostalCode::setCountry Modify the <i>country</i> linked to
     * field
     * @param country New country
     */
    void setCountry(const QString &country);

private :
    QString _country;   //!< Country of the field
};
}
}
}
#endif // CHECKPOSTALCODE_H
