#include "database/userdatabase.h"
#include "models/user.h"


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

User *UserDatabase::getUser(const int pId)
{
    QSqlQuery q;
    User* user;

    q.prepare("SELECT * FROM User WHERE idUser = :pId");
    q.bindValue(":pId", pId);

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'ajouter le Customer",
            "BddCustomer::getCustomer",
            lastError(q),
            1.2);
    }

    if(q.first()) {
        user = new User();
        user->setId(value(q, "pId").toInt());
        user->setFirstname(value(q,"firstname").toString());
        user->setLastname(value(q,"lastname").toString());
        user->setCompany(value(q,"company").toString());
        user->setAddress(value(q,"address").toString());
        user->setPostalCode(value(q,"postalCode").toString());
        user->setCity(value(q,"city").toString());
        user->setCountry(value(q,"country").toString());
        user->setEmail(value(q,"email").toString());
        user->setMobilePhone(value(q,"mobilePhone").toString());
        user->setPhone(value(q,"phone").toString());
        user->setFax(value(q,"fax").toString());
        user->setNoSiret(value(q,"noSiret").toString());
    } else {
        user = NULL;
    }

    return user;
}

void UserDatabase::updateUser(const User& pUser) {
    QSqlQuery q;
    q.prepare(
        "UPDATE User SET "
        "firstnameReferent= :firstname, lastnameReferent= :lastname,"
        "company= :company, address= :address, postalCode= :postalCode,"
        "city= :city, country= :country, email= :email,"
        "mobilePhone= :mobilePhone, phone= :phone, fax= :fax, noSiret= :noSiret"
        "WHERE idUser=:idUser");

    q.bindValue(":idUser", pUser.getId());
    q.bindValue(":firstname", pUser.getFirstname());
    q.bindValue(":lastname", pUser.getLastname());
    q.bindValue(":company", pUser.getCompany());
    q.bindValue(":address", pUser.getAddress());
    q.bindValue(":phone", pUser.getPhone());
    q.bindValue(":postalCode", pUser.getPostalCode());
    q.bindValue(":city", pUser.getCity());
    q.bindValue(":country", pUser.getCountry());
    q.bindValue(":email", (pUser.getEmail()));
    q.bindValue(":mobilePhone", pUser.getMobilePhone());
    q.bindValue(":phone", pUser.getPhone());
    q.bindValue(":fax", pUser.getFax());
    q.bindValue("noSiret", pUser.getNoSiret());

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'éditer les informations du Customer",
            "BddCustomer::updateCustomer",
            lastError(q),
            1.4);
    }
}
