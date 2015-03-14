#ifndef CHECKCOUNTRY_H
#define CHECKCOUNTRY_H

#include "checkfieldsletters.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {
/**
 * @brief CheckCountry::CheckCountry Line Edit of country with a check icon
 */
class CheckCountry : public CheckFieldsLetters
{
public:
    /**
     * @brief CheckCountry::CheckCountry Construct a CheckCountry
     * @param w QWidget linked to <b>CheckCountry</b>
     */
    CheckCountry (QWidget* w = 0, QPushButton* btn = 0);


};
}
}
}
#endif // CHECKCOUNTRY_H
