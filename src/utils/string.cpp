#include "string.h"
#include <QDebug>
namespace Utils {
QString String::firstLetterToUpper(QString s)
{
    return s.replace(0, 1, s[0].toUpper());
}

QString String::getExtensionFile(QString fileName)
{
    QStringList list = fileName.split(".");
    return list.at(list.size()-1);
}
}
