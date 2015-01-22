#ifndef ICHECKFIELD_H
#define ICHECKFIELD_H
#include <QString>

class ICheckField {

public:
    virtual bool check(QString) = 0;

};

#endif // ICHECKFIELD_H
