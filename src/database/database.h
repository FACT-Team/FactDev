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
    /**
     * @brief Database::getInstance Return an instance of Database
     * @return Instance of Database
     */
    static Database* instance() throw(DbException*);

    /**
     * @brief Database::lastError Return an error message on the last error
     * occured during the SQL request 'i'
     * @param q SQL request
     * @return an error message
     */
    QString  lastError(const QSqlQuery& q);

    /**
     * @brief Database::jeuDEssai Create
     */
    void jeuDEssai();

    /**
     * @brief Database::viderDatabase Clear database
     */
    void cleanDatabase();

    /**
     * @brief Database::executerFichier Exeute a specified file
     * @param pNom File name
     */
    void executeFile(QString pNom);

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
     * @brief Database::creerDatabase Create a new database
     */
    void createDatabase();
protected:
    /**
     * @brief Database::Database Database is a singleton
     */
    Database()throw(DbException*);

    static Database* _instance;
    static bool _dbInstance;

    QSettings* _settings;

    QSqlDatabase mDatabase;
    QList<Database*> _instances;

    static bool isOpen;

    /**
     * @brief Database::valeur Value of database field
     * @param q Query
     * @param champ Field
     * @return  The value
     */
    QVariant value(const QSqlQuery& q, const QString& champ);


};

#endif // Database_H
