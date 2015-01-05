#ifndef DbException_H
#define DbException_H
#include <exception>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <QDebug>

/**
 * @brief The DbException class for database exception : queries, db file, …
 */
class DbException : public std::exception
{
public:
    DbException(const QString fct, const QString fctName, const QString logError, float errorCode );


    virtual ~DbException() throw()
    {

    }

    void popupMessage(QWidget *parent);
private:
    QString _userError;
    int _errorCode;
};


#endif // DbException_H
