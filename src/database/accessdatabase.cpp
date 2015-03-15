#include "accessdatabase.h"

namespace Databases {
QString AccessDatabase::_address;
QString AccessDatabase::_dbName;
QString AccessDatabase::_userDb;
QString AccessDatabase::_password;
int AccessDatabase::_port;
bool AccessDatabase::_exists;


AccessDatabase::AccessDatabase()
{
    QSettings settings("FACT Team", "FactDev");
    if(!settings.value("externalDbExists", false).toBool()) {
        _exists = false;
    } else {
        _address = settings.value("address").toString();
        _port = settings.value("port").toInt();
        _userDb = settings.value("userDb").toString();
        _password = settings.value("password").toString();
        _dbName = settings.value("dbName").toString();
    }
}

void AccessDatabase::commit()
{
    QSettings settings("FACT Team", "FactDev");
    settings.setValue("externalDbExists", _exists);
    settings.setValue("address", _address);
    settings.setValue("port", _port);
    settings.setValue("userDb", _userDb);
    settings.setValue("password", _password);
    settings.setValue("dbName", _dbName);

}

}





