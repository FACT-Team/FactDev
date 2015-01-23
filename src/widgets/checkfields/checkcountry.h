#ifndef CHECKCOUNTRY_H
#define CHECKCOUNTRY_H
#include "checkfieldsletters.h"
/**
 * @brief CheckCountry::CheckCountry Line Edit of country with a check icon
 */
class CheckCountry : public CheckFieldsLetters
{
public:
    /**
     * @brief CheckEmail::CheckCountry Construct a CheckCountry
     * @param w QWidget linked to <b>CheckCountry</b>
     */
    CheckCountry (QWidget* w = 0, QPushButton* btn = 0);

    /**
     * @brief CheckCountry::check Check if the field email is valid.
     * To be valid, a country is composed of letters
     * @param text
     * @return boolean
     */
//    bool check(QString text);
};

#endif // CHECKCOUNTRY_H
