#ifndef CHECKPORTNUMBER_H
#define CHECKPORTNUMBER_H

#include "gui/widgets/checkfields/checkqlineedit.h"
#include "gui/widgets/checkfields/icheckfield.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {

/**
 * @author Florent BERBIE
 * @brief The CheckFieldsNumbers class Line Edit of number with a check icon
 * @see CheckQLineEdit
 * @see CheckUntilField
 */
class CheckPortNumber : public CheckQLineEdit
{
public:
    /**
     * @brief CheckPortNumber
     * @param w
     * @param btn
     */
    CheckPortNumber(QWidget* w = 0, QPushButton* btn=0);

    /**
     * @brief CheckPortNumber::check Check if the field contains only numbers or
     * an empty text
     * @param text
     * @return boolean
     */
    bool check(QString text);
};
}
}
}
#endif // CHECKPORTNUMBER_H
