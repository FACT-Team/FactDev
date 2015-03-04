#include "directories.h"

namespace Utils {

QString Directories::makeDirectory(QDir &directory, const QString path, const QString folder) throw(Exceptions::FileException*)
{
    if (!directory.cd(path + "/" + folder)) {
        if (!directory.mkdir(folder)) {
            throw new Exceptions::FileException(
                        "Impossible de créer le répertoire de travail",
                        "makeDirectory::" + path + "/" + folder,
                        directory.currentPath(),
                        1.1);
        }

    }
    directory.setPath(path + "/" + folder);
    return path + "/" + folder;
}

}
