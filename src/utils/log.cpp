#include "log.h"

namespace Utils {
const int LOG_QDEBUG_LEVEL = 2;
Log* Log::_instance = 0;
TypeLog Log::_type = INFO;

Log::Log() {

    _file = new QFile(
                QCoreApplication::applicationDirPath()+"/"+"/message.log");
    bool exists = _file->exists();
    _file->open(QIODevice::Append | QIODevice::Text);
    if(!exists) {
        *this << "Création du fichier de log";
    }
}

Log& Log::instance(TypeLog type) {
    if (_instance == 0) {
        _instance = new Log();
    }

    _type = type;
    return *_instance;
}

inline QString Log::typeLog2String(TypeLog type) {
    QStringList list;
    list << "INFO"<<"ERROR"<<"WARNING";

    return list.at((int)type);
}

void Log::write(const QString text) {
    QTextStream out(_file);
    QString ret = head() + text + "\n";
    out << ret;
    if(LOG_QDEBUG_LEVEL < 2) {
        qDebug() << ret;
    }
}

inline QString Log::head() {
    return  "["+QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss")
            +" V"+QString::number(Parameters::VERSION)
            +" "+typeLog2String(_type)+"] ";
}
}
