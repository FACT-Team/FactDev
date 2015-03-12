#ifndef CHECKVALIDFIELD_H
#define CHECKVALIDFIELD_H

#include "checkqlineedit.h"

namespace Gui {
namespace Widgets {
namespace CheckFields {
/**
 * @brief The CheckValidField class Check field not required
 */
class CheckValidField : public CheckQLineEdit {
public:
    /**
     * @brief CheckValidField::CheckValidField
     * @param w QWidget linked to <b>CheckValidField</b>
     */
    CheckValidField(QWidget* w = 0, QPushButton* btn = 0) ;

    /**
     * @brief CheckValidField::check Return TRUE : the field is not required
     * @param text Text to check
     * @return boolean Validity of the text
     */
    bool check(QString text);
};
}
}
}
#endif // CHECKVALIDFIELD_H
