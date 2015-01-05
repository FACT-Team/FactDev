#ifndef Database_H
#define Database_H

#include <exception>
#include <QtSql/QSql>
#include <QtSql/QSqlQuery>
#include <QStandardItemModel>
#include <QSettings>


#include "exceptions/dbexception.h"

/**
 * @brief The Database class Master class for all database access
 */
class Database {
public:
    static Database* instance() throw(DbException*);
    QString  lastError(const QSqlQuery& q);
    void jeuDEssai();
    void cleanDatabase();
    void executeFile(QString pNom);
    void openTransaction();
    void closeTransaction();

    void close();
    void open();
    ~Database();
    void setDatabase(QSqlDatabase sql);

protected:
    Database()throw(DbException*);
    static Database* _instance;
    static bool _dbInstance;
    QVariant value(const QSqlQuery& q, const QString& champ);
    QSettings* _settings;

    QSqlDatabase mDatabase;
    QList<Database*> _instances;

    static bool isOpen;


private:
    void creerDatabase();


};

#endif // Database_H
