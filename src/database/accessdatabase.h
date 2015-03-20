#ifndef ACCESSDATABASE_H
#define ACCESSDATABASE_H

#include <QString>
#include <QSettings>
#include <QDebug>

namespace Databases {
enum DbType {SQLITE, MYSQL};

class AccessDatabase
{
public:
    AccessDatabase();
    static void init();
    static void commit();

    static QString _address;
    static int _port;
    static QString _userDb;
    static QString _password;
    static QString _dbName;
    static Databases::DbType _dbType;

    static bool _exists;

};
}
#endif // ACCESSDATABASE_H
