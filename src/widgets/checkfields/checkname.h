#ifndef CHECKNAME_H
#define CHECKNAME_H
#include "checkfieldsletters.h"

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

    /**
     * @brief CheckName::check Check if the field name (firstname or lastname)
     * is valid.
     * To be valid, a name should be composed only with letters
     * @param text
     * @return boolean
     */
//    bool check(QString text);
};

#endif // CHECKNAME_H
