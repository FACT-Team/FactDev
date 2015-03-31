#include "database/customerdatabase.h"
#include <QDebug>

namespace Databases {
CustomerDatabase::CustomerDatabase() throw(DbException*)  : Database() {
    _instances << this;
}

// SINGLETON
CustomerDatabase* CustomerDatabase::_instance = 0;

CustomerDatabase*CustomerDatabase::instance()throw(DbException*)
{
    if (!_instance) {
        _instance = new CustomerDatabase();
    }

    return _instance;
}


WdgModels::CustomersTableModel*
    CustomerDatabase::getCustomersTable(QString filter) throw(DbException*)
{
    WdgModels::CustomersTableModel* ret
            = new WdgModels::CustomersTableModel();
    QSqlQuery q;

    q.prepare( "SELECT DISTINCT c.idCustomer as cidcustomer, "
               "c.firstnameReferent as cfirstnameReferent, "
               "UPPER(c.lastnameReferent) as clastnameReferent, "
               "c.company as ccompany, "
               "c.address as caddress, c.postalCode as cpostalcode, "
               "c.city as ccity, c.country as ccountry, c.email as cemail, "
               "c.phone as cphone, c.mobilephone as cmobilephone, "
               "c.fax as cfax "
               "FROM Customer c "+filter+" "
               "ORDER BY 4, 3"
               );

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'obtenir la liste des Customers",
                    "CustomerDatabase::getCustomersTable",
                    lastError(q),
                    1.1);
    }

    while(q.next()) {
        Customer c = *getCustomer(q);
        ret->append(c);
    }

    return ret;
}



QStandardItemModel* CustomerDatabase::getTree(QString filter)
throw(DbException*)
{
    QStandardItemModel* ret = new QStandardItemModel();

    QSqlQuery q;

    q.prepare(  "SELECT DISTINCT c.idCustomer as cidcustomer, "
                "c.firstnameReferent as cfirstnameReferent, "
                "UPPER(c.lastnameReferent) as clastnameReferent, "
                "c.company as ccompany, "
                "c.address as caddress, c.postalCode as cpostalcode, "
                "c.city as ccity, c.country as ccountry, c.email as cemail, "
                "c.phone as cphone, c.mobilephone as cmobilephone, "
                "c.fax as cfax "
                "FROM Customer c "+filter+" "
                "ORDER BY 4, 3 "
                );

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'obtenir la liste des Customers",
                    "CustomerDatabase::getTree",
                    lastError(q),
                    1.1);
    }

    ret->appendRow(getItemRoot());

    // Manage any customer
    while (q.next()) {
        QStandardItem *itemCustomer = getItemCustomer(q);

        // QUERY 2
        // Query for projects of a customer
        QSqlQuery q2;

        q2.prepare("SELECT * FROM Project "
                   "WHERE idCustomer = :idCustomer "
                   "ORDER BY UPPER(name), UPPER(description)");
        q2.bindValue(":idCustomer",value(q, "cidcustomer").toString());

        if(!q2.exec()) {
            throw new DbException(
                        "Impossible d'obtenir la liste des Projects",
                        "CustomerDatabase::getTree",
                        lastError(q2),
                        1.1);
        }

        // Manage any project of a customer
        while (q2.next()) {
            QStandardItem *itemProject = getItemProject(q2);

            // QUERY 3
            // Query for bills or quotes of a project of a customer
            QSqlQuery q3;

            q3.prepare(
                     "SELECT DISTINCT b.isPaid, b.description, "
                     "b.idBilling,title,number,isBilling,date "
                     "FROM Billing b, BillingProject bp "
                     "WHERE idProject = :idproject "
                     "AND b.idBilling = bp.idBilling ORDER BY date DESC");
            q3.bindValue(":idproject",value(q2, "idProject").toString());

            if(!q3.exec()) {
                throw new DbException(
                            "Impossible d'obtenir la liste des Factures/Devis",
                            "CustomerDatabase::getTree",
                            lastError(q3),
                            1.1);
            }
            // Manage any bill/quote of a project of a customer
            while (q3.next()) {
                itemProject->appendRow(
                            Databases::BillingDatabase::instance()->getBilling(q3)->getItem());
            }

            itemCustomer->appendRow(itemProject);
        }

        ret->appendRow(itemCustomer);
    }

    return ret;
}

QStandardItem *CustomerDatabase::getItemRoot() {
    QStandardItem* itemRoot = new QStandardItem("Tous les clients");
    itemRoot->setIcon(QIcon(":icons/img/all_customers.png"));
    return itemRoot;
}

QStandardItem *CustomerDatabase::getItemCustomer(QSqlQuery q1) {
    QStandardItem *itemCustomer;
    if(value(q1,"ccompany").toString().isEmpty()) {
        itemCustomer =
                new QStandardItem(value(q1, "clastnameReferent").toString().toUpper()
                + " "
                + Utils::String::firstLetterToUpper(value(q1,"cfirstnameReferent").toString()));
    } else {
        itemCustomer =
                new QStandardItem(Utils::String::firstLetterToUpper(value(q1,"ccompany").toString()));
    }
    itemCustomer->setIcon(QIcon(":icons/customer"));
    return itemCustomer;
}

QStandardItem *CustomerDatabase::getItemProject(QSqlQuery q2) {
    QStandardItem *itemProject = new QStandardItem(value(q2,"name").toString());
    itemProject->setIcon(QIcon(":icons/img/project"));
    return itemProject;
}

QSharedPointer<Models::Customer> CustomerDatabase::getCustomer(QSqlQuery &q)
{
    QSharedPointer<Models::Customer> customer =
            QSharedPointer<Models::Customer>(new Models::Customer());
    customer->setId(value(q, "cidCustomer").toInt());
    customer->setFirstname(value(q,"cfirstnameReferent").toString());
    customer->setLastname(value(q,"clastnameReferent").toString());
    customer->setCompany(value(q,"ccompany").toString());
    customer->setAddress(value(q,"caddress").toString());
    customer->setPostalCode(value(q,"cpostalCode").toString());
    customer->setCity(value(q,"ccity").toString());
    customer->setCountry(value(q,"ccountry").toString());
    customer->setEmail(value(q,"cemail").toString());
    customer->setPhone(value(q,"cphone").toString());
    customer->setMobilePhone(value(q,"cmobilePhone").toString());
    customer->setFax(value(q,"cfax").toString());

    return customer;
}

void CustomerDatabase::updateCustomer(QSqlQuery &q, Customer &pCustomer)
{
    q.bindValue(":idCustomer", pCustomer.getId());
    q.bindValue(":firstnameReferent", pCustomer.getFirstname());
    q.bindValue(":lastnameReferent", pCustomer.getLastname());
    q.bindValue(":company", pCustomer.getCompany());
    q.bindValue(":address", pCustomer.getAddress());
    q.bindValue(":postalCode", pCustomer.getPostalCode());
    q.bindValue(":city", pCustomer.getCity());
    q.bindValue(":country", pCustomer.getCountry());
    q.bindValue(":email", (pCustomer.getEmail()));
    q.bindValue(":phone", pCustomer.getPhone());
    q.bindValue(":mobilePhone", pCustomer.getMobilePhone());    
    q.bindValue(":fax", pCustomer.getFax());
}

QPixmap CustomerDatabase::getCustomerImage(const int pId)
{
    QPixmap img;
    QSqlQuery q;
    q.prepare("SELECT image FROM Customer WHERE idCustomer = :pId");
    q.bindValue(":pId", pId);
    //Debug()
    if (q.exec()) {
        q.next();
        if(q.first()) {
            img =  Utils::Image::bytesToPixmap(q.value("image").toByteArray());
        }

    }
    if (img.size().isEmpty()) {
        img = QPixmap(":/icons/customer");
    }

    return img;
}

void CustomerDatabase::setCustomerImage(Models::Customer &pCustomer) {
    QSqlQuery q;
    qDebug() << pCustomer.getLastname() << " - " << pCustomer.getImage()->size();
    QByteArray byteArray = Utils::Image::pixmapToBytes(
                *pCustomer.getImage(),
                pCustomer.getExtensionImage());

    q.prepare("UPDATE Customer SET image = :image WHERE idCustomer = :id ");

    q.bindValue(":id", pCustomer.getId());
    q.bindValue(":image", byteArray);


    if(!q.exec()) {
        throw new DbException(
                    "Impossible de modifier l'image du Customer",
                    "BddCustomer::setCustomerImage",
                    lastError(q),
                    1.3);
    }
    qDebug() << pCustomer.getLastname() << " - " << "Image inserted";

}

QSharedPointer<Models::Customer> CustomerDatabase::getCustomer(const int pId) {
    QSqlQuery q;
    QSharedPointer<Models::Customer> customer;

    q.prepare("SELECT DISTINCT c.idCustomer as cidcustomer, "
              "c.firstnameReferent as cfirstnameReferent, "
              "c.lastnameReferent as clastnameReferent, c.company as ccompany, "
              "c.address as caddress, c.postalCode as cpostalcode, "
              "c.city as ccity, c.country as ccountry, c.email as cemail, "
              "c.phone as cphone, c.mobilephone as cmobilephone, c.fax as cfax "
              "FROM Customer c "
              "WHERE idCustomer = :pId");
    q.bindValue(":pId", pId);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'ajouter le Customer",
                    "BddCustomer::getCustomer",
                    lastError(q),
                    1.2);
    }

    if(q.first()) {
        customer = getCustomer(q);
    }

    return customer;
}


int CustomerDatabase::addCustomer(const Models::Customer &pCustomer) {
    QSqlQuery q;

    q.prepare(
                "INSERT INTO Customer "
                "(firstnameReferent, lastnameReferent, company, address, "
                "postalCode, city, country, email, mobilePhone, phone, fax) "
                " VALUES "
                "(:firstnameReferent, :lastnameReferent, :company, :address, "
                ":postalCode, :city, :country, :email,:mobilePhone, :phone,"
                ":fax)"
                );

    q.bindValue(":firstnameReferent", pCustomer.getFirstname());
    q.bindValue(":lastnameReferent", pCustomer.getLastname());
    q.bindValue(":company", pCustomer.getCompany());
    q.bindValue(":address", pCustomer.getAddress());
    q.bindValue(":postalCode", pCustomer.getPostalCode());
    q.bindValue(":city", pCustomer.getCity());
    q.bindValue(":country", pCustomer.getCountry());
    q.bindValue(":email", pCustomer.getEmail());
    q.bindValue(":phone", pCustomer.getPhone());
    q.bindValue(":mobilePhone", pCustomer.getMobilePhone());
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

void CustomerDatabase::updateCustomer(Models::Customer &pCustomer) {
    QSqlQuery q;
    q.prepare(
                "UPDATE Customer SET "
                "firstnameReferent=:firstnameReferent, "
                "lastnameReferent=:lastnameReferent, company=:company, "
                "address=:address, postalCode=:postalCode, city=:city, "
                "country=:country, email=:email, mobilePhone=:mobilePhone, "
                "phone=:phone, fax=:fax "
                "WHERE idCustomer=:idCustomer");
    updateCustomer(q, pCustomer);

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
    q.prepare("DELETE FROM Customer WHERE idCustomer=:pId");
    q.bindValue(":pId", pId);

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'éditer les informations du Customer",
                    "BddCustomer::removeCustomer",
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
                    "BddCustomer::getNbCustomers",
                    lastError(q),
                    1.6);
    }
    q.next();

    return value(q, "nb_p").toInt();
}
}
