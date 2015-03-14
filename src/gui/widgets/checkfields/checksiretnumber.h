#ifndef CHECKSIRETNUMBER_H
#define CHECKSIRETNUMBER_H

#include "checkqlineedit.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {
/**
 * @brief The CheckSiretNumber class Line Edit with a check icon
 */
class CheckSiretNumber : public CheckQLineEdit
{
public:
    /**
     * @brief CheckSiretNumber::CheckSiretNumber Construct a CheckSiretNumber
     * @param w QWidget linked to <b>CheckSiretNumber</b>
     */
    CheckSiretNumber(QWidget* w = 0, QPushButton* btn = 0);

    /**
     * @brief CheckSiretNumber::check Check if the field noSiret is valid.
     * To be valid, a SIRET number should be composed of numbers
     * @param text Text to check
     * @return boolean Validy of the text
     */
    bool check(QString text);
};
}
}
}
#endif // CHECKSIRETNUMBER_H
