#ifndef CHECKFIELDSLETTERS_H
#define CHECKFIELDSLETTERS_H

#include "checkuntilfield.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {
/**
 * @brief The CheckFieldsLetters class Field with only letters (no numbers)
 */
class CheckFieldsLetters : public CheckUntilField {
public:
    /**
     * @brief CheckFieldsLetters::CheckFieldsLetters Construct a
     *  CheckFieldsLetters
     * @param w QWidget linked to <b>CheckFieldsLetters</b>
     */
    CheckFieldsLetters(QWidget* w = 0, QPushButton* btn=0);

    /**
     * @brief CheckName::check Check if the field contains only letters
     * @param text
     * @return boolean
     */
    bool check(QString text);
};
}
}
}
#endif // CHECKFIELDSLETTERS_H
