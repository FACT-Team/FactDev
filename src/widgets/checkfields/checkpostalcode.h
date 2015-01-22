#ifndef CHECKPOSTALCODE_H
#define CHECKPOSTALCODE_H
#include "checkqlineedit.h"

/**
 * @brief The CheckPostalCode class Line Edit of postal code with a check icon
 */
class CheckPostalCode : public CheckQLineEdit
{
public:
    /**
     * @brief CheckPostalCode::CheckPostalCode Construct a CheckPostalCode
     * @param w QWidget linked to <b>CheckPostalCode</b>
     */
    CheckPostalCode(QWidget *w);

    /**
     * @brief CheckPostalCode::check Check if the field postal code is valid.
     * To be valid, a postal code is composed of five numbers
     * @param text
     * @return boolean
     */
    bool check(QString text);
};

#endif // CHECKPOSTALCODE_H
