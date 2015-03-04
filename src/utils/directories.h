#ifndef DIRECTORIES_H
#define DIRECTORIES_H
#include <QString>
#include <QDir>

#include "exceptions/fileexception.h"
namespace Utils {
class Directories
{
public:

    /**
     * @brief MainWindow::makeDirectory If not exists make a new directory
     * <i>folder</i>
     * @param path Return the path of the folder just created
     * @param folder Folder name to create
     * @return Path of the folder just created
     */
    static QString makeDirectory(QDir &directory,
                          const QString path, const QString folder) throw(Exceptions::FileException*);
};
}
#endif // DIRECTORIES_H
