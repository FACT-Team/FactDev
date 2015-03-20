#ifndef CHECKIPADDRESS_H
#define CHECKIPADDRESS_H

#include "gui/widgets/checkfields/checkuntilfield.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {

/**
 * @author Florent BERBIE
 * @brief The CheckIpAddress class Line Edit of IP address with a check icon
 * @see CheckQLineEdit
 * @see CheckUntilField
 */
class CheckIpAddress : public CheckUntilField
{
public:
    /**
     * @brief CheckIpAddress::CheckIpAddress Construct a CheckIpAddress
     * @param w QWidget linked to <b>CheckIpAddress</b>
     */
    CheckIpAddress(QWidget* w = 0, QPushButton* btn=0);

    /**
     * @brief CheckIpAddress::check Check if the field contains an IP address
     * or domain name valid
     * @param text Text to check
     * @return boolean Validity of the text
     */
    bool check(QString text);
};

}
}
}
#endif // CHECKIPADDRESS_H
