#ifndef CHECKPHONE_H
#define CHECKPHONE_H
#include "checkqlineedit.h"

/**
 * @brief The CheckPhone class Line Edit of Phone number with a check icon
 */
class CheckPhone : public CheckQLineEdit
{
public:
    /**
     * @brief CheckPhone::CheckPhone Construct a CheckPhone
     * @param w QWidget linked to <b>CheckPhone</b>
     */
    CheckPhone(QWidget* w = 0, QPushButton* btn=0);


    /**
     * @brief CheckPhone::check Check if the field phone is valid.
     * To be valid, a phone should be composed only with numbers
     * @param text
     * @return boolean
     */
    bool check(QString text);
};

#endif // CHECKPHONE_H
