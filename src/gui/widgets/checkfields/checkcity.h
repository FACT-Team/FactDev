#ifndef CHECKCITY_H
#define CHECKCITY_H
#include "checkfieldsletters.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {
/**
 * @brief The CheckCity class Line Edit of City with a check icon
 */
class CheckCity : public CheckFieldsLetters
{
public:
    /**
     * @brief CheckCity::CheckCity Construct a CheckCity
     * @param w QWidget linked to <b>CheckCity</b>
     */
    CheckCity(QWidget* w = 0, QPushButton* btn=0);

};
}
}
}
#endif // CHECKCITY_H
