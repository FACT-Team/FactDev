#include "directoriestests.h"
#include "exceptions/fileexception.h"
#include <QException>

DirectoriesTests::DirectoriesTests()
{

}

DirectoriesTests::~DirectoriesTests()
{

}

void DirectoriesTests::validDirectoriesTest() {
    Models::User user(1);
    QString path;
    QString folder;
    QDir directory;
    path = user.getWorkspacePath();
    folder = user.getWorkspaceName();
    directory.setPath(path);
    path = Utils::Directories::makeDirectory(directory, path, folder);
    QVERIFY("/home/florent/Documents/FactDev" == path);
}

void DirectoriesTests::invalidDirectoriesTest() {
    Models::User user(1);
    QString path;
    QString path2;
    QString folder;
    QDir directory;
    path = user.getWorkspacePath();
    folder = "/./";
    directory.setPath(path);
    try {
        path2 = Utils::Directories::makeDirectory(directory, path, folder);
        if ( (path + "/" + folder) == path2) {
            throw new Exceptions::FileException(
                        "Impossible de créer le répertoire de travail",
                        "makeDirectory::" + path + "/" + folder,
                        directory.currentPath(),
                        1.1);
        }
        QFAIL("Exception not thrown");
    } catch (Exceptions::FileException*) {
        QVERIFY(true);
    } catch (const std::exception& e) {
        QVERIFY(true);
    }



}

