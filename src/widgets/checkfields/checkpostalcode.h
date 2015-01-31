#ifndef CHECKPOSTALCODE_H
#define CHECKPOSTALCODE_H
#include "checkuntilfield.h"

/**
 * @brief The CheckPostalCode class Line Edit of postal code with a check icon
 */
class CheckPostalCode : public CheckUntilField
{
public:
    /**
     * @brief CheckPostalCode::CheckPostalCode Construct a CheckPostalCode
     * @param w QWidget linked to <b>CheckPostalCode</b>
     */
    CheckPostalCode (QWidget* w = 0, QPushButton* btn = 0);

};

#endif // CHECKPOSTALCODE_H
