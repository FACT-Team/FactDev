#include "database/database.h"

namespace Databases {
// SINGLETON
Database* Database::_instance = 0;
bool Database::_dbInstance = 0;
bool Database::isOpen = false;
bool Database::_isMysql = false;

Database* Database::instance(bool tests) {
    if (_instance==0) {
        _instance = new Database(tests);
    }

    _instance->setDatabase(QSqlDatabase::database());
    return _instance;
}

void Database::setDatabase(QSqlDatabase sql) {
    mDatabase = sql;
}

void Database::close() {
    mDatabase.close();
}

Database::Database(bool tests) {
    if(!isOpen) {
        if(!tests) {
            AccessDatabase::init();
        }

        if(AccessDatabase::_exists && AccessDatabase::_dbType == MYSQL) {
            _isMysql = true;
            mDatabase = QSqlDatabase::addDatabase("QMYSQL");
        } else {
            _isMysql = false;
            mDatabase = QSqlDatabase::addDatabase("QSQLITE");
        }
        open();
        isOpen = true;
    }
}

Database::~Database() {
    mDatabase.close();
    _instance = 0;
    _dbInstance = 0;
    isOpen = false;
    delete _instance;
}

void Database::changeDatabase(DbType dbType)
{
    if(isOpen) {
    close();
    switch(dbType) {
    case SQLITE:
        _isMysql = false;
        QSqlDatabase::removeDatabase("QMYSQL");
        mDatabase = QSqlDatabase::addDatabase("QSQLITE");
        break;
    case MYSQL:
        _isMysql = true;
        QSqlDatabase::removeDatabase("QSQLITE");
        mDatabase = QSqlDatabase::addDatabase("QMYSQL");
        break;
    }
    open();
    }
}
void Database::open() {
    mDatabase = QSqlDatabase::database();
    bool creerStructure = false;
    QString environment;

#if QT_NO_DEBUG
    environment = "release";
#else
    environment = "debug";
#endif

    if(!AccessDatabase::_exists || AccessDatabase::_dbType == SQLITE)
    {
        _settings = new QSettings("FACT", "FactDev-"+environment);
        _settings->setValue("dbPath", QCoreApplication::applicationDirPath());
        _isMysql = false;
        if(!QFile::exists(
                    _settings->value("dbPath").toString()+"/"+Parameters::DB_FILENAME))
        {
            creerStructure = true;
            _settings->setValue("version", 0);
        }
        Database::mDatabase.setDatabaseName(_settings->value("dbPath").toString()+"/"+Parameters::DB_FILENAME);

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
        query.exec("PRAGMA auto_vacuum=FULL");
        query.exec("PRAGMA synchronous=OFF");
        query.exec("PRAGMA journal_mode=MEMORY");
        query.exec("PRAGMA default_cache_size=10000");
        query.exec("PRAGMA locking_mode=EXCLUSIVE");
        executeFile(QCoreApplication::applicationDirPath()+"/sql/sqlite/createtables.sql");
    } else {
        mDatabase.setHostName(AccessDatabase::_address);
        mDatabase.setDatabaseName(AccessDatabase::_dbName);
        mDatabase.setUserName(AccessDatabase::_userDb);
        mDatabase.setPassword(AccessDatabase::_password);
        mDatabase.setPort(AccessDatabase::_port);
        _isMysql = true;
        if(!Database::mDatabase.open()) {
            if(!Database::mDatabase.open()) {
                throw new DbException(
                            "Impossible d'ouvrir la base de données",
                            "Database::Database",
                            "Impossible d'ouvrir la base de données",
                            22.1);
                exit(22);
            }

        }
        QSqlQuery q;
        q.prepare("SELECT * FROM User");
        if(!q.exec()) {
            qDebug() << "--- Création of database";
            creerStructure = true;
            executeFile(QCoreApplication::applicationDirPath()+"/sql/mysql/createtables.sql");
        }

    }
    if(creerStructure) {
#ifndef QT_NO_DEBUG
        testCases();
#endif
    }
}

void Database::updateBillingNumber()
{
    QSqlQuery q;
    q.prepare("UPDATE Billing set number=:number, isBilling=:isBilling where idBilling=:id");
    for(int i = 1 ; i < 60 ; ++i) {
        q.bindValue(":id", i);
        q.bindValue(":number", i%(60/2));
        q.bindValue(":isBilling", i%2);
        if(!q.exec()) {
            Log::instance(WARNING) << "Update billing Number problems" << lastError(q);
        }
    }
}

inline void Database::testCases() {
    executeFile(QCoreApplication::applicationDirPath()+"/sql/tests/customers.sql");
    executeFile(QCoreApplication::applicationDirPath()+"/sql/tests/projects.sql");
    executeFile(QCoreApplication::applicationDirPath()+"/sql/tests/user.sql");
    executeFile(QCoreApplication::applicationDirPath()+"/sql/tests/billings.sql");
    executeFile(QCoreApplication::applicationDirPath()+"/sql/tests/contributories.sql");
    executeFile(QCoreApplication::applicationDirPath()+"/sql/tests/billingsprojects.sql");
    executeFile(QCoreApplication::applicationDirPath()+"/sql/tests/billingrate.sql");
    executeFile(QCoreApplication::applicationDirPath()+"/sql/tests/removeuselessdata.sql");

    updateBillingNumber();
}

void Database::cleanDatabase() {
    executeFile(QCoreApplication::applicationDirPath()+"/sql/removetables.sql");
}

void Database::executeFile(QString pName) {
    QSqlQuery q;

    Log::instance() << "Execution de " + pName;

    QFile file(pName);
    file.open(QIODevice::ReadOnly);

    QStringList querys = QString(file.readAll()).split(";",
                                                       QString::SkipEmptyParts);
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

void Database::openTransaction()
{
    QSqlQuery q;

    q.prepare((!_isMysql ? "BEGIN" : "START")+QString(" TRANSACTION"));
    if(!q.exec()) {
        qDebug() << _isMysql;
        Log::instance(WARNING) << (_isMysql==false ? "321BEGIN" : "START");
        Log::instance(WARNING) << "Erreur d'ouverture de la transaction";
        Log::instance(WARNING) << lastError(q);

        throw std::exception();
    }
}

void Database::closeTransaction()
{
    QSqlQuery q;

    q.prepare(!_isMysql ? "END TRANSACTION" : "COMMIT");

    if(!q.exec()) {
        Log::instance(WARNING) << "Erreur de fermeture de la transaction";
        Log::instance(WARNING) << lastError(q);
    }

}

inline QString Database::lastError(const QSqlQuery& q) const {
    QString ret = "[ ERREUR  ] " + q.lastError().text()+"\n"
            +"[ query ] " + q.lastQuery() +"\n";

    return ret;
}

QVariant Database::value(const QSqlQuery& q, const QString& champ) const {
    return q.value(champ);
}

}
