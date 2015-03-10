#ifndef ACCESSDATABASE_H
#define ACCESSDATABASE_H

#include <QString>
#include <QSettings>

namespace Databases {
class AccessDatabase
{
public:
    AccessDatabase();

    void commit();

    QString getAddress() const;
    void setAddress(const QString &getAddress);

    QString getPort() const;
    void setPort(QString getPort);

    QString getUserDb() const;
    void setUserDb(const QString &getUserDb);

    QString getPassword() const;
    void setPassword(const QString &getPassword);

    QString getDbName() const;
    void setDbName(const QString &getDbName);

    bool exists() const;
    void setExists(bool exists);

private:
    QString _address;
    QString _port;
    QString _userDb;
    QString _password;
    QString _dbName;

    bool _exists;

};
}
#endif // ACCESSDATABASE_H
