#ifndef USERDATABASE_H
#define USERDATABASE_H

#include "database/database.h"
#include "exceptions/dbexception.h"
#include "models/user.h"

using namespace Models;

/**
 * @author Florent Berbie
 * @brief The UserDatabase class Access to User data in the the table User of
 * the <b>Database</b>
 * @see Database
 * @see User
 */
class UserDatabase : public Database
{
private:
    static UserDatabase* _instance; //!< Singleton instance of UserDatabase
    /**
     * @brief UserDatabase: is a singleton
     */
    UserDatabase()throw(DbException*) ;

public:
    /**
     * @brief UserDatabase::getInstance Return an instance of UserDatabase
     * @return Instance of UserDatabase
     */
    static UserDatabase* instance()throw(DbException*);

    /**
     * @brief getUserTable Return an item model of User for QTableView
     * @return QStandardItemModel an item model
     */
    QStandardItemModel* getUserTable() throw(DbException*);

    /**
     * @brief getUser Get informations about the user (identified by 'pId')
     * @param pId user id (1 default)     * 
     * @return the user
     */
    User *getUser(const int pId=1);

    /**
     * @brief updateUser Update informations about the user
     */
    void updateUser(const User&);

};

#endif // USERDATABASE_H
