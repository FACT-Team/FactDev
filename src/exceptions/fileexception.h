#ifndef FILEEXCEPTION_H
#define FILEEXCEPTION_H
#include <exception>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include <QMessageBox>

#include "utils/log.h"

namespace Exceptions {
/**
 * @author Florent Berbie
 * @brief The FileException class for file/acess file exception
 */
class FileException
{
public:
    /**
     * @brief FileException::FileException. Construct a FileException.
     * @param userError ClassName of error
     * @param fctName Function name
     * @param logError Message error
     * @param errorCode Code of error
     */
    FileException(const QString userError, const QString fctName,
                  const QString logError, float errorCode);
    ~FileException();

    /**
     * @brief FileException::popupMessage. Display a popup message with the
     * message error.
     * @param parent
     */
    void popupMessage(QWidget *parent);
private:

    QString _userError; //!< user error
    int _errorCode;     //!<  Error code
};
}
#endif // FILEEXCEPTION_H
