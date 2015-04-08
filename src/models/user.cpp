#include "models/user.h"
#include "database/userdatabase.h"
#include "utils/hierarchicalsystem.h"

using namespace Databases;

namespace Models {
User::User() : People()
{
}

User::User(int id) : People(id)
{
    hydrat(id);
}

void User::commit() {
    if(!_toRemoved) {
        UserDatabase::instance()->updateUser(*this);
    } else {
        remove();
    }
}

void User::remove()
{
    // Not use
}

QVariantHash User::getDataMap()
{
    QVariantHash data;

    data["firstName"]   = getFirstname();
    data["lastName"]    = getLastname();
    data["title"]       = getTitle();
    data["address"]     = getAddress();
    data["postalCode"]  = getPostalCode();
    data["city"]        = getCity();
    data["phone"]       = getPhone();
    data["mobilePhone"]       = getMobilePhone();
    data["fax"]       = getMobilePhone();
    data["email"]       = getEmail();
    if(!getWebsite().isEmpty()) {
        data["website"]     = getWebsite();
    }

    if(!getAddressComplement().isEmpty()) {
        data["complement"]     = getAddressComplement();
    }

    return data;
}

void User::updateFolders()
{
    Customer customer;
    QString path;
    QString folder;
    QDir directory;
    Utils::HierarchicalSystem hierarchy;

    hierarchy.updateData();

    path = getWorkspacePath();
    folder = getWorkspaceName();
    directory.setPath(path);

    path = Utils::Directories::makeDirectory(directory, path, folder);

    for (auto c = hierarchy.getCustomers().cbegin();
         c != hierarchy.getCustomers().cend();
         ++c ) {
        customer = c.value();
        folder = customer.getNameFolder();

        path = Utils::Directories::makeDirectory(directory, path, folder);

        path  = Utils::Directories::makeDirectory(directory, path, "Devis");
        path = customer.getPath();
        directory.setPath(path);

        path  = Utils::Directories::makeDirectory(directory, path, "Factures");
        path = customer.getPath();
        directory.setPath(path);

        path = getWorkspacePath() + "/" + getWorkspaceName();
        directory.setPath(path);
    }
}

void User::hydrat(int id)
{
    User* user = UserDatabase::instance()->getUser(id);
    bool toCommit = false;

    setId(id);
    setFirstname(           user->getFirstname());
    setLastname(            user->getLastname());
    setCompany(             user->getCompany());
    setTitle(               user->getTitle());
    setAddress(             user->getAddress());
    setPostalCode(          user->getPostalCode());
    setCity(                user->getCity());
    setEmail(               user->getEmail());
    setPhone(               user->getPhone());
    setMobilePhone(         user->getMobilePhone());
    setNoSiret(             user->getNoSiret());
    setWorkspaceName(       user->getWorkspaceName());
    setWorkspacePath(       user->getWorkspacePath());
    setPdflatexPath( user->getPdflatexPath());
    setWebsite(             user->getWebsite());
    setAddressComplement(   user->getAddressComplement());
    setNbDaysPerMonth(user->getNbDaysPerMonth());
    setNbDaysPerWeek(user->getNbDaysPerWeek());
    setNbHoursPerDay(user->getNbHoursPerDay());
    if (getWorkspaceName().isEmpty()) {
        setWorkspaceName("FactDev");
        toCommit =  true;
    }

    if (getWorkspacePath().isEmpty()) {
        setWorkspacePath(QDir::homePath() + "/" +
            QStandardPaths::displayName(QStandardPaths::DocumentsLocation));
        toCommit = true;
    }

    if(toCommit) {
        commit();
    }

    delete user;
}

QString User::getTitle() const
{
    return _title;
}

void User::setTitle(const QString &title)
{
    _title = title;
}

QString User::getNoSiret() const
{
    return _noSiret;
}

void User::setNoSiret(const QString &noSiret)
{
    _noSiret = noSiret;
}

QPixmap *User::getImage()
{
    if (_image == NULL || _image->isNull()) {
        _image = new QPixmap(
                    UserDatabase::instance()->getUserImage(getId()));
    }
    return _image;
}

void User::setImage(QPixmap *image)
{
    _image = image;
    UserDatabase::instance()->setUserImage(*this);
    commit();
}

QString User::getWorkspaceName() const
{
    return _workspaceName;
}

void User::setWorkspaceName(const QString &workspaceName)
{
    _workspaceName = workspaceName;
}

QString User::getWorkspacePath() const
{
    return _workspacePath;
}

void User::setWorkspacePath(const QString &workspacePath)
{
    _workspacePath = workspacePath;
}

bool User::operator ==(const User &u)
{
    bool b = People::operator == (u);
    return  People::operator == (u)
            && getNoSiret() == u.getNoSiret()
            && getTitle() == u.getTitle();
}

bool User::operator !=(const User &u)
{
    return People::operator !=(u)
            || getNoSiret() == u.getNoSiret()
            ||  getTitle() == u.getTitle();
}
QString User::getPdflatexPath() const
{
    return _pdflatexPath;
}

void User::setPdflatexPath(const QString &pdflatexPath)
{
    _pdflatexPath = pdflatexPath;
}

double User::getNbHoursPerDay() const
{
    return _nbHoursPerDay;
}

void User::setNbHoursPerDay(double value)
{
    _nbHoursPerDay = value;
}
double User::getNbDaysPerWeek() const
{
    return _nbDaysPerWeek;
}

void User::setNbDaysPerWeek(double value)
{
    _nbDaysPerWeek = value;
}

double User::getNbHoursPerWeek() const
{
    return _nbDaysPerWeek * _nbHoursPerDay;
}

double User::getNbHoursPerMonth() const
{
    return _nbDaysPerMonth * _nbHoursPerDay;
}
double User::getNbDaysPerMonth() const
{
    return _nbDaysPerMonth;
}

void User::setNbDaysPerMonth(double nbDaysPerMonth)
{
    _nbDaysPerMonth = nbDaysPerMonth;
}




}
