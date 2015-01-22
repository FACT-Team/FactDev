#ifndef CHECKEMAIL_H
#define CHECKEMAIL_H
#include "checkqlineedit.h"

/**
 * @brief The CheckEmail class
 */
class CheckEmail : public CheckQLineEdit
{
public:
    /**
     * @brief CheckEmail::CheckEmail Construct a CheckMail
     * @param w QWidget linked to <b>CheckEmail</b>
     */
    CheckEmail(QWidget* w = 0);

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
     * @param text
     * @return
     */
    bool check(QString text);
};

#endif // CHECKEMAIL_H
