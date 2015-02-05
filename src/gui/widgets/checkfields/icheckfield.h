#ifndef ICHECKFIELD_H
#define ICHECKFIELD_H

#include <QString>

/**
 * @brief The ICheckField class Interface to check fields validity
 */
class ICheckField {

public:
    /**
     * @brief check Check if the field (line edit) is valid
     * Return TRUE if the field is valid, else FALSE
     * @return boolean
     */
    virtual bool check(QString text) = 0;

};

#endif // ICHECKFIELD_H
