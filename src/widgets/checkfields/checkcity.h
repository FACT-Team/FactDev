#ifndef CHECKCITY_H
#define CHECKCITY_H
#include "checkuntilfield.h"

/**
 * @brief The CheckCity class Line Edit of City with a check icon
 */
class CheckCity : public CheckUntilField
{
public:
    /**
     * @brief CheckCity::CheckCity Construct a CheckCity
     * @param w QWidget linked to <b>CheckCity</b>
     */
    CheckCity(QWidget* w = 0);

    /**
     * @brief CheckCity::check Check if the field city is valid.
     * To be valid, a city should be composed only with letters
     * @param text
     * @return boolean
     */
    bool check(QString text);
};

#endif // CHECKCITY_H
