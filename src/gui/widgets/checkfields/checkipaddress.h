#ifndef CHECKIPADDRESS_H
#define CHECKIPADDRESS_H

#include "gui/widgets/checkfields/checkuntilfield.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {

/**
 * @brief The CheckIpAddress class Line Edit of IP address with a check icon
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
     * @brief CheckFieldsNumbers::check Check if the field contains only numbers
     * @param text
     * @return boolean
     */
    bool check(QString text);
};

}
}
}
#endif // CHECKIPADDRESS_H
