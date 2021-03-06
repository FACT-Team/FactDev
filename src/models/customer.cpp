#include "models/customer.h"

#include "database/customerdatabase.h"
#include "database/billingdatabase.h"
#include "models/user.h"
#include "models/billing.h"

using namespace Databases;

namespace Models {
Customer::Customer() : People()
{
}

Customer::Customer(int id) : People(id)
{
    hydrat(id);
}

void Customer::commit() {
    if(_id == 0) {
        _id = CustomerDatabase::instance()->addCustomer(*this);
    } else if(_toRemoved){
        remove();
    } else {
        CustomerDatabase::instance()->updateCustomer(*this);
    }
}

void Customer::hydrat(int id)
{
    QSharedPointer<Customer> customer =
            CustomerDatabase::instance()->getCustomer(id);

    setId(id);
    setFirstname(           customer->getFirstname());
    setLastname(            customer->getLastname());
    setCompany(             customer->getCompany());
    setAddress(             customer->getAddress());
    setPostalCode(          customer->getPostalCode());
    setCity(                customer->getCity());
    setCountry(             customer->getCountry());
    setEmail(               customer->getEmail());
    setPhone(               customer->getPhone());
    setMobilePhone(         customer->getMobilePhone());
    setFax(                 customer->getFax());
    setWebsite(             customer->getWebsite());
    setAddressComplement(   customer->getAddressComplement());
    setIsArchived(          customer->isArchived());
    setToRemoved(false);
}

void Customer::remove()
{
    CustomerDatabase::instance()->removeCustomer(_id);
}

QVariantHash Customer::getDataMap()
{
    QVariantHash data;
    data["firstname"]   = getFirstname();
    data["lastname"]    = getLastname();
    data["company"]     = getCompany();
    data["address"]     = getAddress();
    data["postalcode"]  = getPostalCode();
    data["city"]        = getCity();
    data["email"]       = getEmail();
    data["mobilephone"] = getMobilePhone();
    data["phone"]       = getPhone();
    data["fax"]         = getFax();

    if(!getWebsite().isEmpty()) {
        data["website"]     = getWebsite();
    }

    if(!getAddressComplement().isEmpty()) {
        data["complement"]     = getAddressComplement();
    }

    return data;
}

QString Customer::getPath() const
{
   User u(1);

   return   u.getWorkspacePath()
            + "/" + u.getWorkspaceName() + "/"
            + getNameFolder();
}

QString Customer::getNameFolder() const
{
    return  getCompany().toUpper()
            + " " + getLastname()
            + " " + getFirstname();
}

double Customer::getTurnover() const {
    double ret(0.0);
    QList<Project> projects =
            Databases::ProjectDatabase::instance()->getProjects(getId());

    for (Project project : projects) {
        ret += project.getCost();
    }
    return ret;
}

QPixmap * Customer::getImage()
{
    if (_image == NULL || _image->isNull()) {
        _image = new QPixmap(
                    CustomerDatabase::instance()->getCustomerImage(getId()));
    }
    return _image;
}

void Customer::setImage(QPixmap *image)
{
    _image = image;
    CustomerDatabase::instance()->setCustomerImage(*this);
    commit();
}

bool Customer::isArchived() const
{
    return _isArchived;
}

void Customer::setIsArchived(const bool isArchived)
{
    _isArchived = isArchived;
}

}
