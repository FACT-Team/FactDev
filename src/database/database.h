#ifndef Database_H
#define Database_H

#include <QtSql/QSql>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>

#include <QStandardItemModel>
#include <QSettings>
#include <QStandardItem>
#include <QDate>
#include <QCoreApplication>
#include <QFile>

#include <exception>

#include "exceptions/dbexception.h"
#include "utils/log.h"
#include "parameters.h"
#include "database/accessdatabase.h"

using namespace Exceptions;
using namespace Utils;

/**
 * @brief Class for Database, contains queries
 */
namespace Databases {
enum DbType {SQLITE, MYSQL};
/**
 * @author Antoine de Roquemaurel
 * @brief The <b>Database</b> class Master class for all database access
 */
class Database {
public:
    /**
     * @brief Database::getInstance Return an instance of Database
     * @return Instance of Database
     */
    static Database* instance() throw(DbException*);

    /**
     * @brief Database::lastError Return an error message on the last error
     * occured during the SQL request <i>q</i>
     * @param q SQL request
     * @return an error message
     */
    QString  lastError(const QSqlQuery& q) const;

    /**
     * @brief Database::testCases Realise a test cases
     */
    void testCases();

    /**
     * @brief Database::executerFichier Exeute a specified file named
     * <i>pName</i>
     * @param pNom File name
     */
    void executeFile(QString pName);

    /**
     * @brief Database::openTransaction Open new transaction
     */
    void openTransaction();

    /**
     * @brief Database::closeTransaction Close current transaction
     */
    void closeTransaction();

    /**
     * @brief Database::close Close database access
     */
    void close();

    /**
     * @brief Database::open Open database
     */
    void open();

    /**
     * @brief Database::~Database Suppression object, and close database access
     */
    ~Database();

    /**
     * @brief Database::setDatabase Set database
     * @param sql The new database
     */
    void setDatabase(QSqlDatabase sql);

    /**
     * @brief Database::updateBillingNumber Update the billing number
     */
    void updateBillingNumber();

    /**
     * @brief Database::clearDatabase Drop alls tables of Database
     * WARNING: We can't restore data after.
     */
    void cleanDatabase();

    /**
     * @brief changeDatabase Change the current database : mysql to sqlite or sqlite to mysql
     * @param dbType : The new database type, Sqlite or Mysql
     */
    void changeDatabase(DbType dbType);
protected:
    /**
     * @brief Database::Database Database is a singleton
     */
    Database()throw(DbException*);

    static Database* _instance; //!< Instance
    static bool _dbInstance; //!< an instance of db is open

    QSettings* _settings; //!< settings

    QSqlDatabase mDatabase; //!< contains Database
    QList<Database*> _instances; //!< List of instances

    static bool isOpen; //!< Database is open

    /**
     * @brief Database::valeur Value of database field
     * @param q Query
     * @param champ Field
     * @return  The value
     */
    QVariant value(const QSqlQuery& q, const QString& champ) const;

    static bool _isMysql;

};

}
#endif // Database_H
