#ifndef POINTERS_H
#define POINTERS_H

#include <QObject>

namespace Utils {
class pointers
{
public:
    static void deleteIfNotNull(QObject* p);
};
}
#endif // POINTERS_H
