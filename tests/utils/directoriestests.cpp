#include "directoriestests.h"

DirectoriesTests::DirectoriesTests()
{

}

DirectoriesTests::~DirectoriesTests()
{

}

void DirectoriesTests::validDirectoriesTest()
{
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
