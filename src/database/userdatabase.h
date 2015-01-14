#ifndef USERDATABASE_H
#define USERDATABASE_H
#include "database/database.h"
#include "exceptions/dbexception.h"
#include "models/user.h"

class UserDatabase : public Database
{
private:
    static UserDatabase* _instance;
    UserDatabase()throw(DbException*) ;
public:
    static UserDatabase* instance()throw(DbException*);

    QStandardItemModel* getUserTable() throw(DbException*);

    /**
     * @brief getUser
     * @param pId user id (1 default)
     * get informations about the user (identified by 'pId')
     * @return the user
     */
    User *getUser(const int pId=1);

    /**
     * @brief updateUser
     * update informations about the user
     */
    void updateUser(const User&);

};

#endif // USERDATABASE_H
