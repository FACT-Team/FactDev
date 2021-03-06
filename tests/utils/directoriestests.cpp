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

    try {
        path = Utils::Directories::makeDirectory(directory, path, folder);
        QVERIFY(QDir(QDir::homePath()+"/Documents/FactDev").absolutePath() == QDir(path).absolutePath());
    } catch (Exceptions::FileException*) {
        QVERIFY(true);
    }
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
    }
}

