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

QStandardItemModel* CustomerDatabase::getCustomerList(QString pSearch, bool archive) {
    QStandardItemModel* retour = new QStandardItemModel();

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

//    q.prepare("SELECT id_p, nom_p, prenom_p, ddn_p,telephone_p "
//              "FROM Customer WHERE UPPER(nom_p) LIKE :pSearch AND (archive=0 OR archive=:archive) ORDER BY nom_p, prenom_p");
//    q.bindValue(":pSearch", '%'+pSearch.toUpper()+'%');
//    q.bindValue(":archive", archive);


//    if(!q.exec()) {
//        throw new DbException("Impossible de lister les Customers", "BddCustomer::getListeCustomers", derniereErreur(q), 1.2);
//    }
//    while(q.next()) {
//        QList<QStandardItem*> ligne;

//        ligne << new QStandardItem(valeur(q, "id_p").toString());
//        // Nom
//        ligne << new QStandardItem(valeur(q, "nom_p").toString().toUpper());
//        // Prénom
//        ligne << new QStandardItem(Util::stringFirstUpper(valeur(q, "prenom_p").toString()));
//        // ddn
//        ligne << new QStandardItem(valeur(q, "ddn_p").toDate().toString("dd/MM/yyyy"));

//        ligne << new QStandardItem(valeur(q, "telephone_p").toString());

//        retour->appendRow(ligne);
//    }
    return retour;
}

Customer CustomerDatabase::getCustomer(const int pId) {
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
//    QSqlQuery q;

//    q.prepare("insert into Customer "
//              "(nom_p, prenom_p, sexe_p, "
//              "telephone_p, ddn_p, "
//              "adresse_p, codepostal_p, ville_p, autorisation_p, nss_p, archive) "
//              "values (:surname, :name, "
//              ":sex, :phone, :bornDate, :address, "
//              ":postalcode, :town, :acceptSendData, :ssNum, 0)");

//    q.bindValue(":name", pCustomer.getName());
//    q.bindValue(":surname", pCustomer.getSurname());
//    q.bindValue(":sex", pCustomer.getSex());
//    q.bindValue(":bornDate", pCustomer.getBornDate().toString("yyyy-MM-dd"));
//    q.bindValue(":phone", pCustomer.getPhone());
//    q.bindValue(":address", pCustomer.getAddress());
//    q.bindValue(":postalcode", pCustomer.getPostalCode());
//    q.bindValue(":town", pCustomer.getTown());
//    q.bindValue(":acceptSendData", (pCustomer.getAcceptSendData() ? 1 : 0));
//    q.bindValue(":ssNum", pCustomer.getSsNum());

//    if(!q.exec()) {
//        throw new DbException("Impossible d'ajouter le Customer", "BddCustomer::addCustomer", derniereErreur(q), 1.3);
//    }

//    return q.lastInsertId().toInt();
}

void CustomerDatabase::updateCustomer(const Customer &pCustomer) {
    QSqlQuery q;
//    q.prepare("update Customer set "
//              "prenom_p=:name, nom_p=:surname, sexe_p=:sex, "
//              "telephone_p=:phone, ddn_p=:bornDate, "
//              "adresse_p=:address, codepostal_p=:postalcode, ville_p=:town, "
//              "autorisation_p=:acceptSendData, nss_p=:ssNum, archive=:archive "
//              "where id_p=:id");
//    q.bindValue(":id", pCustomer.getId());
//    q.bindValue(":name", pCustomer.getName());
//    q.bindValue(":surname", pCustomer.getSurname());
//    q.bindValue(":sex", pCustomer.getSex());
//    q.bindValue(":bornDate", pCustomer.getBornDate().toString("yyyy-MM-dd"));
//    q.bindValue(":phone", pCustomer.getPhone());
//    q.bindValue(":address", pCustomer.getAddress());
//    q.bindValue(":postalcode", pCustomer.getPostalCode());
//    q.bindValue(":town", pCustomer.getTown());
//    q.bindValue(":acceptSendData", (pCustomer.getAcceptSendData() ? 1 : 0));
//    q.bindValue(":ssNum", pCustomer.getSsNum());
//    q.bindValue(":archive", pCustomer.isArchive() ? 1 : 0);
    if(!q.exec()) {
        throw new DbException("Impossible d'éditer les informations du Customer", "BddCustomer::updateCustomer", lastError(q), 1.4);
    }

}

int CustomerDatabase::getNbCustomers() {
    QSqlQuery q;

    q.prepare("select count(id_p) as nb_p from Customer");
    if(!q.exec()) {
        throw new DbException("Impossible d'éditer les informations du Customer", "BddCustomer::updateCustomer", lastError(q), 1.4);
    }
    q.next();

    return value(q, "nb_p").toInt();
}

int CustomerDatabase::getNbWomen() {
    QSqlQuery q;

    q.prepare("select count(id_p) as nb_p from Customer where sexe_p = 'F' ");
    if(!q.exec()) {
        throw new DbException("Impossible d'éditer les informations du Customer", "BddCustomer::updateCustomer", lastError(q), 1.4);
    }
    q.next();

    return value(q, "nb_p").toInt();

}

int CustomerDatabase::getNbMen() {
    QSqlQuery q;

    q.prepare("select count(id_p) as nb_p from Customer where sexe_p = 'M' ");
    if(!q.exec()) {
        throw new DbException("Impossible d'éditer les informations du Customer", "BddCustomer::updateCustomer", lastError(q), 1.4);
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
