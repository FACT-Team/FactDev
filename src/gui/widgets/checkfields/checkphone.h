#ifndef CHECKPHONE_H
#define CHECKPHONE_H

#include "checkuntilfield.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {
/**
 * @brief The CheckPhone class Line Edit of Phone number with a check icon
 */
class CheckPhone : public CheckUntilField
{
public:
    /**
     * @brief CheckPhone::CheckPhone Construct a CheckPhone
     * @param w QWidget linked to <b>CheckPhone</b>
     */
    CheckPhone(QWidget* w = 0, QPushButton* btn=0);

    /**
     * @brief CheckPhone::check Check if the field  is valid.
     * To be valid, a name should be composed of a character
     * @param text
     * @return boolean
     */
    bool check(QString text);

    /**
     * @brief CheckPhone::getCountry Return the country linked to current field
     * @return
     */
    QString getCountry() const;
    /**
     * @brief CheckPhone::setCountry Modify the <i>country</i> linked to field
     * @param country New country
     */
    void setCountry(const QString &country);

private :
    QString _country;
};
}
}
}

#endif // CHECKPHONE_H
