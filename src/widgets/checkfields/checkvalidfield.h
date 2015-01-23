#ifndef CHECKVALIDFIELD_H
#define CHECKVALIDFIELD_H
#include "checkqlineedit.h"

/**
 * @brief The CheckValidField class Check field not required
 */
class CheckValidField : public CheckQLineEdit {
public:
    /**
     * @brief CheckValidField::CheckValidField
     * @param w QWidget linked to <b>CheckValidField</b>
     */
    CheckValidField(QWidget* w);

    /**
     * @brief CheckValidField::check Return TRUE : the field is not required
     * @param text
     * @return boolean
     */
    bool check(QString text);
};

#endif // CHECKVALIDFIELD_H
