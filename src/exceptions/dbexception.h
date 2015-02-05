#ifndef DbException_H
#define DbException_H

#include <exception>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include <QMessageBox>

#include "utils/log.h"

namespace Exceptions {
/**
 * @author Antoine de Roquemaurel
 * @brief The DbException class for database exception : queries, db file, …
 */
class DbException : public std::exception
{
public:
    /**
     * @brief DbException::DbException. Construct a DbException.
     * @param userError ClassName of error
     * @param fctName Function name
     * @param logError Message error
     * @param errorCode Code of error
     */
    DbException(const QString fct, const QString fctName,
        const QString logError, float errorCode );


    /**
     * @brief ~DbException
     */
    virtual ~DbException() throw()
    {

    }

    /**
     * @brief DbException::popupMessage. Display a popup message with the
     * message error.
     * @param parent
     */
    void popupMessage(QWidget *parent);
private:

    QString _userError; //!<

    int _errorCode; //!<  Error code
};
}

#endif // DbException_H
