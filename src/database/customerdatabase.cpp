#include "database/clientdatabase.h"
#include "log.h"


ClientDatabase::ClientDatabase()throw(DbException*)  : Bdd() {
_instances << this;
}

// SINGLETON
ClientDatabase* ClientDatabase::_instance = 0;

ClientDatabase*ClientDatabase::getInstance()throw(DbException*)
{
    if (!_instance) {
        _instance = new ClientDatabase();
    }

    return _instance;
}


QStandardItemModel* ClientDatabase::getClientsTable() throw(DbException*) {
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
//              "FROM Client WHERE archive = 0 ORDER BY UPPER(nom_p), UPPER(prenom_p)");

//    if(!q.exec()) {
//        throw new DbException("Impossible d'obtenir la liste des Clients", "ClientDatabase::getTableauClients", lastError(q), 1.1);
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

QStandardItemModel* ClientDatabase::getClientList(QString pSearch, bool archive) {
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

//    q.prepare("SELECT id_p, nom_p, prenom_p, ddn_p,telephone_p "
//              "FROM Client WHERE UPPER(nom_p) LIKE :pSearch AND (archive=0 OR archive=:archive) ORDER BY nom_p, prenom_p");
//    q.bindValue(":pSearch", '%'+pSearch.toUpper()+'%');
//    q.bindValue(":archive", archive);


//    if(!q.exec()) {
//        throw new DbException("Impossible de lister les Clients", "BddClient::getListeClients", derniereErreur(q), 1.2);
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

Client ClientDatabase::getClient(const int pId) {
    QSqlQuery q;
    Client retour;

    q.prepare("SELECT * "
              "FROM Client WHERE id_p = :pId");
    q.bindValue(":pId", pId);

    if(!q.exec()) {
        throw new DbException("Impossible d'obtenir les informations du Client", "BddClient::getClient", derniereErreur(q), 1.5);
    }
    q.next();
    retour.setId(valeur(q, "id_p").toInt());
    retour.setSurname(valeur(q, "nom_p").toString());
    retour.setName(valeur(q, "prenom_p").toString());
    retour.setSex(valeur(q, "sexe_p").toString());
    retour.setBornDate(valeur(q, "ddn_p").toDate());
    retour.setPhone(valeur(q, "telephone_p").toString());
    retour.setPostalCode(valeur(q, "codepostal_p").toString());
    retour.setAddress(valeur(q, "adresse_p").toString());
    retour.setTown(valeur(q, "ville_p").toString());
    retour.setSsNum(valeur(q, "nss_p").toString());
    retour.setAcceptSendData(valeur(q, "autorisation_p").toBool());
//    retour.setArchive(valeur(q, "archive").toBool());
    return retour;
}

int ClientDatabase::addClient(const Client& pClient) {
    QSqlQuery q;

    q.prepare("insert into Client "
              "(nom_p, prenom_p, sexe_p, "
              "telephone_p, ddn_p, "
              "adresse_p, codepostal_p, ville_p, autorisation_p, nss_p, archive) "
              "values (:surname, :name, "
              ":sex, :phone, :bornDate, :address, "
              ":postalcode, :town, :acceptSendData, :ssNum, 0)");

    q.bindValue(":name", pClient.getName());
    q.bindValue(":surname", pClient.getSurname());
    q.bindValue(":sex", pClient.getSex());
    q.bindValue(":bornDate", pClient.getBornDate().toString("yyyy-MM-dd"));
    q.bindValue(":phone", pClient.getPhone());
    q.bindValue(":address", pClient.getAddress());
    q.bindValue(":postalcode", pClient.getPostalCode());
    q.bindValue(":town", pClient.getTown());
    q.bindValue(":acceptSendData", (pClient.getAcceptSendData() ? 1 : 0));
    q.bindValue(":ssNum", pClient.getSsNum());

    if(!q.exec()) {
        throw new DbException("Impossible d'ajouter le client", "BddClient::addClient", derniereErreur(q), 1.3);
    }

    return q.lastInsertId().toInt();
}

void ClientDatabase::updateClient(const Client &pClient) {
    QSqlQuery q;
//    q.prepare("update Client set "
//              "prenom_p=:name, nom_p=:surname, sexe_p=:sex, "
//              "telephone_p=:phone, ddn_p=:bornDate, "
//              "adresse_p=:address, codepostal_p=:postalcode, ville_p=:town, "
//              "autorisation_p=:acceptSendData, nss_p=:ssNum, archive=:archive "
//              "where id_p=:id");
//    q.bindValue(":id", pClient.getId());
//    q.bindValue(":name", pClient.getName());
//    q.bindValue(":surname", pClient.getSurname());
//    q.bindValue(":sex", pClient.getSex());
//    q.bindValue(":bornDate", pClient.getBornDate().toString("yyyy-MM-dd"));
//    q.bindValue(":phone", pClient.getPhone());
//    q.bindValue(":address", pClient.getAddress());
//    q.bindValue(":postalcode", pClient.getPostalCode());
//    q.bindValue(":town", pClient.getTown());
//    q.bindValue(":acceptSendData", (pClient.getAcceptSendData() ? 1 : 0));
//    q.bindValue(":ssNum", pClient.getSsNum());
//    q.bindValue(":archive", pClient.isArchive() ? 1 : 0);
    if(!q.exec()) {
        throw new DbException("Impossible d'éditer les informations du client", "BddClient::updateClient", derniereErreur(q), 1.4);
    }

}

int ClientDatabase::getNbClients() {
    QSqlQuery q;

    q.prepare("select count(id_p) as nb_p from Client");
    if(!q.exec()) {
        throw new DbException*("...");
    }
    q.next();

    return value(q, "nb_p").toInt();
}

int ClientDatabase::getNbWomen() {
    QSqlQuery q;

    q.prepare("select count(id_p) as nb_p from Client where sexe_p = 'F' ");
    if(!q.exec()) {
        Log::getInstance(WARNING) << "BddClient::getNbWomen";
        Log::getInstance(WARNING) << derniereErreur(q);
    }
    q.next();

    return valeur(q, "nb_p").toInt();

}

int ClientDatabase::getNbMen() {
    QSqlQuery q;

    q.prepare("select count(id_p) as nb_p from Client where sexe_p = 'M' ");
    if(!q.exec()) {
        Log::getInstance(WARNING) << "BddClient::getNbMen";
        Log::getInstance(WARNING) << derniereErreur(q);
    }
    q.next();

    return valeur(q, "nb_p").toInt();
}

int ClientDatabase::getNbUsageData() {
    QSqlQuery q;

    q.prepare("select count(id_p) as nb_p from Client where autorisation_p = 1 ");
    if(!q.exec()) {
        Log::getInstance(WARNING) << "BddClient::getNbUsageData";
        Log::getInstance(WARNING) << derniereErreur(q);
    }
    q.next();

    return valeur(q, "nb_p").toInt();
}
