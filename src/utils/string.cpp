#include "string.h"

namespace Utils {
QString String::firstLetterToUpper(QString s)
{
    return s.replace(0, 1, s[0].toUpper());
}
}
