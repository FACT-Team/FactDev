#include "accessdatabase.h"

namespace Databases {
QString AccessDatabase::_address;
QString AccessDatabase::_dbName;
QString AccessDatabase::_userDb;
QString AccessDatabase::_password;
int AccessDatabase::_port;
bool AccessDatabase::_exists;
DbType AccessDatabase::_dbType;


AccessDatabase::AccessDatabase()
{
    init();
}

void AccessDatabase::init()
{
    QString environment;
#if QT_NO_DEBUG
    environment = "release";
#else
    environment = "debug";
#endif

    QSettings settings("FACT Team", "FactDev-"+environment);

    if(!settings.value("externalDbExists", false).toBool()) {
        _exists = false;
    } else {
        _address = settings.value("address").toString();
        _port = settings.value("port").toInt();
        _userDb = settings.value("userDb").toString();
        _password = settings.value("password").toString();
        _dbName = settings.value("dbName").toString();
        _exists = true;
        _dbType = (DbType)settings.value("dbType").toInt();
    }
}

void AccessDatabase::commit()
{
    QString environment;

#if QT_NO_DEBUG
    environment = "release";
#else
    environment = "debug";
#endif

    QSettings settings("FACT Team", "FactDev-"+environment);
    settings.setValue("externalDbExists", _exists);
    settings.setValue("address", _address);
    settings.setValue("port", _port);
    settings.setValue("userDb", _userDb);
    settings.setValue("password", _password);
    settings.setValue("dbName", _dbName);
    settings.setValue("dbType", _dbType);

}

}





