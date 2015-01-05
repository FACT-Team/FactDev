#include <QDate>
#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QSettings>
#include <QString>

#include "log.h"
#include "parameters.h"
Log* Log::_instance = 0;
TypeLog Log::_type = INFO;

/**
 * @brief Log::Log. Log is a singleton.
 */
Log::Log() {
    QSettings settings("BilanMDT", "Antoine de Roquemaurel");
    _file = new QFile(settings.value("workspace").toString()+"/"+"/message.log");
    bool exists = _file->exists();
    _file->open(QIODevice::Append | QIODevice::Text);
    if(!exists) {
        *this << "Création du fichier de log";
    }
}

/**
 * @brief Log::instance. Return the instance of logger.
 * @param type Type of log : WARNING, INFO, ERROR
 * @return Instance of logger.
 */
Log& Log::instance(TypeLog type) {
    if (_instance == 0) {
        _instance = new Log();
    }

    _type = type;
    return *_instance;
}

/**
 * @brief Log::~Log
 */
Log::~Log() {
    _file->close();
    delete _instance;
}

/**
 * @brief Log::typeLog2String. Display keyword in function of TypeLog
 * @param type The type : INFO? ERROR, WARNING
 * @return String KeyWord
 */
inline QString Log::typeLog2String(TypeLog type) {
    QStringList list;
    list << "INFO"<<"ERROR"<<"WARNING";

    return list.at((int)type);
}

/**
 * @brief Log::write. Write log message in file
 * @param text
 */
void Log::write(const QString text) {
    QTextStream out(_file);
    QString ret = head() + text + "\n";
    out << ret;
    qDebug() << ret;
}

/**
 * @brief Log::head. Head of log instruction
 * @return The head instruction : date Version logType
 */
inline QString Log::head() {
    return"["+QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss")+" V"+QString::number(Parameters::VERSION)+" "+typeLog2String(_type)+"] ";
}
