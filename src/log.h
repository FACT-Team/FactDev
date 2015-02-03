#ifndef LOG_H
#define LOG_H
#include <QFile>
#include <QDate>
#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QSettings>
#include <QString>

#include "parameters.h"

/**
 * @brief Enum for log : INFO, ERREUR, WARNING
*/
typedef enum {INFO, ERROR, WARNING } TypeLog;

/**
 * @brief The Log class for Simple management of log.
 */
class Log
{
public:
    /**
     * @brief Log::instance. Return the instance of logger.
     * @param type Type of log : WARNING, INFO, ERROR
     * @return Instance of logger.
     */
    static Log &instance(TypeLog type=INFO);

    /**
     * @brief Log::~Log
     */
    ~Log();

    /**
     * @brief Log::write. Write log message in file
     * @param text
     */
    void write(const QString text);

    /**
     * @brief Log::Log. Log is a singleton.
     */
    Log();

    /**
     * @brief operator << for log writing
     * @param logger Instance of Logger
     * @param text Text to write
     * @return New logger.
     */
    friend Log &operator << (Log &logger, const QString& text) {
        logger.write(text);

        return logger;
    }
private:
    static Log* _instance;  //!< Log instance
    static TypeLog _type;   //!< Type of log, WARNING, ERROR, INFO

    QFile* _file;

    /**
     * @brief Log::head. Head of log instruction
     * @return The head instruction : date Version logType
     */
    QString head();

    /**
     * @brief Log::typeLog2String. Display keyword in function of TypeLog
     * @param type The type : INFO? ERROR, WARNING
     * @return String KeyWord
     */
    QString typeLog2String(TypeLog type);
};

#endif // LOG_H
