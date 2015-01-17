#ifndef USERDATABASE_H
#define USERDATABASE_H

#include "database/database.h"
#include "exceptions/dbexception.h"
#include "models/user.h"

class UserDatabase : public Database
{
private:
    static UserDatabase* _instance;
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
