#include "pointers.h"

namespace Utils {

void pointers::deleteIfNotNull(QObject *p)
{
    if (p != NULL) {
        delete p;
    }

}

}
