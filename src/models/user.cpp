#include "models/user.h"
#include "database/userdatabase.h"
#include "utils/hierarchicalsystem.h"

using namespace Databases;

namespace Models {
User::User() : People()
{

}

User::User(int id) : People()
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
    data["email"]       = getEmail();

    return data;
}

void User::updateFolders()
{
    Customer customer;
    Project p1;
    Project p2;
    QString path;
    QString folder;
    QDir directory;
    Utils::HierarchicalSystem hierarchy;

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

        for (auto p = hierarchy.getProjects().cbegin();
             p != hierarchy.getProjects().cend();
             ++p ) {
            p1 = *p.value();
            p2 = *c.key();

            if (p1 == p2) {
                if ((*p.key()).isBilling()) {
                    folder = "Factures";
                } else {
                    folder = "Devis";
                }
                path  = Utils::Directories::makeDirectory(directory, path, folder);
            }

            path = customer.getPath();
            directory.setPath(path);
        }
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
}
