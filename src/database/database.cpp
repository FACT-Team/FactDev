#include "database/database.h"
#include "log.h"

#include <QStandardItem>
#include <QDate>
#include <QDebug>
#include <QCoreApplication>
#include <QFile>

#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>

#include "parameters.h"

// SINGLETON
Database* Database::_instance = 0;
bool Database::_dbInstance = 0;
bool Database::isOpen = false;


/**
 * @brief Database::getInstance Return an instance of Database
 * @return Instance of Database
 */
Database* Database::instance() throw(DbException*) {
    if (_instance==0) {
        _instance = new Database();
    }

    _instance->setDatabase(QSqlDatabase::database());
    return _instance;
}

/**
 * @brief Database::setDatabase Set database
 * @param sql The new database
 */
void Database::setDatabase(QSqlDatabase sql) {
    mDatabase = sql;
}

/**
 * @brief Database::close Close database access
 */
void Database::close() {
    mDatabase.close();
}

/**
 * @brief Database::Database Database is a singleton
 */
Database::Database() throw(DbException*) {
    if(!isOpen) {
        mDatabase = QSqlDatabase::addDatabase("QSQLITE");
        open();
        isOpen = true;
    }
}

/**
 * @brief Database::~Database Suppression object, and close database access
 */
Database::~Database() {
    mDatabase.close();
    _instance = 0;
    _dbInstance = 0;

    delete _instance;
}

/**
 * @brief Database::open Open database
 */
void Database::open() {
    mDatabase = QSqlDatabase::database();
    bool creerStructure = false;

    _settings = new QSettings("FACT", "FactDev");
//    qDebug() << _settings->value("dbPath").toString();

//    if(_settings->value("dbPath").toString() == "") {
        _settings->setValue("dbPath", QCoreApplication::applicationDirPath());
//    }
    if(!QFile::exists(
       _settings->value("dbPath").toString()+"/"+Parameters::DB_FILENAME))
    {
        creerStructure = true;
        _settings->setValue("version", 0);
    }
    Database::mDatabase.setDatabaseName(
        _settings->value("dbPath").toString()+"/"+Parameters::DB_FILENAME);

    if(!Database::mDatabase.open()) {
        mDatabase.close();
        mDatabase = QSqlDatabase::database();
        Database::mDatabase.setDatabaseName(
            _settings->value("dbPath").toString()+"/"+Parameters::DB_FILENAME);

        if(!Database::mDatabase.open()) {
            throw new DbException(
                "Impossible d'ouvrir la base de données",
                "Database::Database",
                "Impossible d'ouvrir la base de données",
                22.1);
            exit(22);
        }
    }

    QSqlQuery query;
   // query.exec("PRAGMA foreign_keys = ON;");
    query.exec("PRAGMA auto_vacuum=FULL");
    query.exec("PRAGMA synchronous=OFF");
    query.exec("PRAGMA journal_mode=MEMORY");
    query.exec("PRAGMA default_cache_size=10000");
    query.exec("PRAGMA locking_mode=EXCLUSIVE");
    if(creerStructure) {
        createDatabase();

        #ifndef QT_NO_DEBUG
            jeuDEssai();
        #endif
    }
}

/**
 * @brief Database::jeuDEssai Create
 */
inline void Database::jeuDEssai() {
    executeFile(QCoreApplication::applicationDirPath()+"/sql/tests.sql");
}

/**
 * @brief Database::viderDatabase Clear database
 */
inline void Database::cleanDatabase() {
    executeFile(QCoreApplication::applicationDirPath()+"/sql/cleardatabase.sql");
}

/**
 * @brief Database::creerDatabase Create a new database
 */
inline void Database::createDatabase() {
    executeFile(QCoreApplication::applicationDirPath()+"/sql/createtables.sql");
}

/**
 * @brief Database::executerFichier Exeute a specified file
 * @param pNom File name
 */
void Database::executeFile(QString pNom) {
    QSqlQuery q;

    Log::instance() << "Execution de " + pNom;

    QFile file(pNom);
    file.open(QIODevice::ReadOnly);

    QStringList querys = QString(file.readAll()).split(";", QString::SkipEmptyParts);
    QStringListIterator i(querys);
    while(i.hasNext()) {
        QString query = i.next();
        // Check if query is not empty
        if(query.contains(QRegExp("[a-zA-Z]"))) {
            q.prepare(query);

            if(!q.exec()) {
                Log::instance(WARNING) << lastError(q);
            }
        }
    }
    file.close();
}

/**
 * @brief Database::openTransaction Open new transaction
 */
void Database::openTransaction()
{
    QSqlQuery q;

    q.prepare("BEGIN TRANSACTION");
    if(!q.exec()) {
        Log::instance(WARNING) << "Erreur d'ouverture de la transaction";
        Log::instance(WARNING) << lastError(q);

        throw std::exception();
    }
}

/**
 * @brief Database::closeTransaction Close current transaction
 */
void Database::closeTransaction()
{
    QSqlQuery q;

    q.prepare("END TRANSACTION");

    if(!q.exec()) {
        Log::instance(WARNING) << "Erreur de fermeture de la transaction";
        Log::instance(WARNING) << lastError(q);
    }

}

/**
 * @brief Database::derniereErreur Return text of last error
 * @param q Query
 * @return error message
 */
inline QString Database::lastError(const QSqlQuery& q) {
    QString ret = "[ ERREUR  ] " + q.lastError().text()+"\n"
                +"[ query ] " + q.lastQuery() +"\n";

    return ret;
}

/**
 * @brief Database::valeur Value of database field
 * @param q Query
 * @param champ Field
 * @return  The value
 */
QVariant Database::value(const QSqlQuery& q, const QString& champ) {
    return q.value(champ);
}

