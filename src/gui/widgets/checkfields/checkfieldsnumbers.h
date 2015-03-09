#ifndef CHECKFIELDSNUMBERS_H
#define CHECKFIELDSNUMBERS_H

#include "gui/widgets/checkfields/checkuntilfield.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {

/**
 * @author Florent BERBIE
 * @brief The CheckFieldsNumbers class Line Edit of number with a check icon
 * @see CheckQLineEdit
 * @see CheckUntilField
 */
class CheckFieldsNumbers : public CheckUntilField
{
public:
    /**
     * @brief CheckFieldsNumbers::CheckFieldsNumbers Construct a
     * CheckFieldsNumbers
     * @param w QWidget linked to <b>CheckFieldsNumbers</b>
     */
    CheckFieldsNumbers(QWidget* w = 0, QPushButton* btn=0);

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
#endif // CHECKFIELDSNUMBERS_H
