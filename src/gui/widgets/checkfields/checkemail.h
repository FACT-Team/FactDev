#ifndef CHECKEMAIL_H
#define CHECKEMAIL_H

#include "checkqlineedit.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {

/**
 * @brief The CheckEmail class Line Edit of email with a check icon
 */
class CheckEmail : public CheckQLineEdit
{
public:
    /**
     * @brief CheckEmail::CheckEmail Construct a CheckMail
     * @param w QWidget linked to <b>CheckEmail</b>
     */
    CheckEmail(QWidget* w = 0, QPushButton* btn=0);

    /**
     * @brief CheckEmail::check Check if the field email is valid.
     * To be valid, an email address should be under this form: me@me.xx
     * An email address need:
     *     - 1 character [A-Z] or [a-z]  minimum before the character <i>@</i>
     *     - the character '@'
     *     - 1 character [A-Z] or [a-z]  after the character<i>@</i>minimum and
     *     before the character <i>.</i>
     *     - 1 character [A-Z] or [a-z]  minimum afer the character <i>.</i>
     * Return TRUE if email address is valid, else FALSE
     * @param text Text to check
     * @return boolean Validity of the text
     */
    bool check(const QString text);
};
}
}
}
#endif // CHECKEMAIL_H
