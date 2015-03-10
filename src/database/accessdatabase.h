#ifndef ACCESSDATABASE_H
#define ACCESSDATABASE_H

#include <QString>
#include <QSettings>

class AccessDatabase
{
public:
    AccessDatabase();

    void commit();

    QString getAddress() const;
    void setAddress(const QString &getAddress);

    int getPort() const;
    void setPort(int getPort);

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
    int _port;
    QString _userDb;
    QString _password;
    QString _dbName;

    bool _exists;

};

#endif // ACCESSDATABASE_H
