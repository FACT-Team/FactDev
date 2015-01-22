#ifndef CHECKCOUNTRY_H
#define CHECKCOUNTRY_H
#include "checkqlineedit.h"
/**
 * @brief CheckCountry::CheckCountry Line Edit of country with a check icon
 */
class CheckCountry : public CheckQLineEdit
{
public:
    /**
     * @brief CheckEmail::CheckCountry Construct a CheckCountry
     * @param w QWidget linked to <b>CheckCountry</b>
     */
    CheckCountry(QWidget *w);

    /**
     * @brief CheckCountry::check Check if the field email is valid.
     * To be valid, a country is composed of letters
     * @param text
     * @return boolean
     */
    bool check(QString text);
};

#endif // CHECKCOUNTRY_H
