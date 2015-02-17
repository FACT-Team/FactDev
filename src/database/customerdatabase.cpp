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
    q.prepare("SELECT DISTINCT c.idCustomer , c.firstnameReferent, "
              "c.lastnameReferent, c.company, c.address, c.postalCode, "
              "c.city, c.country, c.email, c.mobilephone, c.phone, c.fax "
              "FROM Customer c, Project p, BillingProject bp "
              "WHERE c.idCustomer = p.idCustomer "
              "AND bp.idProject = p.idProject "
              "AND 1 "+filter+" "
              "ORDER BY UPPER(company), UPPER(lastnameReferent)");

    if(!q.exec()) {
        throw new DbException(
                    "Impossible d'obtenir la liste des Customers",
                    "CustomerDatabase::getCustomersTable",
                    lastError(q),
                    1.1);
    }

    while(q.next()) {
        ret->append(*getCustomer(q));
    }

    return ret;
}



QStandardItemModel* CustomerDatabase::getTree(QString filter)
throw(DbException*)
{
    QStandardItemModel* ret = new QStandardItemModel();

    QSqlQuery q;


    q.prepare( "SELECT DISTINCT c.idCustomer , c.firstnameReferent, "
               "c.lastnameReferent, c.company, c.address, c.postalCode, "
               "c.city, c.country, c.email, c.mobilephone, c.phone, c.fax "
               "FROM Customer c, Project p, BillingProject bp "
               "WHERE c.idCustomer = p.idCustomer "
               "AND bp.idProject = p.idProject "
               "AND 1 "+filter+" "
               "ORDER BY UPPER(company), UPPER(lastnameReferent)");

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
                   "WHERE idCustomer = :idCustom "
                   "ORDER BY UPPER(name), UPPER(description)");
        q2.bindValue(":idCustom",value(q, "idCustomer").toString());

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
                     "SELECT DISTINCT b.idBilling,title,number,isBilling,date "
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
            while (q3.next()) itemProject->appendRow(getItemBillQuote(q3));

            itemCustomer->appendRow(itemProject);
        }

        ret->appendRow(itemCustomer);
    }

    return ret;
}

QStandardItem *CustomerDatabase::getItemRoot() {
    QStandardItem* itemRoot = new QStandardItem("Tous les clients");
    itemRoot->setIcon(QIcon(":icons/customer"));
    return itemRoot;
}

QStandardItem *CustomerDatabase::getItemCustomer(QSqlQuery q1) {
    QStandardItem *itemCustomer;
    if(value(q1,"company").toString().isEmpty()) {
        itemCustomer =
                new QStandardItem(value(q1, "lastnameReferent").toString().toUpper()
                + " "
                + Utils::String::firstLetterToUpper(value(q1,"firstnameReferent").toString()));
    } else {
        itemCustomer =
                new QStandardItem(Utils::String::firstLetterToUpper(value(q1,"company").toString()));
    }
    itemCustomer->setIcon(QIcon(":icons/customer"));
    return itemCustomer;
}

QStandardItem *CustomerDatabase::getItemProject(QSqlQuery q2) {
    QStandardItem *itemProject = new QStandardItem(value(q2,"name").toString());
    itemProject->setIcon(QIcon(":icons/img/project"));
    return itemProject;
}

QStandardItem *CustomerDatabase::getItemBillQuote(QSqlQuery q3) {
    QStandardItem *itemBillQuote = new QStandardItem(value(q3,"date").toString() + " " + value(q3,"title").toString());
    if (value(q3,"isBilling").toInt() == 0) {
        itemBillQuote->setIcon(QIcon(":icons/img/quote"));
    } else if (value(q3,"isBilling").toInt() == 1) {
        itemBillQuote->setIcon(QIcon(":icons/img/bill"));
    }

    return itemBillQuote;
}

QSharedPointer<Models::Customer> CustomerDatabase::getCustomer(QSqlQuery &q)
{
    QSharedPointer<Models::Customer> customer =
            QSharedPointer<Models::Customer>(new Models::Customer());
    customer->setId(value(q, "idCustomer").toInt());
    customer->setFirstnameReferent(value(q,"firstnameReferent").toString());
    customer->setLastnameReferent(value(q,"lastnameReferent").toString());
    customer->setCompany(value(q,"company").toString());
    customer->setAddress(value(q,"address").toString());
    customer->setPostalCode(value(q,"postalCode").toString());
    customer->setCity(value(q,"city").toString());
    customer->setCountry(value(q,"country").toString());
    customer->setEmail(value(q,"email").toString());
    customer->setMobilePhone(value(q,"mobilePhone").toString());
    customer->setPhone(value(q,"phone").toString());
    customer->setFax(value(q,"fax").toString());

    return customer;
}

QSharedPointer<Models::Customer> CustomerDatabase::getCustomer(const int pId) {
    QSqlQuery q;
    QSharedPointer<Models::Customer> customer;

    q.prepare("SELECT * FROM Customer WHERE idCustomer = :pId");
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


int CustomerDatabase::addCustomer(const Models::Customer& pCustomer) {
    QSqlQuery q;

    q.prepare(
                "INSERT INTO Customer "
                "(firstnameReferent, lastnameReferent, company, address, "
                "postalCode, city, country, email, mobilePhone, phone, fax)"
                " VALUES "
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

void CustomerDatabase::updateCustomer(const Models::Customer &pCustomer) {
    QSqlQuery q;
    q.prepare(
                "UPDATE Customer SET "
                "firstnameReferent=:firstname, lastnameReferent=:lastname,"
                "company=:company, address=:address, postalCode=:postalCode, city=:city,"
                "country=:country, email=:email, mobilePhone=:mobilePhone, phone=:phone,"
                "fax=:fax "
                "WHERE idCustomer=:idCustomer");

    q.bindValue(":idCustomer", pCustomer.getId());

    q.bindValue(":firstname", pCustomer.getFirstnameReferent());
    q.bindValue(":lastname", pCustomer.getLastnameReferent());
    q.bindValue(":company", pCustomer.getCompany());
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
