#ifndef CHECKCUNTILFIELD_H
#define CHECKCUNTILFIELD_H

#include "checkqlineedit.h"

/**
 * @brief The CheckUntilField class
 */
class CheckUntilField : public CheckQLineEdit {

public:
    /**
     * @brief CheckUntilField::CheckUntilField Construct a CheckUntilField
     * @param w QWidget linked to <b>CheckUntilField</b>
     */
    CheckUntilField(QWidget* w = 0, QPushButton* btn = 0);

    /**
     * @brief CheckUntilField::check Check if the field  is valid.
     * To be valid, a name should be composed of a character
     * @param text
     * @return boolean
     */
    bool check (QString text);
};

#endif // CHECKUNTILFIELD_H
