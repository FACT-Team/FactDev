#include "database/userdatabase.h"
#include <QBuffer>

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
        user->setWorkspaceName(value(q,"workspaceName").toString());
        user->setWorkspacePath(value(q,"workspacePath").toString());
//        user->setImage(
//                    QPixmap::fromImage(
//                        QImage::fromData(q.value("image").toByteArray())));
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
                "phone = :phone, noSiret = :noSiret, "
                "workspaceName = :workspaceName, workspacePath = :workspacePath "
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
    q.bindValue(":workspaceName", pUser.getWorkspaceName());
    q.bindValue(":workspacePath", pUser.getWorkspacePath());

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'éditer les informations du User",
                    "BddUser::updateUser",
                    lastError(q),
                    1.4);
    }
}

QPixmap UserDatabase::getUserImage(const int pId)
{
    QPixmap imgUser;
    QSqlQuery q;
    q.prepare("SELECT image  FROM User WHERE idUser = :pId");
    q.bindValue(":pId", pId);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible de récupérer l'image de l'utilisateur' ",
                    "BddCustomer::getUserImage",
                    lastError(q),
                    1.5);
    }

    if(q.first()) {
        imgUser =
                QPixmap::fromImage(
                    QImage::fromData(q.value("image").toByteArray()));
    }

    return imgUser;
}

void UserDatabase::setUserImage(const Models::User& pUser)
{
    QSqlQuery q;

    QImage image(pUser.getImage().toImage());
    qDebug() << image.size();
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer);

    q.prepare(
                "UPDATE User "
                "SET image = :image "
                "WHERE idUser = :id ");

    q.bindValue(":id", pUser.getId());
    q.bindValue(":image", byteArray);
    //q.addBindValue(byteArray);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible de modifier l'image de l'utilisateur",
                    "BddUser::setUserImage",
                    lastError(q),
                    1.6);
    }
}
}
