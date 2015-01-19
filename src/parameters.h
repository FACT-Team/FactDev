#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>

class Parameters
{
public:
    Parameters();

    static const QString DB_FILENAME;   //!< Database file name
    static const double VERSION;        //!< Application version
};

#endif // SETTINGS_H
