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
    q.prepare("SELECT idUser, firstname, lastname, company, title, address, "
              "postalCode, city, email, mobilePhone, phone, noSiret, "
              "workspaceName, workspacePath, pdflatexcommand, complementAddress,website  "
              "FROM User WHERE idUser = :pId");
    q.bindValue(":pId", pId);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible de récupérer le User",
                    "BddUser::getUser",
                    lastError(q),
                    1.2);
    }
    q.next();
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
        user->setPdflatexPath(value(q, "pdflatexcommand").toString());
        user->setAddressComplement(value(q,"complementAddress").toString());
        user->setWebsite(value(q,"website").toString());
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
                "workspaceName = :workspaceName, workspacePath = :workspacePath, pdflatexcommand=:pdflatex, "
                "complementAddress=:complementAddress, website=:website "
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
    q.bindValue(":pdflatex", pUser.getPdflatexPath());
    q.bindValue(":complementAddress", pUser.getAddressComplement());
    q.bindValue(":website", pUser.getWebsite());

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
    QPixmap img;
    QSqlQuery q;
    q.prepare("SELECT image  FROM User WHERE idUser = :pId");
    q.bindValue(":pId", pId);

    if (q.exec()) {
        q.next();
        if(q.first()) {
            img = Utils::Image::bytesToPixmap(q.value("image").toByteArray());
        }
    }
    if (img.size().isEmpty()) {
        img = QPixmap(":/icons/img/company.png");
    }

    return img;
}

void UserDatabase::setUserImage(Models::User& pUser)
{
    QSqlQuery q;

    QByteArray byteArray = Utils::Image::pixmapToBytes(
                *pUser.getImage(),
                pUser.getExtensionImage());

    q.prepare("UPDATE User SET image = :image WHERE idUser = :id ");

    q.bindValue(":id", pUser.getId());
    q.bindValue(":image", byteArray);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible de modifier l'image de l'utilisateur",
                    "BddUser::setUserImage",
                    lastError(q),
                    1.6);
    }
}
}
