#include "database/customerdatabase.h"
#include "log.h"


CustomerDatabase::CustomerDatabase() throw(DbException*)  : Database() {
_instances << this;
}

// SINGLETON
CustomerDatabase* CustomerDatabase::_instance = 0;

CustomerDatabase*CustomerDatabase::getInstance()throw(DbException*)
{
    if (!_instance) {
        _instance = new CustomerDatabase();
    }

    return _instance;
}


QStandardItemModel* CustomerDatabase::getCustomersTable() throw(DbException*) {
    // TODO implement me

//    QStandardItemModel* retour = new QStandardItemModel();

//        retour->setColumnCount(5);
//        retour->setHorizontalHeaderLabels(
//                    QStringList()
//                    << qApp->tr("Id")
//                    << qApp->tr("Nom")
//                    << qApp->tr("Prénom")
//                    << qApp->tr("Date naissance")
//                    << qApp->tr("Téléphone")
//                    );
//    QSqlQuery q;


//    q.prepare("SELECT id_p ,nom_p, prenom_p, ddn_p, telephone_p "
//              "FROM Customer WHERE archive = 0 ORDER BY UPPER(nom_p), UPPER(prenom_p)");

//    if(!q.exec()) {
//        throw new DbException("Impossible d'obtenir la liste des Customers", "CustomerDatabase::getTableauCustomers", lastError(q), 1.1);
//    }

//    while(q.next()) {
//        QList<QStandardItem*> ligne;

//        ligne << new QStandardItem(valeur(q, "id_p").toString());
//        ligne << new QStandardItem(valeur(q, "nom_p").toString().toUpper());
//        ligne << new QStandardItem(Util::stringFirstUpper(valeur(q, "prenom_p").toString().toUpper()));
//        ligne << new QStandardItem(valeur(q, "ddn_p").toDate().toString("dd/MM/yyyy"));
//        ligne << new QStandardItem(valeur(q, "telephone_p").toString());

//        retour->appendRow(ligne);
//    }

//    return retour;
}

Customer CustomerDatabase::getCustomer(const int pId) {
    // TODO implement me !
//    QSqlQuery q;
//    Customer retour;

//    q.prepare("SELECT * "
//              "FROM Customer WHERE id_p = :pId");
//    q.bindValue(":pId", pId);

//    if(!q.exec()) {
//        throw new DbException("Impossible d'obtenir les informations du Customer", "BddCustomer::getCustomer", derniereErreur(q), 1.5);
//    }
//    q.next();
//    retour.setId(valeur(q, "id_p").toInt());
//    retour.setSurname(valeur(q, "nom_p").toString());
//    retour.setName(valeur(q, "prenom_p").toString());
//    retour.setSex(valeur(q, "sexe_p").toString());
//    retour.setBornDate(valeur(q, "ddn_p").toDate());
//    retour.setPhone(valeur(q, "telephone_p").toString());
//    retour.setPostalCode(valeur(q, "codepostal_p").toString());
//    retour.setAddress(valeur(q, "adresse_p").toString());
//    retour.setTown(valeur(q, "ville_p").toString());
//    retour.setSsNum(valeur(q, "nss_p").toString());
//    retour.setAcceptSendData(valeur(q, "autorisation_p").toBool());
////    retour.setArchive(valeur(q, "archive").toBool());
//    return retour;
}


int CustomerDatabase::addCustomer(const Customer& pCustomer) {
    QSqlQuery q;

    q.prepare(
        "INSERT INTO Customer "
        "(firstnameReferent, lastnameReferent, company, address, "
        "postalCode, city, country, email, mobilePhone, phone, fax)"
        "VALUES"
        "(:firstnameReferent, :lastnameReferent, :company, :address, "
        ":postalCode, :city, :country, :email, :mobilePhone, :phone, :fax)"
    );

    q.bindValue(":firstnameReferent", pCustomer.getFirstnameReferent());
    q.bindValue(":lastnameReferent", pCustomer.getLastnameReferent());
    q.bindValue(":company", pCustomer.getCompany());
    q.bindValue(":address", pCustomer.getAddress());
    q.bindValue(":postalCode", pCustomer.getPostalCode());
    q.bindValue(":city", pCustomer.getCity());
    q.bindValue(":country", pCustomer.getCountry());
    q.bindValue(":email", pCustomer.getEmail());
    q.bindValue(":mobilePhone", pCustomer.getMobilePhone());
    q.bindValue(":phone", pCustomer.getPhone());
    q.bindValue(":fax", pCustomer.getFax());

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'ajouter le Customer",
            "BddCustomer::addCustomer",
            lastError(q),
            1.3);
    }

    return q.lastInsertId().toInt();
}

void CustomerDatabase::updateCustomer(const Customer &pCustomer) {

    QSqlQuery q;
    q.prepare(
        "UPDATE Customer SET "
        "firstnameReferent=:firstname, lastnameReferent=:lastname,"
        "company=:company, address=:address, postalCode=:postalCode, city:=city,"
        "country:=country, email=:email, mobilePhone=:mobilePhone, phone=:phone,"
        "fax=:fax"
        "WHERE idCustomer=:idCustomer");

    q.bindValue(":idCustomer", pCustomer.getId());
    q.bindValue(":firstname", pCustomer.getFirstnameReferent());
    q.bindValue(":lastname", pCustomer.getLastnameReferent());
    q.bindValue(":company", pCustomer.getCompany();
    q.bindValue(":address", pCustomer.getAddress());
    q.bindValue(":phone", pCustomer.getPhone());
    q.bindValue(":postalCode", pCustomer.getPostalCode());
    q.bindValue(":city", pCustomer.getCity());
    q.bindValue(":country", pCustomer.getCountry());
    q.bindValue(":email", (pCustomer.getEmail()));
    q.bindValue(":mobilePhone", pCustomer.getMobilePhone());
    q.bindValue(":phone", pCustomer.getPhone());
    q.bindValue(":fax", pCustomer.getFax());

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'éditer les informations du Customer",
            "BddCustomer::updateCustomer",
            lastError(q),
            1.4);
    }

}

void CustomerDatabase::removeCustomer(const int pId)
{
    QSqlQuery q;
    q.prepare(
        "DELETE FROM Customer "
        "WHERE idCustomer=:pId"
        );

    q.bindValue(":pId", pId);

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'éditer les informations du Customer",
            "BddCustomer::updateCustomer",
            lastError(q),
            1.5);
    }

}

int CustomerDatabase::getNbCustomers() {
    QSqlQuery q;

    q.prepare("SELECT count(idCustomer) AS nb_p FROM Customer");

    if(!q.exec()) {
        throw new DbException(
            "Impossible d'éditer les informations du Customer",
            "BddCustomer::updateCustomer",
            lastError(q),
            1.6);
    }
    q.next();

    return value(q, "nb_p").toInt();
}

int CustomerDatabase::getNbUsageData() {
    QSqlQuery q;

    q.prepare("select count(id_p) as nb_p from Customer where autorisation_p = 1 ");
    if(!q.exec()) {
        throw new DbException("Impossible d'éditer les informations du Customer", "BddCustomer::updateCustomer", lastError(q), 1.4);
    }
    q.next();

    return value(q, "nb_p").toInt();
}
