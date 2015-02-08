#include "database/userdatabase.h"

namespace Databases {

UserDatabase::UserDatabase() throw(DbException*)  : Database() {
    _instances << this;
}

// SINGLETON
UserDatabase* UserDatabase::_instance = 0;

UserDatabase* UserDatabase::instance()throw(DbException*) {
    if (!_instance) {
        _instance = new UserDatabase();
    }

    return _instance;
}

Models::User *UserDatabase::getUser(const int pId)
{
    QSqlQuery q;
    Models::User* user;

    q.prepare("SELECT * FROM User WHERE idUser = :pId");
    q.bindValue(":pId", pId);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible de récupérer le User",
                    "BddUser::getUser",
                    lastError(q),
                    1.2);
    }

    if(q.first()) {
        user = new Models::User();
        user->setId(value(q, "idUser").toInt());
        user->setFirstname(value(q,"firstname").toString());
        user->setLastname(value(q,"lastname").toString());
        user->setCompany(value(q,"company").toString());
        user->setTitle(value(q,"title").toString());
        user->setAddress(value(q,"address").toString());
        user->setPostalCode(value(q,"postalCode").toString());
        user->setCity(value(q,"city").toString());
        user->setEmail(value(q,"email").toString());
        user->setMobilePhone(value(q,"mobilePhone").toString());
        user->setPhone(value(q,"phone").toString());
        user->setNoSiret(value(q,"noSiret").toString());
    } else {
        user = NULL;
    }

    return user;
}

void UserDatabase::updateUser(const Models::User& pUser) {
    QSqlQuery q;
    q.prepare(
                "UPDATE User SET "
                "firstname = :firstname, lastname = :lastname, company = :company, "
                "title = :title, address = :address, postalCode = :postalCode, "
                "city = :city, email = :email, mobilePhone = :mobilePhone, "
                "phone = :phone, noSiret = :noSiret "
                "WHERE idUser = :idUser");

    q.bindValue(":idUser", pUser.getId());
    q.bindValue(":firstname", pUser.getFirstname());
    q.bindValue(":lastname", pUser.getLastname());
    q.bindValue(":company", pUser.getCompany());
    q.bindValue(":title", pUser.getTitle());
    q.bindValue(":address", pUser.getAddress());
    q.bindValue(":phone", pUser.getPhone());
    q.bindValue(":postalCode", pUser.getPostalCode());
    q.bindValue(":city", pUser.getCity());
    q.bindValue(":email", pUser.getEmail());
    q.bindValue(":mobilePhone", pUser.getMobilePhone());
    q.bindValue(":phone", pUser.getPhone());
    q.bindValue(":noSiret", pUser.getNoSiret());

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'éditer les informations du User",
                    "BddUser::updateUser",
                    lastError(q),
                    1.4);
    }
}
}
