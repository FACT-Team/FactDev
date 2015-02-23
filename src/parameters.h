#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>

/**
 * @author Antoine de Roquemaurel
 * @brief The Parameters class Class for simple user parameters
 */
class Parameters
{
public:
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
