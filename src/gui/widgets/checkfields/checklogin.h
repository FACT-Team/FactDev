#ifndef CHECKLOGIN_H
#define CHECKLOGIN_H
#include "gui/widgets/checkfields/checkuntilfield.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {

/**
 * @author Florent BERBIE
 * @brief The CheckLogin class Line Edit of login with a check icon
 * @see CheckQLineEdit
 * @see CheckUntilField
 */
class CheckLogin : public CheckUntilField
{
public:
    /**
     * @brief CheckLogin::CheckLogin Construct a CheckLogin
     * @param w QWidget linked to <b>CheckIpAddress</b>
     */
    CheckLogin(QWidget* w = 0, QPushButton* btn=0);
    /**
     * @brief CheckLogin::check Check if the field contains only numbers
     * @param text Text to check
     * @return boolean Validity of the text
     */
    bool check(QString text);

public slots:
    /**
     * @brief CheckLogin::fieldTextChanged For each new characater inputed
     * or removed, displays an icon to show if the field is valid or not
     */
    void passwordPreviousInputed(const QString &text);

private :
    QString _login; //!< User login
};

}
}
}

#endif // CHECKLOGIN_H
