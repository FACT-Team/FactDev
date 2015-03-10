#include "accessdatabase.h"

AccessDatabase::AccessDatabase()
{
    QSettings settings("FACT Team", "FactDev");
    if(!settings.value("externalDbExists", false)) {
        _exists = false;
    } else {
        _address = settings.value("address");
        _port = settings.value("port");
        _userDb = settings.value("userDb");
        _password = settings.value("password");
        _dbName = settings.value("dbName");
    }
}

void AccessDatabase::commit()
{
    QSettings settings("FACT Team", "FactDev");
    settings.setValue("externalDbExists", true);
    settings.setValue("address", _address);
    settings.setValue("port", _port);
    settings.setValue("userDb", _userDb);
    settings.setValue("password", _password);
    settings.setValue("dbName", _dbName);

}
QString AccessDatabase::getAddress() const
{
    return _address;
}

void AccessDatabase::setAddress(const QString &address)
{
    _address = address;
}
int AccessDatabase::getPort() const
{
    return _port;
}

void AccessDatabase::setPort(int port)
{
    _port = port;
}
QString AccessDatabase::getUserDb() const
{
    return _userDb;
}

void AccessDatabase::setUserDb(const QString &user)
{
    _userDb = user;
}
QString AccessDatabase::getPassword() const
{
    return _password;
}

void AccessDatabase::setPassword(const QString &password)
{
    _password = password;
}
QString AccessDatabase::getDbName() const
{
    return _dbName;
}

void AccessDatabase::setDbName(const QString &dbName)
{
    _dbName = dbName;
}
bool AccessDatabase::exists() const
{
    return _exists;
}

void AccessDatabase::setExists(bool exists)
{
    _exists = exists;
}







