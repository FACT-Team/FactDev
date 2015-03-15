#ifndef ACCESSDATABASE_H
#define ACCESSDATABASE_H

#include <QString>
#include <QSettings>

namespace Databases {
class AccessDatabase
{
public:
    AccessDatabase();

    static void commit();

    static QString _address;
    static int _port;
    static QString _userDb;
    static QString _password;
    static QString _dbName;

    static bool _exists;

};
}
#endif // ACCESSDATABASE_H
