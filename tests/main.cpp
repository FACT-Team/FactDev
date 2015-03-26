/*
 * Thanks to
 * https://marcoarena.wordpress.com/2012/06/23/increase-your-qtest-productivity
 *
 * @aroquemaurel
 */

#include <QApplication>
#include <QString>
#include <iostream>
#include <QDebug>
#include "QTestRunner/testrunner.h"
#include "database/database.h"
#include "database/accessdatabase.h"

int mysqlExecution(int argc, char **argv);
int sqliteExecution(QCoreApplication& a);

#include <QtCore/QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int ret = 0;

    if(sqliteExecution(a) != 0) {
        ret += 2;
    }

    if(mysqlExecution(argc, argv) != 0) {
        ret = 1;
    }

    if(ret == 0) {
        qDebug() << "All tests passed ! \\o/";
    } else {
        qDebug() << "Some tests failed…";
    }
    return  ret;
}

int mysqlExecution(int argc, char**argv)
{
    int ret;
    std::cout << "=== Execution des tests de FactDev v" << QString::number(Parameters::VERSION).toStdString() << " avec MySQL ===" << std::endl;

    if(argc >= 3) {
        Databases::AccessDatabase::init();
        Databases::AccessDatabase::_address = argv[1];
        Databases::AccessDatabase::_userDb = argv[2];
        Databases::AccessDatabase::_password = argv[3];
        Databases::AccessDatabase::_dbName = "FactDev";
        Databases::AccessDatabase::_exists = true;
        Databases::AccessDatabase::_dbType = Databases::MYSQL;
        Databases::Database::instance(true);
    } else {
        std::cerr << "Bad parameters ! "<< std::endl;
        return EXIT_FAILURE;
    }

    ret = RUN_ALL_TESTS();
    Databases::Database::instance()->cleanDatabase();

    return ret;
}

int sqliteExecution(QCoreApplication& a)
{
    std::cout << "=== Execution des tests de FactDev v"+QString::number(Parameters::VERSION).toStdString()+" avec SQLite ===" << std::endl;
    QFile f(QString(a.applicationDirPath()+"/"+Parameters::DB_FILENAME));
    f.remove();
    Databases::AccessDatabase::_dbType = Databases::SQLITE;
    Databases::AccessDatabase::_exists = true;
    Databases::Database::instance(true);
    int ret = RUN_ALL_TESTS();
    std::cout << "-- Clean of database" << std::endl;
    Databases::Database::instance()->cleanDatabase();
    delete Databases::Database::instance();
    return ret;
}
