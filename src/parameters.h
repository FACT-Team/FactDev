#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>

class Parameters
{
public:
    /**
     * @brief Parameters Construct a new parameters
     */
    Parameters();

    /**
     * @brief DB_FILENAME The database sqlite file name
     */
    static const QString DB_FILENAME;   //!< Database file name

    /**
     * @brief VERSION Version number of software
     */
    static const double VERSION;        //!< Application version
};

#endif // SETTINGS_H
