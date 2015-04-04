#ifndef USERDATABASE_H
#define USERDATABASE_H

#include "database/database.h"
#include "exceptions/dbexception.h"
#include "models/user.h"
#include "gui/utils/image.h"

namespace Databases {

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
     * @brief UserDatabase::getUser Get informations about the user (identified
     * by 'pId')
     * @param pId user id (1 default)
     * @return the user
     */
    Models::User *getUser(const int pId=1);

    /**
     * @brief UserDatabase::updateUser Update informations about the user
     */
    void updateUser(const Models::User&);

    /**
     * @brief UserDatabase::getUserImage Return a User image
     * @param pId Customer id
     * @return User image
     */
    QPixmap getUserImage(const int pId=1);

    /**
     * @brief UserDatabase::setUserImage Change the image of the
     * customer <i>pCustomer</i>
     * @param pUser User
     */
    void setUserImage(Models::User &pUser);

};
}
#endif // USERDATABASE_H
