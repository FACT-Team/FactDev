#ifndef CHECKWEBSITE_H
#define CHECKWEBSITE_H

#include "checkvalidfield.h"
namespace Gui {
namespace Widgets {
namespace CheckFields {

/**
 * @brief The CheckWebsite class Line Edit of website with a check icon
 * @see CheckQLineEdit
 * @see CheckUntilField
 * @see CheckIpAddress
 */
class CheckWebsite : public CheckValidField
{
public:
    /**
     * @brief CheckWebsite::CheckWebsite Construct a CheckWebsite
     * @param w QWidget linked to <b>CheckWebsite</b>
     */
    CheckWebsite(QWidget* w = 0, QPushButton* btn=0);

    /**
     * @brief CheckWebsite::check Check if the field contains an website address
     * @param text Text to check
     * @return boolean Validity of the text
     */
    bool check(QString text);
};
}
}
}
#endif // CHECKWEBSITE_H
