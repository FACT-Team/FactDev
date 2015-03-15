/*
 * Thanks to
 * https://marcoarena.wordpress.com/2012/06/23/increase-your-qtest-productivity
 *
 * @aroquemaurel
 */

#include <QApplication>
#include <QString>
#include "QTestRunner/testrunner.h"
#include "database/database.h"
#include "database/accessdatabase.h"

int mysqlExecution(int argc, char **argv);
int sqliteExecution(int argc, char **argv, QCoreApplication& a);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int ret = 0;

    if(sqliteExecution(argc, argv, a) != 0) {
        ret += 2;
    }

    if(mysqlExecution(argc, argv) != 0) {
        ret = 1;
    }

    return  ret;
}

int mysqlExecution(int argc, char **argv)
{
    int ret;
    qDebug() << "Execution des tests de FactDev v"+QString::number(Parameters::VERSION)+" avec MySQL";

    if(argc >= 3) {
        Databases::AccessDatabase::_address = argv[1];
        Databases::AccessDatabase::_userDb = argv[2];
        Databases::AccessDatabase::_password = argv[3];
        Databases::AccessDatabase::_dbName = "FactDev";
        Databases::AccessDatabase::_exists = true;
        Databases::Database::instance();
    } else {
        qDebug() << "Bad parameters ! ";
        return EXIT_FAILURE;
    }

    ret = RUN_ALL_TESTS(0, argv);
    Databases::Database::instance()->cleanDatabase();

    return ret;
}

int sqliteExecution(int argc, char **argv, QCoreApplication& a)
{
    qDebug() << "Execution des tests de FactDev v"+QString::number(Parameters::VERSION)+" avec SQLite";
    QFile f(QString(a.applicationDirPath()+"/"+Parameters::DB_FILENAME));
    f.remove();
    Databases::AccessDatabase::_exists = false;

    int ret = RUN_ALL_TESTS(0, argv);
    Databases::Database::instance()->cleanDatabase();
    delete Databases::Database::instance();
    return ret;
}
