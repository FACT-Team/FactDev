#ifndef CHECKNAME_H
#define CHECKNAME_H

#include "checkfieldsletters.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {
/**
 * @brief The CheckName class Line edit of name with a check icon
 */
class CheckName : public CheckFieldsLetters
{
public:
    /**
     * @brief CheckName::CheckName Construct a CheckName
     * @param w QWidget linked to <b>CheckName</b>
     */
    CheckName(QWidget* w = 0, QPushButton* btn=0);


};
}
}
}
#endif // CHECKNAME_H
